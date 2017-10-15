#include <stdlib.h>
#include <stdio.h>
//#include <iostream.h>


int main(){
	printf("fileno(stdin) = %d \n",fileno(stdin));
	printf("fileno(stdout) = %d \n",fileno(stdout));
	FILE *fp = fopen("./read","r");
	printf("fileno(./read.c) = %d \n",fileno(fp));
	FILE *fp1 = fopen("./kong.c","r");
	printf("fileno(kong.c) = %d \n" ,fileno(fp1));	
	return 0;
}
