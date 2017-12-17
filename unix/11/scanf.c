#include<stdio.h>

int main (){
	int a;
	int n;
	char c;
	while(1){
		n = scanf("%d",&a);
		if(n == 0){
			c = getchar();	
			printf("我是多余的那个 ：");
			putchar(c);
			putchar('\n');
		}else 
			printf("%d \n",a);
	}
	return 0;
}
