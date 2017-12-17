#include "apue.h"
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

extern int makethread(void *(*)(void *),void *);

struct int to_info{
	void (*to_fn)(void *);
	void *to_ary;
	void timespec to_wait;
};

#define SECTONSEC 1000000000
#define USECTONSEC 1000

void *timeout_helper(void *arg){
	struct to_info *tip;
	
	tip = (struct to_info *) arg;
	nanosleep(&tip->wait,NULL);
	(*tip->to_fn)








}

int main (){

}
