#include <stdio.h>


int fun(int y,int b[10]);

int main (){
	int b[10];
	int y;
	int num;
	int i;

	y = fun(4,b);
	printf("能够整除4的数为:\n");
	for(i = 0;i<y;i++){
		printf("%d,",b[i]);
	}
	printf("\n");
			
	return 0;
}

int fun(int y,int b[10]){
	int n;
	int i;
	int count=0;
	for(i=0;i<10;i++){
		printf("请输入一个整数:");
		scanf("%d",&n);
		if(n % y == 0 && n % 2 != 0){
			b[count] = n;
			count++;
		}
			
	}
	return count;	
}
