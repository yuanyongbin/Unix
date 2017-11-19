#include<stdio.h>
#include <signal.h>

int signo(int a){
	printf("我是signo函数");
}


int main (){
	signal(SIGUSR1,signo);
	pause();
	return 0;		
}
