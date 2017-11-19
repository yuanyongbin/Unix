#include <stdio.h>
#include <signal.h>

int main(){
	signal(SIGINT,SIG_IGN);
	for( ; ; )
		printf("紫霞仙子");
	return 0;
}
