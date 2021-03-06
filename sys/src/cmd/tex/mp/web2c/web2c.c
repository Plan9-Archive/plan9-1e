/*
 * This program converts (mostly) the pseudo-Pascal generated by Tangle to C.
 * The output depends on many C macros and some postprocessing by other
 * programs.
 *
 * Arguments:
 *	-f:	force strict interpretation of semantics of for stmt
 *		(never used with TeX and friends)
 *	-t:	special optimizations for tex.p->tex.c
 *	-m:	special optimizations for mf.p->mf.c
 *	-c:	supply the base part of the name of the coerce.h file
 *	-h:	supply the name of the standard header file
 *	-a:	generate ANSI-style function prototypes
 *	-d:	generate some additional debugging output
 *
 * The majority of this program (which includes ptoc.yacc and ptoc.lex)
 * was written by Tomas Rokicki, with modifications by Tim Morgan.
 */

#include <stdio.h>
#include "web2cy.h"
#include "web2c.h"


#define max_line_length (78)
#define max_strings (20000)
#define hash_prime (101)
#define sym_table_size (3000)
#define unused (271828)
#define ex_32 (2)
#define ex_real (3)
#define max(a,b) ((a>b)?a:b)

boolean debug=FALSE;
int indent = 0;
int line_pos = 0;
int last_brace = 0;
int block_level = 0;
int ii;
int last_tok;
int tex = 0, strict_for = 0, mf = 0;

char safe_string[80];
char var_list[200];
char field_list[200];
char last_id[80];
char z_id[80];
char next_temp[] = "zzzaa";
char coerce_name[100] = "coerce.h";

long last_i_num;
int ii, l_s;
long lower_bound, upper_bound;
extern FILE *fopen();
FILE *std;
FILE *coerce;
int pf_count = 1;
#ifdef	ANSI
boolean ansi=TRUE;
#else
boolean ansi=FALSE;
#endif
char *std_header="tex.h";	/* Default include filename */

char strings[max_strings];
int hash_list[hash_prime];
short global = 1;
#ifdef	MS_DOS
struct sym_entry huge sym_table[sym_table_size];
#else
struct sym_entry sym_table[sym_table_size];
#endif
int next_sym_free = -1, next_string_free = 0;
int mark_sym_free, mark_string_free;

extern int yyleng;
#ifdef	FLEX
extern char *yytext;
#else	/* LEX */
extern char yytext[];
#endif	/* LEX */

void find_next_temp()
{
    next_temp[4]++;
    if (next_temp[4] > 'z') {
	next_temp[4] = 'a';
	next_temp[3]++;
    }
}

void normal()
{
    std = stdout;
}

void new_line()
{
    if (!std)
	return;
    if (line_pos > 0) {
	(void) putc('\n', std);
	line_pos = 0;
    }
}

void indent_line()
{
    new_line();
}

void my_output(s) char *s;
{
    int len = strlen(s);
    int less_indent = 0;

    if (!std)
	return;
    if (line_pos + len > max_line_length)
	indent_line();
    if (indent > 1 && (strcmp(s, "case") == 0 || strcmp(s, "default") == 0))
	less_indent = 2;
    while (line_pos < indent*2 - less_indent) {
	fputs("  ", std);
	line_pos += 2;
    }
    (void) fprintf(std, "%s ", s);
    line_pos += len + 1;
    last_brace = (s[0] == '}');
}

void semicolon()
{
    if (!last_brace) {
	my_output(";");
	indent_line();
	last_brace = 1;
    }
}


/* Since a syntax error can never be recovered from, we exit here with
   bad status.  */

void yyerror(s) char *s;
{
    (void) fflush(stdout);
    (void) fprintf(stderr, " %s\n", s);
    (void) fprintf(stderr, "Last token = %d, ", last_tok);
    (void) fprintf(stderr, "error buffer = `%s',\n\t", yytext);
    (void) fprintf(stderr, "last id = `%s' (", last_id);
    ii = search_table(last_id);
    if (ii == -1)
	(void) fprintf(stderr, "not in symbol table");
    else
	switch (sym_table[ii].typ) {
	case undef_id_tok:
	    (void) fprintf(stderr, "undefined");
	    break;
	case var_id_tok:
	    (void) fprintf(stderr, "variable");
	    break;
	case const_id_tok:
	    (void) fprintf(stderr, "constant");
	    break;
	case type_id_tok:
	    (void) fprintf(stderr, "type");
	    break;
	case proc_id_tok:
	    (void) fprintf(stderr, "parameterless procedure");
	    break;
	case proc_param_tok:
	    (void) fprintf(stderr, "procedure with parameters");
	    break;
	case fun_id_tok:
	    (void) fprintf(stderr, "parameterless function");
	    break;
	case fun_param_tok:
	    (void) fprintf(stderr, "function with parameters");
	    break;
	default:
	    (void) fprintf(stderr, "unknown!");
	    break;
	}
    fprintf(stderr, ").\n");
    exit(1);
    if (debug) {
	(void) fprintf(stderr, "Next sym free    =  %d\n", next_sym_free);
	(void) fprintf(stderr, "Mark sym         =  %d\n", mark_sym_free);
	(void) fprintf(stderr, "Next string free =  %d\n", next_string_free);
	(void) fprintf(stderr, "Mark string      =  %d\n", mark_string_free);
    }
}

int hash(id) char *id;
{
    register int i = 0, j;
    for (j = 0; id[j] != 0; j++)
	i = (i + i + id[j]) % hash_prime;
    return (i);
}

int search_table(id) char *id;
{
    int ptr;
    ptr = hash_list[hash(id)];
    while (ptr != -1) {
	if (strcmp(id, sym_table[ptr].id) == 0)
	    return (ptr);
	else
	    ptr = sym_table[ptr].next;
    }
    return (-1);
}

int add_to_table(id) char *id;
{
    int h, ptr;
    h = hash(id);
    ptr = hash_list[h];
    hash_list[h] = (++next_sym_free);
    sym_table[next_sym_free].next = ptr;
    sym_table[next_sym_free].val = unused;
    sym_table[next_sym_free].id = strings + next_string_free;
    sym_table[next_sym_free].var_formal = FALSE;
    sym_table[next_sym_free].var_not_needed = FALSE;
    (void) strcpy(strings + next_string_free, id);
    next_string_free += strlen(id) + 1;
    return (next_sym_free);
}

void remove_locals()
{
    int h, ptr;
    for (h = 0; h < hash_prime; h++) {
	next_sym_free = mark_sym_free;
	next_string_free = mark_string_free;
	ptr = hash_list[h];
	while (ptr > next_sym_free)
	    ptr = sym_table[ptr].next;
	hash_list[h] = ptr;
    }
    global = 1;
}

void mark()
{
    mark_sym_free = next_sym_free;
    mark_string_free = next_string_free;
    global = 0;
}

void initialize()
{
    register int i;

    for (i = 0; i < hash_prime; hash_list[i++] = -1);
    normal();
    coerce = fopen(coerce_name, "w");
}

#ifdef	ANSI
void
#endif
main(argc, argv)
char *argv[];
{
    int error, i;

    for (i=1; i < argc; i++) if (argv[i][0] == '-') switch (argv[i][1]) {
    case 't':
	tex = TRUE;
	break;
    case 'm':
	mf = TRUE;
	break;
    case 'f':
	strict_for = TRUE;
	break;
    case 'h':
	std_header = &argv[i][2];
	break;
    case 'd':
	debug = TRUE;
	break;
    case 'a':
	ansi = (argv[i][2] == '0')? FALSE : TRUE;
	break;
    case 'c':
	(void) sprintf(coerce_name, "%s.h", &argv[i][2]);
	break;
    default:
	fprintf(stderr, "Unknown option %s, ignored\n", argv[i]);
	break;
    }
    else {
	fprintf(stderr, "Unknown option %s, ignored\n", argv[i]);
    }
    initialize();
    error = yyparse();
    new_line();
    (void) fprintf(stderr, "%d symbols.\n", next_sym_free);
    exit(error);
}
