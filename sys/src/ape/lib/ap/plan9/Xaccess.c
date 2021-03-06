#include "lib.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "sys9.h"
#include "dir.h"

int
__access(const char *name, int mode)
{
	int fd, n;
	char db[DIRLEN];
	struct stat st;
	static char omode[] = {
		0,
		3,
		1,
		2,
		0,
		2,
		2,
		2
	};
	char tname[1024];

	if(mode == 0){
		if(_STAT(name, db) >= 0)
			return 0;
		else {
			_syserrno();
			return -1;
		}
	}
	fd = open(name, omode[mode&7]);
	if(fd >= 0){
		close(fd);
		return 0;
	}
	else if(stat(name, &st)==0 && S_ISDIR(st.st_mode)){
		if(mode & (R_OK|X_OK)){
			fd = open(name, O_RDONLY);
			if(fd < 0)
				return -1;
			close(fd);
		}
		if(mode & W_OK){
			strncpy(tname, name, sizeof(tname)-9);
			strcat(tname, "/_AcChAcK");
			fd = creat(tname, 0666);
			if(fd < 0)
				return -1;
			close(fd);
			_REMOVE(tname);
		}
		return 0;
	}
	return -1;
}
