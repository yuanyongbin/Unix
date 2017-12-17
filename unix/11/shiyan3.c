#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define len sizeof(struct page) 
struct pagetable 
{ 
  int pagenum; //ҳ�� 
  int blocknum; //������ 
  char state; // �Ƿ������� 
}num[1024]; 
  
struct page //FIFO���нڵ�Ľṹ������ 
{ 
  int pagenum; 
  int blocknum; 
  struct page *next; 
}*head=NULL,*tail=NULL; 
  
int blocktable[3]={0,0,0}; //��������̵�����飬0����ÿ�δ���䣬1�����ѷ��� 

void print(int a) //������ֻ���ҳ����Ϣ��û�����������Ϣ��a���������ռҳ�� 
{ 
  int i; 
  printf("\n*****pagenum  blocknum  state\n"); 
  for(i=0;i<=a;i++) 
  { 
    num[i].pagenum=i; 
    printf("%8d%8d%8c",num[i].pagenum,num[i].blocknum,num[i].state); 
    printf("\n"); 
  } 
  printf("\n"); 
} 
void insert(int n,int m) //��ҳ��n��������m ����FIFO������ 
{ 
  struct page*p; 
  p=(struct page*)malloc(len); 
  p->pagenum=n; 
  p->blocknum=m; 
  if(head==NULL) 
  { 
    head=p; 
    tail=p; 
    p->next=NULL; 
  } 
  else
  { 
    tail->next=p; 
    tail=p; 
  } 
} 
int main( void ) 
{ 
  int i,j,a,b,c,d; 
  char s; 
  char ch; 
  struct page *p; 
  
  /* #####Initialize pagetable!!!#####*/
  
  printf("*****Please input the size of process:"); 
  scanf("%d",&a); //a ���̴�С 
  b=a/1024; //b ����ռ�˶���ҳ 
  
  for(i=0;i<=b;i++) //��ʼ��ҳ�� 
  { 
    num[i].pagenum=i; 
    num[i].blocknum=-1; 
    num[i].state='F'; 
  } 
  print(b); //�������ҳ��ҳ�� ������ ״̬ 
  
  /*#####Start to request the page!#####*/
  
  do
  { 
    ch=getchar(); //getch(); 
    j=0; 
    printf("*****please input the adress:"); 
    scanf("%d",&c); //c �߼���ַ 
    if(c>a) //������ڽ��̴�С����Խ�� 
      printf("\n*****The adress is slop over!\n"); 
    else
    { 
      d=c/1024; //d �߼���ַ��Ӧ��ҳ�� 
      s=num[d].state; 
      if(s=='T') //�����ҳ�������У��������ҳ��ҳ�� ������ ״̬ 
        print(b); 
      else
      { 
        for(j=0;j<3;j++) //�ж�������Ƿ�����  Ϊ�ý��̷���3������� 
          if(blocktable[j]==0) //��������δ�� 
          { 
            blocktable[j]=1; 
            num[d].pagenum=d; 
            num[d].blocknum=j; 
            num[d].state='T'; 
  
  
            print(b); 
            insert(d,j); //����������FIFO���� 
            break; 
          } 
  
          /*#####Start FIFO arithmetic!!!#####*/
  
          if(j==3) //������������ 
          { 
            int h; 
            h=head->pagenum; //��FIFO���ж���ҳ�滻�� 
            num[d].blocknum=head->blocknum; 
            num[d].state='T'; 
            num[h].blocknum=-1; 
            num[h].state='F'; 
            print(b); 
            
            //�������ҳ����Ϣ��¼pgae�У�����FIFO����β 
            p=(struct page*)malloc(len); 
            p->pagenum=d; 
            p->blocknum=head->blocknum; 
            p->next=NULL; 
            head=head->next; 
            tail->next=p; 
            tail=p; 
          } 
      } 
    } 
  
  }while(c>=0); 
  
  return 0; 
}
