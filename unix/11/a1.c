#include <stdio.h>

double func(int n);
int main (){
//	int i;
//	double num = 0.0;
	int n;
	
	printf("请输入整数n : ");
	scanf("%d",&n);
	
	
	printf("1-1/2+1/3+1/4+ ... +1/n  = %f\n",func(n));

	
}

double func(int n){
	int i;
	double num = 0.0;	
	for (i = 1;i<=n;i++){
		if(i%2 == 0)
			num = num -(1.0/i);
		if(i%2 != 0)
			num += 1.0/i;
	}
	return num;
}
