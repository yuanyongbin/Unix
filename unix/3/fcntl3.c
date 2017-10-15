#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	if (argc > 2 ){
		err_sys("参数不符合要求");
	}
	int fd = open(argv[1],O_RDONLY);
	printf("argc.df = %d\n",fd);
	
	int fcntlInt = fcntl(fd,F_DUPFD,10);
	printf("%s file descriptor is %d \n",argv[1],fcntlInt);

	return 0;

}
