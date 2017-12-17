#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thrd_func(void *arg);
pthread_t tid;

int main (){
	if(pthread_create(&tid,NULL,thrd_func,NULL)!=0){
		printf("Create thread error!\n");
		exit(1);
	}
	
	printf("Tid in pthread_create function : %u .\n",tid);
	printf("Main process : pid :%d ,tid : %u .\n",getpid(),pthread_self());

	sleep(1);

	return 0;
}

void *thrd_func (void *arg){
	printf("New process : PID : %d,TID : %u .\n",getpid(),pthread_self());
	printf("New process : PID : %d,TID : %u .\n",getpid(),tid);

	pthread_exit(NULL);	
}
