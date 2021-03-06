typedef struct Method	Method;
struct Method
{
	char	*name;
	void	(*config)(Method*);
	int	(*auth)(void);
	int	(*connect)(void);
	char	*arg;
};

extern char*	bootdisk;
extern int	(*cfs)(int);
extern int	cpuflag;
extern char	cputype[NAMELEN];
extern int	fflag;
extern int	kflag;
extern Method	method[];
extern char	password[NAMELEN];
extern void	(*pword)(int, Method*);
extern char	sys[2*NAMELEN];
extern char	terminal[NAMELEN];
extern char	username[NAMELEN];
extern char	bootfile[3*NAMELEN];
extern char	conffile[NAMELEN];
extern char	*sauth;

/* libc equivalent */
extern int	cache(int);
extern int	dkauth(void);
extern int	dkconnect(void);
extern void	fatal(char*);
extern void	getconffile(char*, char*);
extern void	getpasswd(char*, int);
extern void	key(int, Method*);
extern void	newkernel(void);
extern void	nop(int);
extern int	outin(char*, char*, int);
extern int	plumb(char*, char*, int*, char*);
extern int	readfile(char*, char*, int);
extern int	sendmsg(int, char*);
extern void	session(int);
extern void	setenv(char*, char*);
extern void	settime(int);
extern void	srvcreate(char*, int);
extern void	userpasswd(int, Method*);
extern void	warning(char*);
extern void	boot(int, char **);
extern void	bboot(int, char **);

/* methods */
extern void	config9600(Method*);
extern int	auth9600(void);
extern int	connect9600(void);
extern void	config19200(Method*);
extern int	auth19200(void);
extern int	connect19200(void);
extern void	confighs(Method*);
extern int	authhs(void);
extern int	connecths(void);
extern void	configincon(Method*);
extern int	authincon(void);
extern int	connectincon(void);
extern void	configcincon(Method*);
extern int	authcincon(void);
extern int	connectcincon(void);
extern void	configil(Method*);
extern int	authil(void);
extern int	connectil(void);
extern void	configtcp(Method*);
extern int	authtcp(void);
extern int	connecttcp(void);
extern void	configcyc(Method*);
extern int	authcyc(void);
extern int	connectcyc(void);
extern void	configlocal(Method*);
extern int	authlocal(void);
extern int	connectlocal(void);
extern void	configbri(Method*);
extern int	authbri(void);
extern int	connectbri(void);
extern void	confighybrid(Method*);
extern int	authhybrid(void);
extern int	connecthybrid(void);
