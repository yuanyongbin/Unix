#include <stdio.h>

void mao(int arr[],int length,int fun);

int main (){
	int i;
	int n;
	int fun;
	printf("请输入目标数组的长度：");
	scanf("%d",&n);
	int arr[10];
	for (i=0;i<n;i++){
		printf("请输入第  %d  个数 ：",i+1);
		scanf("%d",&arr[i]);
		while (getchar() != '\n')
			continue;
	}
	printf("\n");
	printf("请输入排序方法，大于0为从小到大，小于0是从大到小：");
	scanf("%d",&fun);
	mao(arr,n,fun);
	for(i = 0;i<n;i++){
		printf("%5d ",arr[i]);
	} 
	printf("\n");
	return 0;
}

void mao(int arr[],int length,int fun){
	int i;
	int j;
	int t;
	int x;
	for (i = 0;i<length-1;i++){
		printf("---------------------  排序过程  第 %d  趟 -  DTART ----------------------------------\n",i+1);
		for (j = 1;j<length - i;j++){
			if(fun > 0){
				if(arr[j - 1] > arr[j]){
					t = arr[j - 1];
					arr[j-1] = arr[j];
					arr[j] = t;		
				}
			}
			if(fun < 0){
				if(arr[j - 1] < arr[j]){
					t = arr[j - 1];
					arr[j-1] = arr[j];
					arr[j] = t;
				}
			}
			for(x = 0;x < length;x++){
				//printf("---------------------  排序过程  ----------------------------------\n");
				printf("%5d",arr[x]);	
			}
			printf("\n");			
		}
		printf("---------------------  排序过程  第 %d  趟 -  END ----------------------------------\n",i+1);
		printf("---------------------  排序过程  第 %d  趟 目标状态----------------------------------\n",i+1);
		for(j = 0;j<length;j++){
			printf("%-5d",arr[j]);
		}
		printf("\n");
		printf("---------------------  排序过程  第 %d  趟 目标状态 ----------------------------------\n",i+1);
	}
}
