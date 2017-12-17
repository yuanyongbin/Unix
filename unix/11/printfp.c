#include <stdio.h>

int main (){
	int b = 1;
	int *a = &b;
	printf("%p \n",a);
	printf("%d \n",sizeof(a));
}
