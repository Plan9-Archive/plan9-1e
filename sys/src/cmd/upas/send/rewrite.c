#include "common.h"
#include "send.h"

extern int debug;

/* configuration */
#define RULEBiobuf "lib/rewrite"

/* 
 *	Routines for dealing with the rewrite rules.
 */

/* globals */
typedef struct rule rule;

#define NSUBEXP 10
struct rule {
	String *matchre;	/* address match */
	String *repl1;		/* first replacement String */
	String *repl2;		/* second replacement String */
	d_status type;		/* type of rule */
	Reprog *program;
	Resub subexp[NSUBEXP];
	rule *next;
};
static rule *rulep;

/* predeclared */
static String *substitute(String *, Resub *, char *);
static rule *findrule(String *, int);


/*
 *  Get the next token from `line'.  The symbol `\l' is replaced by
 *  the name of the local system.
 */
extern String *
rule_parse(String *line)
{
	String *token;
	String *expanded;
	char *cp;

	token = s_parse(line, 0);
	if(token == 0)
		return(token);
	if (strchr(s_to_c(token), '\\')==0)
		return(token);
	expanded = s_new();
	for(cp = s_to_c(token); *cp; cp++) {
		if(*cp == '\\') switch(*++cp) {
		case 'l':
			s_append(expanded, thissys);
			break;
		case '\\':
			s_putc(expanded, '\\');
			break;
		default:
			s_putc(expanded, '\\');
			s_putc(expanded, *cp);
			break;
		} else
			s_putc(expanded, *cp);
	}
	s_free(token);
	s_terminate(expanded);
	return(expanded);
}

/*
 *  rules are of the form:
 *	<reg exp> <String> <repl exp> [<repl exp>]
 */
extern int
getrules(void)
{
	Biobuf	*rfp;
	rule	*rp, *rlastp=0;
	String	*line;
	String	*type;
	String	*file;
	String	*re;

	file = abspath(RULEBiobuf, MAILROOT, (String *)0);
	rfp = sysopen(s_to_c(file), "r", 0);
	if (rfp == 0) {
		rulep = 0;
		return -1;
	}
	line = s_new();
	type = s_new();
	while(s_getline(rfp, s_restart(line))){
		/* get a rule */
		rp = (rule *)malloc(sizeof(rule));
		if (rp == 0) {
			perror("getrules:");
			exit(1);
		}
		rp->next = 0;
		re = rule_parse(s_restart(line));
		s_tolower(re);
		rp->matchre = s_new();
		if(*s_to_c(re)!='^')
			s_append(rp->matchre, "^");
		s_append(rp->matchre, s_to_c(re));
		s_append(rp->matchre, "$");
		USE(s_restart(rp->matchre));
		s_free(re);
		s_parse(line, s_restart(type));
		rp->repl1 = rule_parse(line);
		rp->repl2 = rule_parse(line);
		rp->program = 0;
		if (strcmp(s_to_c(type), "|") == 0)
			rp->type = d_pipe;
		else if (strcmp(s_to_c(type), ">>") == 0)
			rp->type = d_cat;
		else if (strcmp(s_to_c(type), "alias") == 0)
			rp->type = d_alias;
		else if (strcmp(s_to_c(type), "translate") == 0)
			rp->type = d_translate;
		else if (strcmp(s_to_c(type), "auth") == 0)
			rp->type = d_auth;
		else {
			s_free(rp->matchre);
			s_free(rp->repl1);
			s_free(rp->repl2);
			free((char *)rp);
			fprint(2,"illegal rewrite rule: %s\n", s_to_c(line));
			continue;
		}
		if (rulep == 0)
			rulep = rlastp = rp;
		else
			rlastp = rlastp->next = rp;
	}
	s_free(type);
	s_free(line);
	s_free(file);
	sysclose(rfp);
	return 0;
}

/* look up a matching rule */
static rule *
findrule(String *addrp, int authorized)
{
	rule *rp;
	static rule defaultrule;

	if (rulep == 0)
		return &defaultrule;
	for (rp = rulep; rp != 0; rp = rp->next) {
		if (rp->type==d_auth && authorized)
			continue;
		if (rp->program == 0)
			rp->program = regcomp(rp->matchre->base);
		if (rp->program == 0)
			continue;
		memset(rp->subexp, 0, sizeof(rp->subexp));
		if(debug)
			print("trying %s\n", rp->matchre->base);
		if (regexec(rp->program, s_to_c(addrp), rp->subexp, NSUBEXP))
			return rp;
	}
	return 0;
}

/*  Transforms the address into a command.
 *  Returns:	-1 if address not matched by reules
 *		 0 if address matched and ok to forward
 *		 1 if address matched and not ok to forward
 */
extern int
rewrite(dest *dp, char *s)
{
	rule *rp;		/* rewriting rule */
	String *lower;		/* lower case version of destination */

	/*
	 *  Rewrite the address.  Matching is case insensitive.
	 */
	lower = s_clone(s_restart(dp->addr));
	s_tolower(s_restart(lower));
	rp = findrule(lower, dp->authorized);
	if (rp == 0)
		return -1;
	strcpy(s_to_c(lower), s_to_c(dp->addr));
	dp->repl1 = substitute(rp->repl1, rp->subexp, s);
	dp->repl2 = substitute(rp->repl2, rp->subexp, s);
	dp->status = rp->type;
	if(debug){
		print("\t->");
		if(dp->repl1)
			print("%s", s_to_c(dp->repl1));
		if(dp->repl2)
			print("%s", s_to_c(dp->repl2));
		print("\n");
	}
	return 0;
}

static String *
substitute(String *source, Resub *subexp, char *s)
{
	register char *sp;
	register char *ssp;
	register String *stp;
	register int i;
	
	if (source == 0)
		return 0;
	sp = s_to_c(source);

	/* someplace to put it */
	stp = s_new();

	/* do the substitution */
	while (*sp != '\0') {
		if (*sp == '\\') {
			switch (*++sp) {
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				i = *sp-'0';
				if (subexp[i].sp != 0)
					for (ssp = subexp[i].sp;
					     ssp < subexp[i].ep;
					     ssp++)
						s_putc(stp, *ssp);
				break;
			case '\\':
				s_putc(stp, '\\');
				break;
			case '\0':
				sp--;
				break;
			case 's':
				for(ssp = s; *ssp; ssp++)
					s_putc(stp, *ssp);
				break;
			default:
				s_putc(stp, *sp);
				break;
			}
		} else if (*sp == '&') {				
			if (subexp[0].sp != 0)
				for (ssp = subexp[0].sp;
				     ssp < subexp[0].ep; ssp++)
					s_putc(stp, *ssp);
		} else
			s_putc(stp, *sp);
		sp++;
	}
	s_terminate(stp);

	return s_restart(stp);
}

extern void
regerror(char* s)
{
	fprint(2, "rewrite: %s\n", s);
}

extern void
dumprules(void)
{
	rule *rp;

	for (rp = rulep; rp != 0; rp = rp->next) {
		fprint(2, "'%s'", rp->matchre->base);
		switch (rp->type) {
		case d_pipe:
			fprint(2, " |");
			break;
		case d_cat:
			fprint(2, " >>");
			break;
		case d_alias:
			fprint(2, " alias");
			break;
		case d_translate:
			fprint(2, " translate");
			break;
		default:
			fprint(2, " UNKNOWN");
			break;
		}
		fprint(2, " '%s'", rp->repl1 ? rp->repl1->base:"...");
		fprint(2, " '%s'\n", rp->repl2 ? rp->repl2->base:"...");
	}
}

