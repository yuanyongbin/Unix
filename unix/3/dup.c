#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[1]){
//	if(argc != 2){
//		err_sys("file is error");
//	}

	//int fileDespriptor = open(argv[1],O_RDONLY);
	int fd = open(argv[1],O_RDONLY);
	printf("%s file despritor is %d \n",argv[1],fd);
	printf("dup = %d \n" ,dup(fd));
	if (argc >= 2 ){
		int fd2 = open(argv[2],O_RDONLY);
		printf("%s file despritor is %d \n" ,argv[2],fd2);
	}
	return 0;
}
