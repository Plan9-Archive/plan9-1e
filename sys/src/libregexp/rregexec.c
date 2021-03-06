#include <u.h>
#include <libc.h>
#include "regexp.h"
#include "regcomp.h"

static Resublist sempty;		/* empty set of matches */

/*
 *  return	0 if no match
 *		>0 if a match
 *		<0 if we ran out of _relist space
 */
static int
rregexec1(Reprog *progp,	/* program to run */
	Rune *bol,		/* string to run machine on */
	Resub *mp,		/* subexpression elements */
	int ms,			/* number of elements at mp */
	Rune *starts,
	Rune *eol,
	Rune startchar)
{
	int flag=0;
	Reinst *inst;
	Relist *tlp;
	Rune *s;
	int i, checkstart;
	Rune r, *rp, *ep;
	Relist* tl;		/* This list, next list */
	Relist* nl;
	Relist* tle;		/* ends of this and next list */
	Relist* nle;
	int match;

	match = 0;
	checkstart = startchar;
	sempty.m[0].rsp = 0;
	if(mp!=0)
		for(i=0; i<ms; i++)
			mp[i].rsp = mp[i].rep = 0;
	_relist[0][0].inst = _relist[1][0].inst = 0;

	/* Execute machine once for each character, including terminal NUL */
	s = starts;
	do{
		r = *s;

		/* fast check for first char */
		if(checkstart && r!=startchar){
			s++;
			continue;
		}

		/* switch run lists */
		tl = _relist[flag];
		tle = _reliste[flag];
		nl = _relist[flag^=1];
		nle = _reliste[flag];
		nl->inst = 0;

		/* Add first instruction to current list */
		sempty.m[0].rsp = s;
		_renewthread(tl, progp->startinst, &sempty);

		/* Execute machine until current list is empty */
		for(tlp=tl; tlp->inst; tlp++){	/* assignment = */
			if(s == eol)
				break;

			for(inst=tlp->inst; ; inst = inst->next){
				switch(inst->type){
				case RUNE:	/* regular character */
					if(inst->r == r)
						if(_renewthread(nl, inst->next, &tlp->se)==nle)
							return -1;
					break;
				case LBRA:
					tlp->se.m[inst->subid].rsp = s;
					continue;
				case RBRA:
					tlp->se.m[inst->subid].rep = s;
					continue;
				case ANY:
					if(r != '\n')
						if(_renewthread(nl, inst->next, &tlp->se)==nle)
							return -1;
					break;
				case ANYNL:
					if(_renewthread(nl, inst->next, &tlp->se)==nle)
							return -1;
					break;
				case BOL:
					if(s == bol || *(s-1) == '\n')
						continue;
					break;
				case EOL:
					if(r == 0 || r == '\n')
						continue;
					break;
				case CCLASS:
					ep = inst->cp->end;
					for(rp = inst->cp->spans; rp < ep; rp += 2)
						if(r >= rp[0] && r <= rp[1]){
							if(_renewthread(nl, inst->next, &tlp->se)==nle)
								return -1;
							break;
						}
					break;
				case NCCLASS:
					ep = inst->cp->end;
					for(rp = inst->cp->spans; rp < ep; rp += 2)
						if(r >= rp[0] && r <= rp[1])
							break;
					if(rp == ep)
						if(_renewthread(nl, inst->next, &tlp->se)==nle)
							return -1;
					break;
				case OR:
					/* evaluate right choice later */
					if(_renewthread(tlp, inst->right, &tlp->se) == tle)
						return -1;
					/* efficiency: advance and re-evaluate */
					continue;
				case END:	/* Match! */
					match = 1;
					tlp->se.m[0].rep = s;
					if(mp != 0)
						_renewmatch(mp, ms, &tlp->se);
					break;
				}
				break;
			}
		}
		checkstart = startchar && nl->inst==0;
		s++;
	}while(r);
	return match;
}

extern int
rregexec(Reprog *progp,	/* program to run */
	Rune *bol,	/* string to run machine on */
	Resub *mp,	/* subexpression elements */
	int ms)		/* number of elements at mp */
{
	Rune *starts;	/* where to start match */
	Rune *eol;	/* where to end match */
	Rune startchar;
	int rv;

	/*
 	 *  use user-specified starting/ending location if specified
	 */
	starts = bol;
	eol = 0;
	if(mp && ms>0){
		if(mp->rsp)
			starts = mp->rsp;
		if(mp->rep)
			eol = mp->rep;
	}
	startchar = progp->startinst->type == RUNE ? progp->startinst->r : 0;

	/* keep trying till we have enough list space to terminate */
	for(;;){
		if(_relist[0] == 0){
			_relist[0] = malloc(2*_relistsize*sizeof(Relist));
			_relist[1] = _relist[0] + _relistsize;
			_reliste[0] = _relist[0] + _relistsize - 1;
			_reliste[1] = _relist[1] + _relistsize - 1;
			if(_relist[0] == 0)
				regerror("_relist overflow");
		}
		rv = rregexec1(progp, bol, mp, ms, starts, eol, startchar);
		if(rv >= 0)
			return rv;
		free(_relist[0]);
		_relist[0] = 0;
		_relistsize += LISTINCREMENT;
	}
	return -1;
}
