#include <stdio.h>

typedef struct student{
	int num;
	char name[40];
	int height;
	int fen;
}stu;

int main (){
	int i;
	stu lq,b;
//	for(i = 0;i<2;i++){
		printf("请输入学号 :");
		scanf("%d",&lq.num);
		printf("\n请输入姓名 :");
		scanf("%s",lq.name);
		printf("\n请输入身高 :");
		scanf("%d",&lq.height);
		printf("\n请输入分数 :");
		scanf("%d",&lq.fen);
          printf("\b请输入学号 :");
          scanf("%d",&b.num);
          printf("\n请输入姓名 :");
          scanf("%s",b.name);
          printf("\n请输入身高 :");
          scanf("%d",&b.height);
          printf("\n请输入分数 :");
          scanf("%d",&b.fen);	
//	printf("请输入");
	if(lq.height > b.height){
		printf("lq的学号是：%d lq的名字是：%s\n",lq.num,lq.name);
		printf("b的学号是：%d b的名字是：%s\n",b.num,b.name);
	}else {
		printf("b的学号是：%d b的名字是：%s\n",b.num,b.name);
		 printf("lq的学号是：%d lq的名字是：%s\n",lq.num,lq.name);
	}
}
