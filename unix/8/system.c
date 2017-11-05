#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system(const char *cmdstring){
	pid_t pid;
	int status;
	if(cmdstring == NULL)
		return(1);


	
}
