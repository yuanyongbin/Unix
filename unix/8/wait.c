#include "apue.h"
#include <sys/wait.h>

int main (){
	int status = 0;
	pid_t pid = fork();
	wait(&status);
	if(pid == 0){
		printf("我是子进程");
		exit(9);
	}
//	wait(&status);
	printf("%d \n",WEXITSTATUS(status));

}
