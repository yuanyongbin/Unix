#include <unistd.h>
#include <stdio.h>

int main (int argc,char *argv[]){
	int n;
	if ((n = link(argv[1],argv[2])) < 0){
		printf("硬链接失败\n");
	}
	return 0;
}
