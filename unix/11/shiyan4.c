#include "stdio.h"
#include "stdlib.h"
#define N 3     /*�û���*/
#define L 3     /*�û�����ļ�*/
#define S 2     /*�û������ļ���*/
struct  ufd       /*�û�Ŀ¼�ṹ*/
{
	char  fn[10];//�ļ��� 
	char  fa[6];//�ļ����� 
	int  r1;//��¼���� 
	int  fd;//�ļ���ַ 
}ufd[N][L];
struct  uof     /*�û����ļ���ṹ*/
{
	char  fn[10];//�ļ��� 
	 char  fa[6];//�ļ����� 
	 int  r1;//��¼���� 
	 char st;//״̬����/������ 
	 int  rp;	//��ָ�� 
	 int  wp;//дָ�� 
}uof[N][S]; 
struct  mfd     /*��Ŀ¼�ṹ*/
{
	char  un[10];//�û��� 
	struct  ufd *p;//�û��ļ�Ŀ¼��ַ 
}mfd[N];
void  init( )     /*�û�Ŀ¼��ʼ������*/
{
	int i;
	char c[3];
	for (i=0;i<N;i++)
	{
		printf("�������û���\n");
		scanf("%s",mfd[i].un);
		for(mfd[i].p=ufd[i]; mfd[i].p<ufd[i]+L;mfd[i].p++)
		{
			 printf("�������û�Ŀ¼ufd��? y/n\n;");
			 scanf("%s",c);
			if(strcmp(c,"y")==0)
			{
				printf("������ fn,fa,r1,fd\n");
				scanf("%s,%s,%d,%d",mfd[i].p->fn, mfd[i].p->fa, &mfd[i].p->r1, &mfd[i].p->fd);
			}
			else
				break;
		}
	}
}
void outufd( )       /*����û�Ŀ¼����*/
{
	int i;
	for(i=0;i<N;i++)
	{
	 printf("�û�%s��ufd\n", mfd[i].un);
	for(mfd[i].p=ufd[i]; mfd[i].p<ufd[i]+L; mfd[i].p++)
	  printf("%s %s %d %d\n",mfd[i].p->fn,mfd[i].p->fa,mfd[i].p->r1, mfd[i].p->fd);
	}
}
void outuof( )    /*����û����ļ�����*/
{
	int i,j;
	for (i=0;i<N;i++)
	{
		printf("�û� %s �� uof\n",mfd[i].un);
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
void mcreat(int i)   /*�����ļ�����*/
{
	char fn[10];
	 int j;
	 printf("�������ļ���\n");
	scanf("%*c");
	 scanf("%s",fn);
	 mfd[i].p=ufd[i];
	 loop1: while (mfd[i].p<ufd[i]+L)
	if(strcmp(fn,mfd[i].p->fn[i])==0)
	{
		printf("�ļ�����!\n");
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
					printf("������fn,fa,r1,fd\n");
				   scanf("%s %s %d %d",mfd[i].p->fn,mfd[i].p->fa,&mfd[i].p->r1,&mfd[i].p->fd);
				   strcpy(uof[i][j].fn[i],mfd[i].p->fn[i]);
				   strcpy(uof[i][j].fa[i],mfd[i].p->fa[i]);
				   uof[i][j].r1=mfd[i].p->r1;
				   uof[i][j].st='c';
				   uof[i][j].rp=rand();
				   uof[i][j].wp=rand();
				   printf("�����ɹ���\n");
				   goto next1;
			 }
			else 
			{
				j++;
				 goto loop2;}
				printf("�������ļ���!\n");
				goto next1;
			}
		else
		{
			mfd[i].p++;
		   goto loop1;
		}
	}
	printf("�����û��ļ���!\n");
	next1: ;
}
void mopen(int i)    /*���ļ�����*/
{

	char fn[10],fa[6];
	 int j;
	printf("�������ļ���!\n");
    scanf("%*c");
	scanf("%s",fn);
	for(mfd[i].p=ufd[i];mfd[i].p<ufd[i]+L;mfd[i].p++)
	 if(strcmp(fn,mfd[i].p->fn[i])==0)
	goto next1;
	printf("�ļ�������,���ܴ�!\n");
	goto next;
	next1: j=0;
	loop1: while(j<S)
	 if(strcmp(uof[i][j].fn[i],fn)==0)
	  if(uof[i][j].st=='c')
	   {printf("�ļ����ڽ���,���ܴ�!\n");
		goto next1;}
	else
	{printf("�ļ��򿪳ɹ�!\n");
	goto next;}
	else
	if(strcmp(uof[i][j].fn,NULL)==0)
	{
		printf("�������ļ�����\n");
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
		printf("�Ƿ����������ܴ򿪣�\n");
		goto next1;
	}
	}
	  else
	{j++;
	goto loop1;}
	printf("�������ļ�����\n");
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
   printf("���濪ʼ�ļ�����\n");
   printf("------------------------\n");
	loop1: printf("�������û���\n");
	scanf("%*c");
	scanf("%s",us);
	for(i=0;i<N;i++)
	if(strcmp(us,mfd[i].un)==0)
	goto loop2;
	printf("û������û�\n");
	goto loop1;
	loop2: printf("�������������\n");
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
	default: printf("�����\n");
		  break;
	}
	goto loop1;
}
