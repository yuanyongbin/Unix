#include <stdio.h>

int main (){
	int n = 5;
	int array [n];
	int x;
	for (x = 0;x < 5;x++){
		array[x] = x * 2 + 1; 
	}
	for (x = 0;x < 5;x++)
		printf("%d   ",array[x]);
	printf("\n");
	return 0;
}
