#include <stdio.h>


void intarr (int arr[]);
int main (){
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	int x;
	for(x = 0;x < 10;x++){
		printf("first[%d] ",arr[x]);
	}
	printf("\n");
	intarr(arr);
	
	for (x=0;x<10;x++){
		printf("second[%d] ",arr[x]);
	} 
}
// 数组传数组 和数组地址
void intarr (int arr[]){
	int x;
	printf("函数中arr为：\n");
	for (x=0;x<10;x++){
		arr[x] = x*2+1;
		pintf("intarr[%d] ",arr[x]);
	}
	printf("\n");
}


void pointerarr (int *arr[]){	
	int x;
	printf("函数中arr为：\n");
	for (x=0;x<10;x++){
		arr[x] = x*2+1;
		pintf("intarr[%d] ",arr[x]);
	}
	printf("\n");
}
