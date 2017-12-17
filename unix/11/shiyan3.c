#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define len sizeof(struct page) 
struct pagetable 
{ 
  int pagenum; //页号 
  int blocknum; //主存块号 
  char state; // 是否在主存 
}num[1024]; 
  
struct page //FIFO队列节点的结构体类型 
{ 
  int pagenum; 
  int blocknum; 
  struct page *next; 
}*head=NULL,*tail=NULL; 
  
int blocktable[3]={0,0,0}; //分配给进程的物理块，0代表该块未分配，1代表已分配 

void print(int a) //本程序只输出页表信息，没有输出其他信息，a代表进程所占页数 
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
void insert(int n,int m) //将页号n，主存块号m 插入FIFO队列中 
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
  scanf("%d",&a); //a 进程大小 
  b=a/1024; //b 进程占了多少页 
  
  for(i=0;i<=b;i++) //初始化页表 
  { 
    num[i].pagenum=i; 
    num[i].blocknum=-1; 
    num[i].state='F'; 
  } 
  print(b); //输出所有页的页号 主存块号 状态 
  
  /*#####Start to request the page!#####*/
  
  do
  { 
    ch=getchar(); //getch(); 
    j=0; 
    printf("*****please input the adress:"); 
    scanf("%d",&c); //c 逻辑地址 
    if(c>a) //如果大于进程大小，则越界 
      printf("\n*****The adress is slop over!\n"); 
    else
    { 
      d=c/1024; //d 逻辑地址对应的页号 
      s=num[d].state; 
      if(s=='T') //如果该页在主存中，输出所有页的页号 主存块号 状态 
        print(b); 
      else
      { 
        for(j=0;j<3;j++) //判断主存块是否已满  为该进程分配3个主存块 
          if(blocktable[j]==0) //如果主存块未满 
          { 
            blocktable[j]=1; 
            num[d].pagenum=d; 
            num[d].blocknum=j; 
            num[d].state='T'; 
  
  
            print(b); 
            insert(d,j); //将主存块插入FIFO队列 
            break; 
          } 
  
          /*#####Start FIFO arithmetic!!!#####*/
  
          if(j==3) //如果主存块已满 
          { 
            int h; 
            h=head->pagenum; //将FIFO队列队首页面换出 
            num[d].blocknum=head->blocknum; 
            num[d].state='T'; 
            num[h].blocknum=-1; 
            num[h].state='F'; 
            print(b); 
            
            //将换入的页面信息记录pgae中，挂在FIFO队列尾 
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
