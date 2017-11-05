#include "apue.h"
#include <sys/wait.h>


void pr_exit(int status){
	if(WIFEXITED(status))
		printf("normal termination exit status = %d\n",WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termimation,signal number = %d %s\n",WTERMSIG(status),
	#ifdef WCOREDUMP
		WCOREDUMP(stutus)  ? " (core file generated)" : "");
	#else
	 	"");
	#endif 
		else if (WIFSTOPPED(status))
			printf("child stopped signal number = %d \n",WSTOPSIG(status));
}
