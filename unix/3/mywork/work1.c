#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 4096 
#define RWXRWRW S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH 

char * mybuff(char *buf);
int main (int argc,char *argv[]){
	int n;
	int fd;   //文件描述符
	int fdtarget;
	int fdopen;
	char buf[BUFFSIZE]; //缓冲区
	char *buf2;

	//检查参数问题
	if(argc != 3){
		printf("参数问题:格式:可执行文件 源文件 目标文件");
		exit(0);
	}
	//打开目标文件 -- 文件不存在则创建
	if((fdtarget = open(argv[2],O_CREAT,RWXRWRW) ) < 0){
		printf("打开目标文件失败;\n");
		exit(0);
}
	// 打开目标文件
	if((fdopen = open(argv[2],O_RDWR)) < 0){
		printf("打开目标文件失败");	
		exit(0);
}
	//设置目标文件偏移量
	if((lseek(fdtarget,0,SEEK_SET)) < 0){
		printf("目标文件偏移量设置失败");
		exit(0);
	}
	fd = open(argv[1],O_RDWR);
	//读文件
	while ((n = read(fd,buf,BUFFSIZE)) > 0){
		
		buf2 = mybuff(buf);
		//if(lseek(fd,0,SEEK_CUR) < 0)
		//	err_sys("文件偏移量出错啦");
		//lessk(fd,0,SEEK_CUR);
		if (write(fdopen,buf2,n) < 0){
			printf("写文件出错啦");
			exit(0);
		}
	}
}



//缓冲区问题
char *mybuff (char *buf){
	//检查缓冲区为空
	int x;
	
	if(strlen(buf) < 0) {
		printf("缓冲区为空");
	}

	//检查关键字符
	for(x= 0;x < BUFFSIZE;x++){
		if(buf[x] == 'F' && buf[x+1]=='0' && buf[x+2] == ' ' && buf[x+3] == 'F' && buf[x+4] == 'A'){
			buf[x+2] = '\n';
			x = x+2;
		}
	}
//	printf("%s",buf);
	return buf;
}
