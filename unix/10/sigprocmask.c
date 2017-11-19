#include <signal.h>
#include <stdio.h>
void sig_int(int signo){
	printf("进程控制\n");	
}

int main (){
	sigset_t newmask,oldmask,zeromask;
	signal(SIGUSR1,sig_int);

	//sigemptyset(&zeromask);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGUSR1);

	sigprocmask(SIG_BLOCK,&newmask,&oldmask);

	sigsuspend(&oldmask);
	pause();	
	return 0;
}
