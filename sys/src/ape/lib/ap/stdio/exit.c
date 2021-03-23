#include <unistd.h>
#define	NONEXIT	34
int (*_atexitfns[NONEXIT])(void);
void exit(int status){
	int i, (*f)(void);
	for(i = NONEXIT-1; i >= 0; i--)
		if(_atexitfns[i]){
			f = _atexitfns[i];
			_atexitfns[i] = 0;	/* self defense against bozos */
			(*f)();
		}
	_exit(status);
}
atexit(int (*f)(void))
{
	int i;
	for(i=0; i<NONEXIT; i++)
		if(!_atexitfns[i]){
			_atexitfns[i] = f;
			return(0);
		}
	return(1);
}
