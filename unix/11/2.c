#include <stdio.h>

typedef struct fushu{
	int i;
	int x = 1 + 2 * i;
}fu;
int main (){
	fu a;
	fu b;
	printf("请输入第一个数 :");
	scanf("%d",&a.i);
	printf("请输入第一个数 :");
	scanf("%d",&b.i);
	printf("%d \n",a.x + b.x);
}
