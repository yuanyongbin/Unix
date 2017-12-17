#include <stdio.h>

int main (){
	int a;
	char name[9] = "abcde";
	char *p;
	printf("sizeof(name) = %d \n",sizeof(name));
	printf("sizeof(p) = %d \n",sizeof(p));
	printf("sizeof(a) = %d \n",sizeof(a));
	printf("sizeof = %d \n",sizeof(&a));
	printf("sizeof(char) = %d \n",sizeof(char));
}
