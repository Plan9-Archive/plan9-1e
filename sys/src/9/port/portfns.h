void		alarmkproc(void*);
Block*		allocb(ulong);
int		anyready(void);
Image*		attachimage(int, Chan*, ulong, ulong);
void		bitdebug(void);
void		bitdepth(void);
void		bitreverse(uchar*, int);
int		blen(Block *);
int		bround(Block *, int);
void		buzz(int, int);
void		cachedel(Image*, ulong);
void		cachepage(Page*, Image*);
int		cangetc(void*);
int		canlock(Lock*);
int		canpage(Proc*);
int		canputc(void*);
int		canqlock(QLock*);
void		chandevinit(void);
void		chandevreset(void);
void		chanfree(Chan*);
void		checkalarms(void);
void		clock(Ureg*);
Chan*		clone(Chan*, Chan*);
void		close(Chan*);
void		closeegrp(Egrp*);
void		closefgrp(Fgrp*);
void		closemount(Mount*);
void		closepgrp(Pgrp*);
long		clrfpintr(void);
void		confinit(void);
void		confinit1(int);
int		consactive(void);
void		consdebug(void);
Block*		copyb(Block*, int);
void		copypage(Page*, Page*);
void		cursoron(int);
void		cursoroff(int);
Segment*	data2txt(Segment*);
int		decref(Ref*);
int		decrypt(void*, void*, int);
void		delay(int);
Chan*		devattach(int, char*);
Chan*		devclone(Chan*, Chan*);
void		devdir(Chan*, Qid, char*, long, char*, long, Dir*);
long		devdirread(Chan*, char*, long, Dirtab*, int, Devgen*);
Devgen		devgen;
int		devno(int, int);
Chan*		devopen(Chan*, int, Dirtab*, int, Devgen*);
void		devstat(Chan*, char*, Dirtab*, int, Devgen*);
int		devwalk(Chan*, char*, Dirtab*, int, Devgen*);
void		dumpqueues(void);
void		dumpregs(Ureg*);
void		dumpstack(void);
Fgrp*		dupfgrp(Fgrp*);
void		duppage(Page*);
void		dupswap(Page*);
int		encrypt(void*, void*, int);
void		envcpy(Egrp*, Egrp*);
int		eqchan(Chan*, Chan*, long);
int		eqqid(Qid, Qid);
void		error(char*);
long		execregs(ulong, ulong, ulong);
void		exhausted(char*);
void		exit(int);
Block*		expandb(Block*, int);
int		fault(ulong, int);
void		fdclose(int, int);
Chan*		fdtochan(int, int, int, int);
int		fixfault(Segment*, ulong, int, int);
void		flowctl(Queue*, Block*);
void		flushmmu(void);
void		free(void*);
void		freeb(Block*);
int		freebroken(void);
void		freechan(Chan*);
void		freepte(Segment*, Pte*);
void		freesegs(int);
Block*		getb(Blist*);
int		getc(IOQ*);
void		getcolor(ulong, ulong*, ulong*, ulong*);
int		getfields(char*, char**, int, char);
Block*		getq(Queue*);
int		gets(IOQ*, void*, int);
void		gotolabel(Label*);
Block*		grabq(Queue*);
int		hwcursmove(int, int);
int		hwcursset(uchar*, uchar*, int, int);
long		ibrk(ulong, int);
int		incref(Ref*);
void		initq(IOQ*);
void		initscsi(void);
void		initseg(void);
void		invalidateu(void);
void		isdir(Chan*);
int		ispages(void*);
void		kbdclock(void);
int		kbdcr2nl(IOQ*, int);
int		kbdputc(IOQ*, int);
void		kbdrepeat(int);
void		kickpager(void);
int		kprint(char*, ...);
void		kproc(char*, void(*)(void*), void*);
void		kproftimer(ulong);
void		ksetenv(char*, char*);
void		ksetterm(char*);
long		latin1(uchar*);
void		lights(int);
void		lock(Lock*);
void		lockinit(void);
Page*		lookpage(Image*, ulong);
int		m3mouseputc(IOQ*, int);
void		machinit(void);
void*		malloc(ulong);
void		mapstack(Proc*);
void		mbbpt(Point);
void		mbbrect(Rectangle);
void		mfreeseg(Segment*, ulong, int);
void		mmurelease(Proc*);
void		mntdump(void);
int		mount(Chan*, Chan*, int);
void		mountfree(Mount*);
void		mousebuttons(int);
void		mousectl(char*);
void		mouseclock(void);
int		mouseputc(IOQ*, int);
void		mousescreenupdate(void);
int		msize(void*);
Chan*		namec(char*, int, int, ulong);
void		nameok(char*);
void		netdisown(Netprot*);
int		netgen(Chan*, void*, int, int, Dir*);
Chan*		netopen(Chan*, int, Network*);
int		netown(Netprot*, char*, int);
void		netadd(Network*, Netprot*, int);
long		netread(Chan*, void*, long, ulong, Network*);
void		netstat(Chan*, char*, Network*);
int		netwalk(Chan*, char*, Network*);
void		netwstat(Chan*, char*, Network*);
Chan*		newchan(void);
Mount*		newmount(Mhead*, Chan*);
Page*		newpage(int, Segment **, ulong);
Pgrp*		newpgrp(void);
Proc*		newproc(void);
void		newqinfo(Qinfo*);
Segment*	newseg(int, ulong, ulong);
char*		nextelem(char*, char*);
void		nexterror(void);
int		nodelims(Stream*);
int		notify(Ureg*);
int		nrand(int);
void		nullput(Queue*, Block*);
int		okaddr(ulong, ulong, int);
int		openmode(ulong);
Block*		padb(Block*, int);
void		pageinit(void);
void		panic(char*, ...);
void		pexit(char*, int);
void		pgrpcpy(Pgrp*, Pgrp*);
void		pgrpnote(ulong, char*, long, int);
Pgrp*		pgrptab(int);
void		pio(Segment *, ulong, ulong, Page **);
void		pixreverse(uchar*, int, int);
#define		poperror()		u->nerrlab--
int		postnote(Proc*, int, char*, int);
int		pprint(char*, ...);
void		printinit(void);
ulong		procalarm(ulong);
void		procctl(Proc*);
void		procdump(void);
void		procinit0(void);
Proc*		proctab(int);
Pte*		ptealloc(void);
Pte*		ptecpy(Pte*);
Block*		pullup(Block *, int);
Queue*		pushq(Stream*, Qinfo*);
int		putb(Blist*, Block*);
void		putbq(Blist*, Block*);
int		putc(IOQ*, int);
void		putimage(Image*);
void		putmmu(ulong, ulong, Page*);
void		putpage(Page*);
int		putq(Queue*, Block*);
void		puts(IOQ*, void*, int);
void		putseg(Segment*);
void		putstr(char*);
void		putstr(char*);
void		putstrn(char*, long);
void		putswap(Page*);
ulong		pwait(Waitmsg*);
Qinfo*		qinfofind(char*);
void		qlock(QLock*);
void		qunlock(QLock*);
int		readnum(ulong, char*, ulong, ulong, int);
int		readstr(ulong, char*, ulong, char*);
void		ready(Proc*);
void		relocateseg(Segment*, ulong);
void		resched(char*);
void		resetscsi(void);
void		resrcwait(char*);
int		return0(void*);
void		rlock(RWlock*);
void		runlock(RWlock*);
Proc*		runproc(void);
void		savefpregs(FPsave*);
void		sccclock(void);
int		sccintr(void);
void		sccsetup(void*, ulong, int);
void		sccspecial(int, IOQ*, IOQ*, int);
void		sched(void);
void		schedinit(void);
int		screenbits(void);
void		screenupdate(void);
Scsibuf*	scsialloc(ulong);
int		scsibread(int, Scsibuf*, long, long, long);
Scsibuf*	scsibuf(void);
void		scsibufreset(ulong);
int		scsibwrite(int, Scsibuf*, long, long, long);
int		scsicap(int, void*);
Scsi*		scsicmd(int, int, Scsibuf*, long);
int		scsiexec(Scsi*, int);
void		scsifree(Scsibuf*);
int		scsiinquiry(int, void*, int);
int		scsimodesense(int, int, void*, int);
int		scsiready(int);
int		scsistartstop(int, int);
int		scsisense(int, void*);
int		scsiwp(int);
long		seconds(void);
ulong		segattach(Proc*, ulong, char *, ulong, ulong);
void		segpage(Segment*, Page*);
int		setcolor(ulong, ulong, ulong, ulong);
int		setlabel(Label*);
void		setregisters(Ureg*, char*, char*, int);
void		setswapchan(Chan*);
void		simpleputpage(Page*);
char*		skipslash(char*);
void		sleep(Rendez*, int(*)(void*), void*);
void*		smalloc(ulong);
int		splhi(void);
int		spllo(void);
void		splx(int);
int		streamclose(Chan*);
int		streamclose1(Stream*);
int		streamenter(Stream*);
void		streamexit(Stream*);
Devgen		streamgen;
void		streaminit(void);
void		streaminit0(void);
Stream*		streamnew(ushort, ushort, ushort, Qinfo*, int);
void		streamopen(Chan*, Qinfo*);
int		streamparse(char*, Block*);
long		streamread(Chan*, void*, long);
void		streamstat(Chan*, char*, char*, long);
long		streamwrite(Chan*, void*, long, int);
void		naildownstream(Stream*);
void		swapinit(void);
long		syscall(Ureg*);
void		tsleep(Rendez*, int (*)(void*), void*, int);
void		unbreak(Proc*);
void		uncachepage(Page*);
long		unicode(uchar*);
long		unionread(Chan*, void*, long);
void		unlock(Lock*);
void		unmount(Chan*, Chan*);
void		urpfillstats(Chan*, char*, int);
void		userinit(void);
ulong		userpc(void);
void		validaddr(ulong, ulong, int);
void*		vmemchr(void*, int, int);
void		wakeup(Rendez*);
void		wlock(RWlock*);
void		wunlock(RWlock*);
void*		xalloc(ulong);
void		xfree(void*);
void		xhole(ulong, ulong);
void		xinit(void);
void*		xspanalloc(ulong, int, ulong);
void		xsummary(void);
Segment*	dupseg(Segment**, int, int);
Segment*	seg(Proc*, ulong, int);
