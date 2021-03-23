#include <u.h>
#include <libc.h>
#include <bio.h>
#include <ctype.h>
#include <mach.h>
#define Extern extern
#include "acid.h"

static List **tail;

List*
construct(Node *l)
{
	List *lh, **save;

	save = tail;
	lh = 0;
	tail = &lh;
	build(l);
	tail = save;

	return lh;
}

void
build(Node *n)
{
	List *l;
	Node res;

	if(n == 0)
		return;

	switch(n->op) {
	case OLIST:
		build(n->left);
		build(n->right);
		return;
	default:
		expr(n, &res);
		l = al(res.type);
		l->Store = res.Store;
		*tail = l;
		tail = &l->next;	
	}
}

List*
addlist(List *l, List *r)
{
	List *f;

	for(f = l; f->next; f = f->next)
		;
	f->next = r;

	return l;
}

void
append(Node *r, Node *list, Node *val)
{
	List *l, *f;

	l = al(val->type);
	l->Store = val->Store;
	l->next = 0;

	r->op = OCONST;
	r->type = TLIST;

	if(list->l == 0) {
		list->l = l;
		r->l = l;
		return;
	}
	for(f = list->l; f->next; f = f->next)
		;
	f->next = l;
	r->l = list->l;
}

int
listcmp(List *l, List *r)
{
	if(l == r)
		return 1;

	while(l) {
		if(r == 0)
			return 0;
		if(l->type != r->type)
			return 0;
		switch(l->type) {
		case TINT:
			if(l->ival != r->ival)
				return 0;
			break;
		case TFLOAT:
			if(l->fval != r->fval)
				return 0;
			break;
		case TSTRING:
			if(scmp(l->string, r->string) == 0)
				return 0;
			break;
		case TLIST:
			if(listcmp(l->l, r->l) == 0)
				return 0;
			break;
		}
		l = l->next;
		r = r->next;
	}
	if(l != r)
		return 0;
	return 1;
}

void
nthelem(List *l, int n, Node *res)
{
	if(n < 0)
		error("negative index in []");

	while(l && n--)
		l = l->next;

	res->op = OCONST;
	if(l == 0) {
		res->type = TLIST;
		res->l = 0;
		return;
	}
	res->type = l->type;
	res->Store = l->Store;
}

void
delete(List *l, int n, Node *res)
{
	List **tl;

	if(n < 0)
		error("negative index in delete");

	res->op = OCONST;
	res->type = TLIST;
	res->l = l;

	for(tl = &res->l; l && n--; l = l->next)
		tl = &l->next;

	if(l == 0)
		error("element beyond end of list");
	*tl = l->next;
}

List*
listvar(char *s, long v)
{
	List *l, *tl;

	tl = al(TLIST);

	l = al(TSTRING);
	tl->l = l;
	l->fmt = 's';
	l->string = strnode(s);
	l->next = al(TINT);
	l = l->next;
	l->fmt = 'X';
	l->ival = v;

	return tl;
}

List*
listlocals(Symbol *fn, ulong fp)
{
	int i;
	long val;
	Symbol s;
	List **tail, *l2;

	l2 = 0;
	tail = &l2;
	s = *fn;
	for (i = 0; localsym(&s, i); i++) {
		if(s.class != CAUTO)
			continue;
		if(s.name[0] == '.')
			continue;
		if(get4(cormap, fp-s.value, SEGDATA, &val)) {
			*tail = listvar(s.name, val);
			tail = &(*tail)->next;
		}
	}
	return l2;
}

List*
listparams(Symbol *fn, ulong fp)
{
	int i;
	Symbol s;
	long v;
	List **tail, *l2;

	l2 = 0;
	tail = &l2;
	fp += mach->szreg;			/* skip saved pc */
	s = *fn;
	for (i = 0; localsym(&s, i); i++) {
		if (s.class != CPARAM)
			continue;
		if (get4(cormap, fp+s.value, SEGDATA, &v)) {
			*tail = listvar(s.name, v);
			tail = &(*tail)->next;
		}
	}
	return l2;
}
