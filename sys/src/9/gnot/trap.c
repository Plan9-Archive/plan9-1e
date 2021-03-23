#include	"u.h"
#include	"../port/lib.h"
#include	"mem.h"
#include	"dat.h"
#include	"fns.h"
#include	"ureg.h"
#include	"io.h"
#include	"../port/error.h"

void	noted(Ureg*, ulong);
void	rfnote(Ureg*);

char *regname[]={
	"R0",
	"R1",
	"R2",
	"R3",
	"R4",
	"R5",
	"R6",
	"R7",
	"A0",
	"A1",
	"A2",
	"A3",
	"A4",
	"A5",
	"A6",
	"A7",
};

long	ticks;

char *trapname[]={
	"reset isp",
	"reset ipc",
	"bus error",
	"address error",
	"illegal instruction",
	"zero divide",
	"chk, chk2 instruction",
	"trapcc instruction",
	"privilege violation",
	"trace",
	"line 1010 emulator",
	"line 1111 emulator",
	"reserved",
	"coprocessor protocol violation",
	"format error",
	"uninitialized interrupt",
	"unassigned 0x40",
	"unassigned 0x44",
	"unassigned 0x48",
	"unassigned 0x4C",
	"unassigned 0x50",
	"unassigned 0x54",
	"unassigned 0x58",
	"unassigned 0x5C",
	"spurious interrupt",
	"level 1 autovector (tac)",
	"level 2 autovector (port)",
	"level 3 autovector (incon)",
	"level 4 autovector (mouse)",
	"level 5 autovector (uart)",
	"level 6 autovector (sync)",
	"level 7 autovector",
};

char *fptrapname[]={
[49-49]	"inexact result",
[50-49]	"divide by zero",
[51-49]	"underflow",
[52-49]	"operand error",
[53-49]	"overflow",
[54-49]	"signaling NaN",
};

char*
excname(unsigned vo, ulong pc)
{
	static char buf[32];	/* BUG: not reentrant! */
	ulong fppc;

	vo &= 0x0FFF;
	vo >>= 2;
	if(vo < sizeof trapname/sizeof(char*)){
		/* special case, and pc will be o.k. */
		if(vo==4 && *(ushort*)pc==0x4848)
			return "breakpoint";
		sprint(buf, "trap: %s", trapname[vo]);
		return buf;
	}
	if(49<=vo && vo<=54){
		fppc = 0;
		if(u)
			fppc = *(ulong*)(u->fpsave.reg+8);
		sprint(buf, "fp: %s fppc=0x%lux", fptrapname[vo-49], fppc);
		return buf;
	}
	sprint(buf, "offset 0x%ux", vo<<2);
	return buf;
}

void
trap(Ureg *ur)
{
	int user;
	char buf[64];

	user = !(ur->sr&SUPER);

	if(u)
		u->dbgreg = ur;

	if(user){
		splhi();
		procsave(u->p);
		spllo();
		sprint(buf, "sys: %s", excname(ur->vo, ur->pc));
		postnote(u->p, 1, buf, NDebug);
	}else{
		print("kernel trap %s pc=0x%lux\n", excname(ur->vo, ur->pc), ur->pc);
		dumpregs(ur);
		exit(1);
	}

	if(user)
		notify(ur);
}

void
dumpstack(void)
{
	ulong l, v, i;
	extern ulong etext;

	if(u==0)
		return;

	i = 0;
	for(l=(ulong)&l; l<USERADDR+BY2PG; l+=4){
		v = *(ulong*)l;
		if(KTZERO < v && v < (ulong)&etext){
			print("%lux\t", v);
			if(++i == 4){
				i = 0;
				print("\n");
			}
		}
	}
	print("\n");
}

void
dumpregs(Ureg *ur)
{
	int i;
	ulong *l;

	if(u)
		print("registers for %s %d\n", u->p->text, u->p->pid);
	else
		print("registers for kernel\n");
	print("SR=%ux PC=%lux VO=%lux, USP=%lux\n", ur->sr, ur->pc, ur->vo, ur->usp);
	l = &ur->r0;
	for(i=0; i<sizeof regname/sizeof(char*); i+=2, l+=2)
		print("%s\t%.8lux\t%s\t%.8lux\n", regname[i], l[0], regname[i+1], l[1]);
}

/*
 * Call user, if necessary, with note
 */
int
notify(Ureg *ur)
{
	int l, sent;
	ulong s, sp;
	Note *n;

	if(u->p->procctl)
		procctl(u->p);
	if(u->nnote == 0)
		return 0;

	s = spllo();
	qlock(&u->p->debug);
	u->p->notepending = 0;
	n = &u->note[0];
	if(strncmp(n->msg, "sys:", 4) == 0){
		l = strlen(n->msg);
		if(l > ERRLEN-15)	/* " pc=0x12345678\0" */
			l = ERRLEN-15;
		sprint(n->msg+l, " pc=0x%lux", ur->pc);
	}
	if(n->flag!=NUser && (u->notified || u->notify==0)){
		if(n->flag == NDebug)
			pprint("suicide: %s\n", n->msg);
    Die:
		qunlock(&u->p->debug);
		pexit(n->msg, n->flag!=NDebug);
	}
	sent = 0;
	if(!u->notified){
		if(!u->notify)
			goto Die;
		sent = 1;
		u->svvo = ur->vo;
		u->svsr = ur->sr;
		sp = ur->usp;
		sp -= sizeof(Ureg);
		if(!okaddr((ulong)u->notify, 1, 0)
		|| !okaddr(sp-ERRLEN-3*BY2WD, sizeof(Ureg)+ERRLEN-3*BY2WD, 0)){
			pprint("suicide: bad address in notify\n");
			qunlock(&u->p->debug);
			pexit("Suicide", 0);
		}
		u->ureg = (void*)sp;
		memmove((Ureg*)sp, ur, sizeof(Ureg));
		sp -= ERRLEN;
		memmove((char*)sp, u->note[0].msg, ERRLEN);
		sp -= 3*BY2WD;
		*(ulong*)(sp+2*BY2WD) = sp+3*BY2WD;	/* arg 2 is string */
		*(ulong*)(sp+1*BY2WD) = (ulong)u->ureg;	/* arg 1 is ureg* */
		*(ulong*)(sp+0*BY2WD) = 0;		/* arg 0 is pc */
		ur->usp = sp;
		ur->pc = (ulong)u->notify;
		ur->vo = 0x0080;	/* pretend we're returning from syscall */
		u->notified = 1;
		u->nnote--;
		memmove(&u->lastnote, &u->note[0], sizeof(Note));
		memmove(&u->note[0], &u->note[1], u->nnote*sizeof(Note));
	}
	qunlock(&u->p->debug);
	splx(s);
	return sent;
}

/*
 * Return user to state before notify()
 */
void
noted(Ureg *ur, ulong arg0)
{
	Ureg *nur;

	nur = u->ureg;
	if(nur->sr!=u->svsr || nur->vo!=u->svvo){
		pprint("bad noted ureg sr %ux vo %ux\n", nur->sr, nur->vo);
    Die:
		pexit("Suicide", 0);
	}
	qlock(&u->p->debug);
	if(!u->notified){
		qunlock(&u->p->debug);
		pprint("call to noted() when not notified\n");
		goto Die;
	}
	u->notified = 0;
	memmove(ur, u->ureg, sizeof(Ureg));
	switch(arg0){
	case NCONT:
		if(!okaddr(nur->pc, 1, 0) || !okaddr(nur->usp, BY2WD, 0)){
			pprint("suicide: trap in noted\n");
			qunlock(&u->p->debug);
			goto Die;
		}
		splhi();
		qunlock(&u->p->debug);
		rfnote(ur);
		break;
		/* never returns */

	default:
		pprint("unknown noted arg 0x%lux\n", arg0);
		u->lastnote.flag = NDebug;
		/* fall through */
		
	case NDFLT:
		if(u->lastnote.flag == NDebug)
			pprint("suicide: %s\n", u->lastnote.msg);
		qunlock(&u->p->debug);
		pexit(u->lastnote.msg, u->lastnote.flag!=NDebug);
	}
}

#include "../port/systab.h"

long
syscall(Ureg *aur)
{
	long ret;
	ulong sp;
	Ureg *ur;

	u->p->insyscall = 1;
	ur = aur;
	u->dbgreg = aur;
	u->p->pc = ur->pc;
	if(ur->sr & SUPER)
		panic("recursive system call");

	/* must save FP registers before fork */
	if(u->p->fpstate==FPactive && ur->r0==RFORK){
		splhi();
		procsave(u->p);
		spllo();
	}

	if(u->p->procctl)
		procctl(u->p);

	u->scallnr = ur->r0;
	sp = ur->usp;

	u->nerrlab = 0;
	ret = -1;
	if(!waserror()){
		if(u->scallnr >= sizeof systab/sizeof systab[0]){
			pprint("bad sys call number %d pc %lux\n", u->scallnr, ur->pc);
			postnote(u->p, 1, "sys: bad sys call", NDebug);
			error(Ebadarg);
		}

		if(sp & (BY2WD-1)){
			pprint("odd sp in sys call pc %lux sp %lux\n", ur->pc, ur->sp);
			postnote(u->p, 1, "sys: odd stack", NDebug);
			error(Ebadarg);
		}

		if(sp<(USTKTOP-BY2PG) || sp>(USTKTOP-sizeof(Sargs)))
			validaddr(sp, sizeof(Sargs), 0);

		u->s = *((Sargs*)(sp+1*BY2WD));
		u->p->psstate = sysctab[u->scallnr];

		ret = (*systab[u->scallnr])(u->s.args);
		poperror();
	}

	u->nerrlab = 0;
	u->p->insyscall = 0;
	u->p->psstate = 0;

	if(u->scallnr == NOTED)		/* ugly hack */
		noted(aur, *(ulong*)(sp+BY2WD));	/* doesn't return */
	splhi();
	if(u->scallnr!=RFORK && (u->p->procctl || u->nnote)){
		ur->r0 = ret;
		notify(ur);
	}
	return ret;
}

long
execregs(ulong entry, ulong ssize, ulong nargs)
{
	ulong *sp;

	sp = (ulong*)(USTKTOP - ssize);
	*--sp = nargs;
	((Ureg*)UREGADDR)->usp = (ulong)sp;
	((Ureg*)UREGADDR)->pc = entry;
	return USTKTOP-BY2WD;			/* address of user-level clock */
}

ulong
userpc(void)
{
	return ((Ureg*)UREGADDR)->pc;
}

/* This routine must save the values of registers the user is not permitted to write
 * from devproc and the restore the saved values before returning
 */
void
setregisters(Ureg *xp, char *pureg, char *uva, int n)
{
	ushort sr;
	ulong magic;
	ushort vo;
	char microstate[UREGVARSZ];

	sr = xp->sr;
	vo = xp->vo;
	magic = xp->magic;
	memmove(microstate, xp->microstate, UREGVARSZ);

	memmove(pureg, uva, n);

	xp->sr = (sr&0xff00) |(xp->sr&0xff);
	xp->vo = vo;
	xp->magic = magic;
	memmove(xp->microstate, microstate, UREGVARSZ);
}
