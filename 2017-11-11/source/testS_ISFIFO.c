/*************************************************************************
	> File Name: testS_ISFIFO.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Nov 11 14:04:05 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include<sys/stat.h>
#include<unistd.h>

int main(){
	struct stat buf;
	int fds[2];
	pipe(fds);
	fstat(fds[0],&buf);
	if(S_ISFIFO(buf.st_mode)){
		printf("is fifo\n");
	}else{
		printf("not fifo, just pipe\n");
	}

	close(fds[0]);
	close(fds[1]);

	return 0;
}
