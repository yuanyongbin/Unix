#include <stdio.h>


int main (){
	int n = 10;
	int x;
	int array[10] = { [5] = 5,[8] = 8};
	// 遍历数组
	
	for(x = 0 ;x < 10;x++){
		printf("%d  ",array[x]);
	}
	printf("\n");
	return 0;
}
