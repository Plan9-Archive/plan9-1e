
# line 1 "act.mt"

#include <u.h>
#include <libc.h>
#include <stdio.h>
#include "dat.h"

typedef struct Cost {
	int gate;
	int pin;
} Cost;
Cost gatecost = {1,0};
Cost pincost = {0,1};
Cost zerocost = {0,0};
Cost infinity = {1000000,0};
Cost bigcost = {1000,0};

#define COST		Cost
#define INFINITY	infinity
#define ZEROCOST	gatecost	/* default cost of a rule */
#define ADDCOST(x,y)	(x.gate += y.gate, x.pin += y.pin)
#define COSTLESS(x,y)	((x.gate)<(y.gate) || (x.gate==y.gate && x.pin<y.pin))
# line 1 "/sys/lib/twig/walker.stdio"
/*
 * The machine is laid out as a sequence of integers in the walker.
 * The form described above is only used inside the preprocessor.
 * Each machine state is one of the following sequence:
 *
 * TABLE <value_1><index_1>...<value_n><index_n> -1 [FAIL <fail_index>] -1
 * or
 * TABLE2 <value_1><index_1>...<value_n><index_n> -1 [FAIL <fail_index>] -1
 * or
 * ACCEPT <accept table index> -1
 *
 * The accept table is in the form:
 *
 * <tree index_1> ...<tree_index_m> -1
 *
 */

#define FASTLIM	0
#define TABLE	1
#define FAIL	2
#define ACCEPT	3
#define TABLE2	4
#define EOT	-1

/* special machine state */
#define HANG	-1

/* used by the evaluator to interpret path table */
#define	eSTOP	0
#define	ePOP	-1
#define eEVAL	-2
#define eNEXT	-3
#define ePUSH	-4

/* Tags that indicate the type of a value */
#define M_BRANCH 010000
#define M_NODE	0
#define M_LABEL 01000
#define MAX_NODE_VALUE 00777
#define MTAG_SHIFT 9
#define M_DETAG(x)	((x)&~(M_BRANCH|M_LABEL|M_NODE))

/* predicates to tell whether a value x is of type NODE, BRANCH, or LABEL */
#define MI_NODE(x)	(((x)&(M_BRANCH|M_LABEL))==0)
#define MI_DEFINED(x)	((x)!=-1)
#define MI_LABEL(x)	(((x)&M_LABEL)!=0)
#define MI_BRANCH(x)	(((x)&M_BRANCH)!=0)

/* build a tagged value */
#define MV_NODE(x)	(x)
#define MV_BRANCH(x)	((x)|M_BRANCH)
#define MV_LABEL(x)	((x)|M_LABEL)

#include "symbols.h"

/* limits */
/*
 * The depth of a pattern must be 7 or less.  Otherwise the type of he
 * partial mask in skeleton must be changed
 */
#define MAXDEPTH	7

/* modes */
#define xTOPDOWN	3
#define xABORT		2
#define xREWRITE	1
#define xDEFER		0

/* macros */
#define tDO(m)	_do((m)->skel, (m), 1)
#define REWRITE	return(_m->cost = cost, xREWRITE)
#define TOPDOWN return(_m->cost = cost, xTOPDOWN)
#define ABORT return(xABORT)

/*
 * REORDER macro allows a knowledgeable user to change the order
 * of evaluation of the leaves.
 */
#ifndef REORDER
#define REORDER(list)	_evalleaves(list)
#endif
#define EVAL	REORDER(_ll)

#define mpush(s,m)	(m)->next = s, s = m

/* skeleton structure */
typedef struct skeleton		skeleton;
typedef struct __match		__match;
typedef struct __partial	__partial;
typedef int			labelset;	/* a bit vector of labels */

struct __partial {
	unsigned char	treeno;
	char		bits;
};

struct skeleton {
	skeleton	*sibling;
	skeleton	*leftchild;		/* leftmost child */
	skeleton	*rightchild;		/* rightmost child */
	NODEPTR		root;
	NODEPTR		parent;			/* our parent */
	int		nson;
	int		treecnt;
	__match		*succ[MAXLABELS];
	__partial	*partial;
	__match		*winner;
	COST		mincost;
};

struct __match {
	__match		**lleaves;	/* labelled leaves */
	skeleton	*skel;		/* back pointer to skeleton node */
	COST		cost;
	short		tree;
	short		mode;
};

/* ZEROCOST, and ADDCOST allows easy implementation of the common
 * operation of just equating the cost of a match to be the sum
 * of the costs of the labelled leaves.
 */
#ifdef ADDCOST
#define DEFAULT_COST sumleaves(_ll)
COST sumleaves(__match **list)
{
	COST cost;
	cost = ZEROCOST;
	for(; *list; list++)
		ADDCOST((cost),(*list)->cost);
	return cost;
}
#endif
/*
 * See Aho, Corasick Comm ACM 18:6, and Hoffman and O'Donell JACM 29:1
 * for detail of the matching algorithm
 */

#ifndef va_start
#include <ape/stdarg.h>
#endif
/* from libc.h */
extern	void*	malloc(long);
extern	void	free(void*);
extern	void	abort(void);
#define _twig_assert(a,str) \
	do{if(!(a)){\
		fprintf(stderr, "twig internal error %s\n", (str));\
		abort();\
	}}while(0)

/* these are user defined, so can be macros */
#ifndef mtValue
int		mtValue(NODEPTR);
#endif
#ifndef mtSetNodes
void		mtSetNodes(NODEPTR, int, NODEPTR);
#endif
#ifndef mtGetNodes
NODEPTR		mtGetNodes(NODEPTR, int);
#endif

/* made by twig proper */
NODEPTR		mtAction(int, __match **, skeleton *);
short		mtEvalCost(__match *, __match **, skeleton *);

/* stuff defined here */
void		_addmatches(int, skeleton *, __match *);
void		_closure(int, int, skeleton *);
void		_do(skeleton *, __match *, int);
void		_evalleaves(__match **);
__match		**_getleaves(__match *, skeleton *);
int		_machstep(short, short);
void		_match(void);
void		_matchinit(void);
void		_merge(skeleton *, skeleton *);
NODEPTR		_mtG(NODEPTR, ...);
skeleton	*_walk(skeleton *, int);
__match		*_allocmatch(void);
skeleton	*_allocskel(void);
__partial	*_allocpartial(void);
void		_freematch(__match *);
void		_freeskel(skeleton *);
void		_freepartial(__partial *);
void		_prskel(skeleton *, int);

int mtDebug = 0;
int treedebug = 0;
extern short mtStart;
extern short mtTable[], mtAccept[], mtMap[], mtPaths[], mtPathStart[];
#ifdef LINE_XREF
	extern short mtLine[];
#endif

#ifndef MPBLOCKSIZ
#define MPBLOCKSIZ 10000
#endif
__match *_mpblock[MPBLOCKSIZ], **_mpbtop;

/*
 * See sym.h in the preprocessor for details
 * Basically used to support eh $%n$ construct.
 */
__match **
_getleaves(register __match *mp, register skeleton *skp)
{
	skeleton *stack[MAXDEPTH];
	skeleton **stp = stack;
	register short *sip = &mtPaths[mtPathStart[mp->tree]];
	register __match **mmp = _mpbtop;

	__match **mmp2 = mmp;
	_mpbtop += *sip++ + 1;
	_twig_assert(_mpbtop <= &_mpblock[MPBLOCKSIZ], "match block overflow");

	for(;;)
		switch(*sip++){
		case ePUSH:
			*stp++ = skp;
			skp = skp->leftchild;
			break;
		case eNEXT:
			skp = skp->sibling;
			break;
		case eEVAL:
			mp = skp->succ[M_DETAG(*sip++)];
			_twig_assert(mp != 0, "bad eEVAL");
			*mmp++ = mp;
			break;
		case ePOP:
			skp = *--stp;
			break;
		case eSTOP:
			*mmp = 0;
			return mmp2;
		}
}

void
_do(skeleton *sp, register __match *winner, int evalall)
{
	register skeleton *skel;

	if(winner == 0) {
		_prskel(sp, 0);
		fprintf(stderr, "no winner");
		return;
	}

	skel = winner->skel;
	if(winner->mode == xDEFER || evalall && winner->mode != xTOPDOWN)
		REORDER(winner->lleaves);
	skel->root = mtAction(winner->tree, winner->lleaves, sp);
	mtSetNodes(skel->parent, skel->nson, skel->root);
}

void
_evalleaves(register __match **mpp)
{
	register __match *mp;
	while(*mpp){
		mp = *mpp++;
		_do(mp->skel, mp, 1);
	}
}

skeleton *
_walk(register skeleton *sp, int ostate)
{
	int state, nstate, nson;
	register __partial *pp;
	register __match *mp;
	register skeleton *nsp, *lastchild = 0;
	NODEPTR son, root;

	root = sp->root;
	nson = 1;
	sp->mincost = INFINITY;
	state = _machstep(ostate, mtValue(root));

	while(son = mtGetNodes(root, nson)){
		nstate = _machstep(state, MV_BRANCH(nson));
		nsp = _allocskel();
		nsp->root = son;
		nsp->parent = root;
		nsp->nson = nson;
		_walk(nsp, nstate);
		if(COSTLESS(nsp->mincost, INFINITY)){
			_twig_assert(nsp->winner->mode == xREWRITE, "bad mode");
			if(mtDebug || treedebug) {
				fprintf(stderr, "rewrite\n");
				_prskel(nsp, 0);
			}
			_do(nsp, nsp->winner, 0);
			_freeskel(nsp);
			continue;
		}
		_merge(sp, nsp);
		if(lastchild == 0)
			sp->leftchild = nsp;
		else
			lastchild->sibling = nsp;
		lastchild = nsp;
		nson++;
	}

	for(pp = sp->partial; pp < &sp->partial[sp->treecnt]; pp++)
		if(pp->bits & 01){
			mp = _allocmatch();
			mp->tree = pp->treeno;
			_addmatches(ostate, sp, mp);
		}
	if(son == 0 && nson == 1)
		_closure(state, ostate, sp);

	sp->rightchild = lastchild;
	if(root == 0){
		COST c;
		__match *win;
		int i;

		nsp = sp->leftchild;
		c = INFINITY;
		win = 0;
		for(i = 0; i < MAXLABELS; i++){
			mp = nsp->succ[i];
			if(mp != 0 && COSTLESS(mp->cost, c)){
				c = mp->cost;
				win = mp;
			}
		}
		if(mtDebug || treedebug)
			_prskel(nsp, 0);
		_do(nsp, win, 0);
	}
	if(mtDebug)
		_prskel(sp, 0);
	return sp;
}

static short _nodetab[MAXNDVAL], _labeltab[MAXLABELS];

/*
 * Convert the start state which has a large branching factor into
 * a index table.  This must be called before the matcher is used.
 */
void
_matchinit(void)
{
	short *sp;

	for(sp = _nodetab; sp < &_nodetab[MAXNDVAL]; sp++)
		*sp = HANG;
	for(sp = _labeltab; sp < &_labeltab[MAXLABELS]; sp++)
		*sp = HANG;
	sp = &mtTable[mtStart];
	_twig_assert(*sp == TABLE, "mtTable[mtStart]!=TABLE");
	for(++sp; *sp != -1; sp += 2){
		if(MI_NODE(*sp))
			_nodetab[M_DETAG(*sp)] = sp[1];
		else if(MI_LABEL(*sp))
			_labeltab[M_DETAG(*sp)] = sp[1];
	}
}

int
_machstep(short state, short input)
{
	register short *stp = &mtTable[state];
	int start = 0;

	if(state == HANG)
		return input == MV_BRANCH(1) ? mtStart : HANG;
rescan:
	if(stp == &mtTable[mtStart]){
		if(MI_NODE(input))
			return _nodetab[M_DETAG(input)];
		if(MI_LABEL(input))
			return _labeltab[M_DETAG(input)];
	}
	
	for(;;){
		if(*stp == ACCEPT)
			stp += 2;
		if(*stp == TABLE){
			stp++;
			while(*stp != -1)
				if(input == *stp)
					return stp[1];
				else
					stp += 2;
			stp++;
		}
		if(*stp != FAIL){
			if(start)
				return HANG;
			else{
				stp = &mtTable[mtStart];
				start = 1;
				goto rescan;
			}
		}else{
			stp = &mtTable[stp[1]];
			goto rescan;
		}
	}
}

void
_addmatches(int ostate, register skeleton *sp, register __match *np)
{
	int label;
	int state;
	register __match *mp;

        label = mtMap[np->tree];

	/*
	 * this is a very poor substitute for good design of the DFA.
	 * What we need is a special case that allows any label to be accepted
	 * by the start state but we don't want the start state to recognize
	 * them after a failure.
	 */
	state = _machstep(ostate, MV_LABEL(label));
	if(ostate != mtStart && state == HANG){
		_freematch(np);
		return;
	}

	np->lleaves = _getleaves(np, sp);
	np->skel = sp;
        if((np->mode = mtEvalCost(np, np->lleaves, sp)) == xABORT){
		_freematch(np);
		return;
	}

	if(mp = sp->succ[label]){
		if(!COSTLESS(np->cost, mp->cost)){
			_freematch(np);
			return;
		}
		_freematch(mp);
	}
	if(COSTLESS(np->cost, sp->mincost)){
		if(np->mode == xREWRITE){
			sp->mincost = np->cost;
			sp->winner = np;
		}else{
			sp->mincost = INFINITY;
			sp->winner = 0;
		}
	}
	sp->succ[label] = np;
	_closure(state, ostate, sp);
}

void
_closure(int state, int ostate, skeleton *skp)
{
	register short *sp = &mtTable[state];
	register __match *mp;

	if(state == HANG || *sp != ACCEPT)
		return;

	for(sp = &mtAccept[sp[1]]; *sp != -1; sp += 2)
		if(sp[1] == 0){
			mp = _allocmatch();	
			mp->tree = *sp;
			_addmatches(ostate, skp, mp);
		}else{
			register __partial *pp;
			register __partial *lim = &skp->partial[skp->treecnt];
			for(pp = skp->partial; pp < lim; pp++)
				if(pp->treeno == *sp)
					break;
			if(pp == lim){
				skp->treecnt++;
				pp->treeno = *sp;
				pp->bits = 1 << sp[1];
			}else
				pp->bits |= 1 << sp[1];
		}
}

void
_merge(skeleton *old, skeleton *new)
{
	register __partial *op = old->partial, *np = new->partial;
	int nson = new->nson;
	register __partial *lim = np + new->treecnt;
	if(nson == 1){
		old->treecnt = new->treecnt;
		for(; np < lim; op++, np++) {
			op->treeno = np->treeno;
			op->bits = np->bits / 2;
		}
	}else{
		__partial *newer = _allocpartial();
		register __partial *newerp = newer;
		register int cnt;
		lim = op + old->treecnt;
		for(cnt = new->treecnt; cnt-- ; np++){
			for(op = old->partial; op < lim; op++)
				if(op->treeno == np->treeno){
					newerp->treeno = op->treeno;
					newerp++->bits = op->bits & np->bits / 2;
					break;
				}
		}
		_freepartial(old->partial);
		old->partial = newer;
		old->treecnt = newerp-newer;
	}
}
 
/* memory management */

#define BLKF	100

typedef union __matchalloc{
	__match			it;
	union __matchalloc	*next;
}__matchalloc;
static __matchalloc *__matchfree = 0;
#ifdef CHECKMEM
staic int a_matches;
#endif

__match *
_allocmatch(void)
{
	static int count = 0;
	static __matchalloc *block = 0;
	__matchalloc *m;

	if(__matchfree){
		m = __matchfree;
		__matchfree = __matchfree->next;
	}else{
		if(count == 0){
			block = (void *)malloc(BLKF * sizeof *block);
			count = BLKF;
		}
		m = block++;
		count--;
	}
#ifdef CHECKMEM
		a_matches++;
#endif
	return (__match *)m;
}

void
_freematch(__match *mp)
{
	__matchalloc *m = (__matchalloc *)mp;
	m->next = __matchfree;
	__matchfree = m;
#ifdef CHECKMEM
	a_matches--;
#endif
}

typedef union __partalloc{
	__partial		it[MAXTREES];
	union __partalloc	*next;
}__partalloc;
static __partalloc *__partfree = 0;
#ifdef CHECKMEM
static int a_partials;
#endif

__partial *
_allocpartial(void)
{
	static int count = 0;
	static __partalloc *block = 0;
	__partalloc *p;

	if(__partfree != 0){
		p = __partfree;
		__partfree = __partfree->next;
	}else{
		if(count == 0){
			block = (void *)malloc(BLKF * sizeof *block);
			count = BLKF;
		}
		p = block++;
		count--;
	}
#ifdef CHECKMEM
		a_partials++;
#endif
	return (__partial *)p;
}

void
_freepartial(__partial *pp)
{
	__partalloc *p = (__partalloc *)pp;
	p->next = __partfree;
	__partfree = p;
#ifdef CHECKMEM
	a_partials--;
#endif
}

typedef union __skelalloc{
	skeleton		it;
	union __skelalloc	*next;
}__skelalloc;
static __skelalloc *__skelfree = 0;

skeleton *
_allocskel(void)
{
	static int count = 0;
	static __skelalloc *block = 0;
	__skelalloc *sf;
	skeleton *s;
	int i;

	if(__skelfree){
		sf = __skelfree;
		__skelfree = sf->next;
	}else{
		if(count == 0){
			block = (void *)malloc(BLKF * sizeof *block);
			count = BLKF;
		}
		sf = block++;
		count--;
	}
	s = (skeleton *)sf;
	s->sibling = 0;
	s->leftchild = 0;
	i = 0;
	while(i < MAXLABELS)
		s->succ[i++] = 0;
	s->treecnt = 0;
	s->partial = _allocpartial();
	return s;
}

void
_freeskel(skeleton *s)
{
	int i;
	__match *mp;
	__skelalloc *sf;

	if(s == 0)
		return;
	if(s->leftchild)
		_freeskel(s->leftchild);
	if(s->sibling)
		_freeskel(s->sibling);
	_freepartial(s->partial);
	i = 0;
	while(i < MAXLABELS)
		if(mp = s->succ[i++])
			_freematch(mp);
	sf = (__skelalloc *)s;
	sf->next = __skelfree;
	__skelfree = sf;
}

void
_match(void)
{
	skeleton *sp;
	sp = _allocskel();
	sp->root = 0;
	_mpbtop = _mpblock;
	_freeskel(_walk(sp, HANG));
#ifdef CHECKMEM
	_twig_assert(a_matches == 0, "__match memory leak");
	_twig_assert(a_partials == 0, "__partial memory leak");
#endif
}

NODEPTR
_mtG(NODEPTR root, ...)
{
	va_list a;
	int i;

	va_start(a, root);
	while((i = va_arg(a, int)) != -1)
		root = mtGetNodes(root, i);
	va_end(a);
	return root;
}

/* diagnostic routines */
void
_prskel(skeleton *skp, int lvl)
{
	int i;
	__match *mp;
	__partial *pp;
	if(skp==0)
		return;
	for(i = lvl; i > 0; i--)
		fprintf(stderr, "  ");
	fprintf(stderr, "###\n");
	for(i = lvl; i > 0; i--)
		fprintf(stderr, "  ");
	for(i = 0; i < MAXLABELS; i++)
		if(mp = skp->succ[i])
#ifdef LINE_XREF
			fprintf(stderr, "[%d<%d> %d]", mp->tree,
				mtLine[mp->tree], mp->cost);
#else
			fprintf(stderr, "[%d %d]", mp->tree, mp->cost);
#endif
	fprintf(stderr, "\n");
	for(i = lvl; i > 0; i--)
		fprintf(stderr, "  ");
	for(i = 0, pp=skp->partial; i < skp->treecnt; i++, pp++)
#ifdef LINE_XREF
			fprintf(stderr, "(%d<%d> %x)", pp->treeno, mtLine[pp->treeno],
				pp->bits);
#else
			fprintf(stderr, "(%d %x)", pp->treeno, pp->bits);
#endif
	fprintf(stderr, "\n");
	_prskel(skp->leftchild, lvl + 2);
	_prskel(skp->sibling, lvl);
}
short mtTable[] = {
3,0,-1,3,3,-1,3,6,-1,3
,9,-1,3,12,-1,3,15,2,9,-1
,3,20,2,12,-1,3,25,2,3,-1
,1,01000,25,-1,2,44,-1,1,010001,30
,-1,2,53,-1,1,00,15,01,20,04
,37,-1,-1,1,010001,44,-1,-1,3,30
,2,3,-1,1,01000,58,-1,2,44,-1
,1,010001,63,-1,2,53,-1,3,35,2
,3,-1,3,40,2,9,-1,3,45,2
,12,-1,1,04,70,01000,77,00,82,01
,87,-1,-1,3,50,2,3,-1,3,59
,2,3,-1,1,01000,108,-1,2,44,-1
,1,010001,113,-1,2,53,-1,1,01000,103
,04,120,-1,-1,1,010001,92,010002,127,-1
,-1,3,64,2,3,-1,1,01000,141,-1
,-1,3,69,2,3,-1,1,01000,151,-1
,-1,1,010001,146,010002,156,-1,-1,1,05
,161,-1,-1,3,74,2,3,-1,1,01000
,173,-1,2,44,-1,1,010001,178,-1,2
,53,-1,1,04,185,-1,-1,3,79,2
,3,-1,1,01000,197,-1,-1,1,010001,192
,010002,202,-1,-1,1,05,207,-1,-1,1
,010001,168,010002,214,-1,-1,1,03,0,01000
,3,02,6,00,9,01,12,04,53,07
,134,06,219,-1,-1};
short mtAccept[] = {
0,0,-1,1,0,-1,2,0,-1,3
,0,-1,4,0,-1,3,0,5,1,-1
,4,0,6,1,-1,1,0,7,2,-1
,1,0,8,2,-1,1,0,9,1,-1
,3,0,10,1,-1,4,0,11,1,-1
,1,0,11,1,10,1,8,1,-1,1
,0,9,2,-1,1,0,12,2,-1,1
,0,12,2,-1,1,0,12,3,-1,1
,0,12,2,-1};
short mtStart = 226;
short int mtMap[] = {
01,01,00,00,00,00,00,00,00,00
,00,00,00};
short int mtPaths[] = {
4,-4,-4,-2,01000,-3,-2,01000,-1,-3
,-4,-4,-2,01000,-1,-3,-2,01000,-1,-1
,0,1,-4,-3,-2,01000,-1,0,1,-4
,-3,-2,01000,-1,0,2,-4,-2,01000,-3
,-4,-2,01000,-1,-1,0,2,-4,-4,-2
,01000,-1,-3,-2,01000,-1,0,1,-4,-4
,-2,01000,-1,-1,0,0,0,0,0,0
,0,0,0,0,0,1,-2,01000,0,0
,0 };
short int mtPathStart[] = {
79,75,73,71,69,67,65,57,46,35
,28,21,0};
NODEPTR
mtAction (int _t, __match **_ll, skeleton *_s)
{ NODEPTR root = _s->root;
switch (_t) {
case 0:{

# line 28 "act.mt"

		push(root);
	} break;
case 1:{

# line 34 "act.mt"

	} break;
case 2:{

# line 39 "act.mt"

		push(root);
	} break;
case 3:{

# line 45 "act.mt"

		push(root);
	} break;
case 4:{

# line 51 "act.mt"

		push(root);
	} break;
case 5:{

# line 57 "act.mt"

		push(ONE);
	} break;
case 6:{

# line 63 "act.mt"

		push(ZERO);
	} break;
case 7:{

# line 69 "act.mt"

		tDO(_ll[(1)-1]);
	} break;
case 8:{

# line 87 "act.mt"

		return nameit(root->id,notnode(xornode(_mtG(root,1,1, -1),_mtG(root,2, -1))));
	} break;
case 9:{

# line 93 "act.mt"

		return nameit(root->id,notnode(xornode(_mtG(root,1, -1),_mtG(root,2,1, -1))));
	} break;
case 10:{

# line 102 "act.mt"

		return _mtG(root,2, -1);
	} break;
case 11:{

# line 108 "act.mt"

		return notnode(_mtG(root,2, -1));
	} break;
case 12:{

# line 122 "act.mt"

		return nameit(root->id,ornode(andnode(notnode(_mtG(root,2,1,1, -1)),_mtG(root,2,2, -1)),andnode(_mtG(root,1,1, -1),_mtG(root,1,2, -1))));
	} break;
} return(_s->root);}
short
mtEvalCost(__match *_m, __match **_ll, skeleton *_s)
{ NODEPTR root = _s->root;
COST cost; cost = DEFAULT_COST;
switch(_m->tree) {
case 0:{

# line 27 "act.mt"
cost = pincost;} break;
case 1:{

# line 33 "act.mt"
} break;
case 2:{

# line 38 "act.mt"
cost = pincost;} break;
case 3:{

# line 44 "act.mt"
cost = zerocost;} break;
case 4:{

# line 50 "act.mt"
cost = zerocost;} break;
case 5:{

# line 56 "act.mt"
cost = zerocost;} break;
case 6:{

# line 62 "act.mt"
cost = zerocost;} break;
case 7:{

# line 68 "act.mt"
cost.gate -= 2; TOPDOWN;} break;
case 8:{

# line 86 "act.mt"
REWRITE;} break;
case 9:{

# line 92 "act.mt"
REWRITE;} break;
case 10:{

# line 101 "act.mt"
REWRITE;} break;
case 11:{

# line 107 "act.mt"
REWRITE;} break;
case 12:{

# line 117 "act.mt"

		if (_mtG(root,1,1, -1)->op == not)
			ABORT;
		REWRITE;
	} break;
}
_m->cost = cost; return(xDEFER);}
