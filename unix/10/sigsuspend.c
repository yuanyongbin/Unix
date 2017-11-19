#include "apue.h"

static void sig_int(int );
int main(){
	sigset_t newmask,oldmask,waitmask;

	pr_mask("program start : ");

	if(signal(SIGINT,sig_int) == SIG_ERR)
		err_sys("signal (sigint) error");
	// 信号集	
	sigemptyset(&waitmask);
	sigaddset(&waitmask,SIGUSR1);	
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGINT);

	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
		err_sys("sig_block error ");

	pr_mask("in critical region: ");
	if(sigsuspend(&waitmask) != -1)
		err_sys("sigsuspend error");
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0)
		err_sys("sig_setmask error ");
	pr_mask("program exit: ");

	exit(0);		
}

static void sig_int (int sig_no){
	pr_mask("\nint sig_int : ");
}
