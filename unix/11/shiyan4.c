#include "stdio.h"
#include "stdlib.h"
#define N 3     /*用户数*/
#define L 3     /*用户最多文件*/
#define S 2     /*用户最多打开文件数*/
struct  ufd       /*用户目录结构*/
{
	char  fn[10];//文件名 
	char  fa[6];//文件属性 
	int  r1;//记录长度 
	int  fd;//文件地址 
}ufd[N][L];
struct  uof     /*用户打开文件表结构*/
{
	char  fn[10];//文件名 
	 char  fa[6];//文件属性 
	 int  r1;//记录长度 
	 char st;//状态（打开/建立） 
	 int  rp;	//读指针 
	 int  wp;//写指针 
}uof[N][S]; 
struct  mfd     /*主目录结构*/
{
	char  un[10];//用户名 
	struct  ufd *p;//用户文件目录地址 
}mfd[N];
void  init( )     /*用户目录初始化函数*/
{
	int i;
	char c[3];
	for (i=0;i<N;i++)
	{
		printf("请输入用户名\n");
		scanf("%s",mfd[i].un);
		for(mfd[i].p=ufd[i]; mfd[i].p<ufd[i]+L;mfd[i].p++)
		{
			 printf("想输入用户目录ufd吗? y/n\n;");
			 scanf("%s",c);
			if(strcmp(c,"y")==0)
			{
				printf("请输入 fn,fa,r1,fd\n");
				scanf("%s,%s,%d,%d",mfd[i].p->fn, mfd[i].p->fa, &mfd[i].p->r1, &mfd[i].p->fd);
			}
			else
				break;
		}
	}
}
void outufd( )       /*输出用户目录表函数*/
{
	int i;
	for(i=0;i<N;i++)
	{
	 printf("用户%s的ufd\n", mfd[i].un);
	for(mfd[i].p=ufd[i]; mfd[i].p<ufd[i]+L; mfd[i].p++)
	  printf("%s %s %d %d\n",mfd[i].p->fn,mfd[i].p->fa,mfd[i].p->r1, mfd[i].p->fd);
	}
}
void outuof( )    /*输出用户打开文件表函数*/
{
	int i,j;
	for (i=0;i<N;i++)
	{
		printf("用户 %s 的 uof\n",mfd[i].un);
		for(j=0;j<S;j++)
		{
			printf("%s %s %d %c %d %d\n",
			uof[i][j].fn[i],
			uof[i][j].fa[i],
			uof[i][j].r1,
			uof[i][j].st,
			uof[i][j].rp,
			uof[i][j].wp);
		}
	}
}
void mcreat(int i)   /*建立文件函数*/
{
	char fn[10];
	 int j;
	 printf("请输入文件名\n");
	scanf("%*c");
	 scanf("%s",fn);
	 mfd[i].p=ufd[i];
	 loop1: while (mfd[i].p<ufd[i]+L)
	if(strcmp(fn,mfd[i].p->fn[i])==0)
	{
		printf("文件重名!\n");
		return;
	}
	else
	{
		if(strcmp(mfd[i].p->fn,NULL)==0)
		{
			j=0;
			loop2: while(j<S)
			 if(strcmp(uof[i][j].fn,NULL)==0)
			  {
					printf("请输入fn,fa,r1,fd\n");
				   scanf("%s %s %d %d",mfd[i].p->fn,mfd[i].p->fa,&mfd[i].p->r1,&mfd[i].p->fd);
				   strcpy(uof[i][j].fn[i],mfd[i].p->fn[i]);
				   strcpy(uof[i][j].fa[i],mfd[i].p->fa[i]);
				   uof[i][j].r1=mfd[i].p->r1;
				   uof[i][j].st='c';
				   uof[i][j].rp=rand();
				   uof[i][j].wp=rand();
				   printf("建立成功！\n");
				   goto next1;
			 }
			else 
			{
				j++;
				 goto loop2;}
				printf("超出打开文件数!\n");
				goto next1;
			}
		else
		{
			mfd[i].p++;
		   goto loop1;
		}
	}
	printf("超出用户文件数!\n");
	next1: ;
}
void mopen(int i)    /*打开文件函数*/
{

	char fn[10],fa[6];
	 int j;
	printf("请输入文件名!\n");
    scanf("%*c");
	scanf("%s",fn);
	for(mfd[i].p=ufd[i];mfd[i].p<ufd[i]+L;mfd[i].p++)
	 if(strcmp(fn,mfd[i].p->fn[i])==0)
	goto next1;
	printf("文件不存在,不能打开!\n");
	goto next;
	next1: j=0;
	loop1: while(j<S)
	 if(strcmp(uof[i][j].fn[i],fn)==0)
	  if(uof[i][j].st=='c')
	   {printf("文件正在建立,不能打开!\n");
		goto next1;}
	else
	{printf("文件打开成功!\n");
	goto next;}
	else
	if(strcmp(uof[i][j].fn,NULL)==0)
	{
		printf("请输入文件属性\n");
		 scanf("%s ",&fa);
		 if(strcmp(fa, mfd[i].p->fa)==0)
		 {
			 strcpy(uof[i][j].fn[i],mfd[i].p->fn[i]);
			 strcpy(uof[i][j].fa[i],mfd[i].p->fa[i]);
			 uof[i][j].r1=mfd[i].p->r1;
			 uof[i][j].st='o';
			 uof[i][j].rp=rand();
			 uof[i][j].wp=rand();
			 printf("open succeed\n");
			 goto next;
		 }
	else
	   {
		printf("非法操作，不能打开！\n");
		goto next1;
	}
	}
	  else
	{j++;
	goto loop1;}
	printf("超出打开文件数！\n");
	next: ;
 }
main( )
{
	int i;
   char us[10];
   char c;
   init( );
   outufd( );
   outuof( );
   printf("下面开始文件操作\n");
   printf("------------------------\n");
	loop1: printf("请输入用户名\n");
	scanf("%*c");
	scanf("%s",us);
	for(i=0;i<N;i++)
	if(strcmp(us,mfd[i].un)==0)
	goto loop2;
	printf("没有这个用户\n");
	goto loop1;
	loop2: printf("请输入操作命令\n");
		scanf("%*c");
		scanf("%c",&c);
	switch(c)
	{
	case 'c': mcreat(i);
			break;
	case 'o': mopen(i);
			break;
	case 'e': outufd();
		   outuof();
		   exit(0);
	default: printf("命令错！\n");
		  break;
	}
	goto loop1;
}
