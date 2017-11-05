#include "apue.h"

int glob = 6;
char buf[] = "a write to stdout \n";

int main(){
	int var;
	pid_t pid;

	var = 88;
	if(write (STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf)-1){
		err_sys("write error");
	}
	printf("before fork \n");

	if((pid = fork()) < 0 ){
		err_sys ("fork erroe");
	} else if(pid == 0){
		glob++;
		var++;
		printf("我是子进程\n");
		exit(0);
	}else {
		sleep(2);
	}

	printf("pid = %d ,glob = %d, var = %d \n",getpid(),glob,var);

	exit(0);
}


