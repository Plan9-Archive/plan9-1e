void	xread(Iobuf*);
void	chat(char*, ...);
void*	ealloc(long);
void	error(char*);
Iobuf*	getbuf(Xdata*, long);
Xdata*	getxdata(char*);
void	iobuf_init(void);
void	nexterror(void);
void	panic(int, char*, ...);
void	purgebuf(Xdata*);
void	putbuf(Iobuf*);
void	refxfs(Xfs*, int);
void	showdir(int, Dir*);
Xfile*	xfile(int, int);

#define	waserror()	(++nerr_lab, setjmp(err_lab[nerr_lab-1]))
#define	poperror()	(--nerr_lab)
