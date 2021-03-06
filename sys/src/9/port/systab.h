#undef	CHDIR	/* BUG */
#include "/sys/src/libc/9syscall/sys.h"

typedef long Syscall(ulong*);

Syscall sysr1;
Syscall syserrstr;
Syscall sysbind;
Syscall syschdir;
Syscall sysclose;
Syscall sysdup;
Syscall sysalarm;
Syscall sysexec;
Syscall sysexits;
Syscall sys_x1;
Syscall sys_x2;
Syscall sysfstat;
Syscall syssegbrk;
Syscall sysmount;
Syscall sysopen;
Syscall sysread;
Syscall sysseek;
Syscall syssleep;
Syscall sysstat;
Syscall sysrfork;
Syscall syswrite;
Syscall syspipe;
Syscall syscreate;
Syscall sys_x3;
Syscall sysbrk_;
Syscall sysremove;
Syscall syswstat;
Syscall sysfwstat;
Syscall sysnotify;
Syscall sysnoted;
Syscall syssegattach;
Syscall syssegdetach;
Syscall syssegfree;
Syscall syssegflush;
Syscall sysrendezvous;
Syscall sysunmount;
Syscall syswait;
Syscall	sysdeath;

Syscall *systab[]={
	[SYSR1]		sysr1,
	[ERRSTR]	syserrstr,
	[BIND]		sysbind,
	[CHDIR]		syschdir,
	[CLOSE]		sysclose,
	[DUP]		sysdup,
	[ALARM]		sysalarm,
	[EXEC]		sysexec,
	[EXITS]		sysexits,
	[_X1]		sysdeath,
	[_X2]		sysdeath,
	[FSTAT]		sysfstat,
	[SEGBRK]	syssegbrk,
	[MOUNT]		sysmount,
	[OPEN]		sysopen,
	[READ]		sysread,
	[SEEK]		sysseek,
	[SLEEP]		syssleep,
	[STAT]		sysstat,
	[RFORK]		sysrfork,
	[WRITE]		syswrite,
	[PIPE]		syspipe,
	[CREATE]	syscreate,
	[_X3]		sysdeath,
	[BRK_]		sysbrk_,
	[REMOVE]	sysremove,
	[WSTAT]		syswstat,
	[FWSTAT]	sysfwstat,
	[NOTIFY]	sysnotify,
	[NOTED]		sysnoted,
	[SEGATTACH]	syssegattach,
	[SEGDETACH]	syssegdetach,
	[SEGFREE]	syssegfree,
	[SEGFLUSH]	syssegflush,
	[RENDEZVOUS]	sysrendezvous,
	[UNMOUNT]	sysunmount,
	[WAIT]		syswait,
};

char *sysctab[]={
	[SYSR1]		"Running",
	[ERRSTR]	"Errstr",
	[BIND]		"Bind",
	[CHDIR]		"Chdir",
	[CLOSE]		"Close",
	[DUP]		"Dup",
	[ALARM]		"Alarm",
	[EXEC]		"Exec",
	[EXITS]		"Exits",
	[_X1]		"_x1",
	[_X2]		"_x2",
	[FSTAT]		"Fstat",
	[SEGBRK]	"Segbrk",
	[MOUNT]		"Mount",
	[OPEN]		"Open",
	[READ]		"Read",
	[SEEK]		"Seek",
	[SLEEP]		"Sleep",
	[STAT]		"Stat",
	[RFORK]		"Rfork",
	[WRITE]		"Write",
	[PIPE]		"Pipe",
	[CREATE]	"Create",
	[_X3]		"_x3",
	[BRK_]		"Brk",
	[REMOVE]	"Remove",
	[WSTAT]		"Wstat",
	[FWSTAT]	"Fwstat",
	[NOTIFY]	"Notify",
	[NOTED]		"Noted",
	[SEGATTACH]	"Segattach",
	[SEGDETACH]	"Segdetach",
	[SEGFREE]	"Segfree",
	[SEGFLUSH]	"Segflush",
	[RENDEZVOUS]	"Rendez",
	[UNMOUNT]	"Unmount",
	[WAIT]		"Wait",
};
