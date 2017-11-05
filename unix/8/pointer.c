#include <stdio.h>

int main (){
	int a;
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	printf("pointer a %p \n", &a);
	printf("pointer arr[0] %p\n",&arr[0]);
	printf("pointer arr    %p\n",&arr);	
	printf("pointer &arr   %p\n",&arr);
	return 0;
}
