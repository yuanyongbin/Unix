#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main (){
	pthread_t pid;
	pid = pthread_self();

	printf("Thread ID : %d \n",pid);
	if(pthread_equal(pid,pthread_self())){
		printf("相同\n");
	}else{
		printf("不相同\n");
	}

	return 0;
}
