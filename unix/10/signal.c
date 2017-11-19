#include "apue.h"

static void sig_usr(int);

int main(){
	if(signal(SIGUSR1,sig_usr) == SIG_ERR)
		err_sys("can't catch sigusr1");
	if(signal(SIGUSR2,sig_usr) == SIG_ERR)
		err_sys("can't catch sigusr2");

	for( ; ; )
		pause();
}


static void sig_usr(int signo){
	if(signo == SIGUSR1)
		printf("sigusr1");
	else if(signo == SIGUSR2)
		printf("sigusr2");
	else 
		err_dump("signal %d \n",signo);
}
