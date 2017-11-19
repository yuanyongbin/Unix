
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int num){
	printf("receive the signal %d. \n",num);
}


int main (){
	signal(SIGALRM,sig_handler);  // 注册信号

	alarm(2);    //时钟发送信号

	while(1){
	//	pause();
		printf("我pause函数 我在休眠. \n");
		pause();
	}
	exit(0);

}
