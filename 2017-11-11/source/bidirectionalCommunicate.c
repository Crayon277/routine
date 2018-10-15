/*************************************************************************
	> File Name: bidirectionalCommunicate.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Nov 11 16:02:20 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/uio.h>

int main(){
	int fds[2];
	pipe(fds);


	if(fork()>0){
		char msg[256];
		memset(msg,0,sizeof(msg));
		read(0,msg,256);
		write(fds[1],msg,256);
		memset(msg,0,sizeof(msg));
		sleep(1);
		read(fds[0],msg,256);
		printf("from child: %s\n",msg);
		close(fds[1]);
		close(fds[0]);
		printf("father down...");
		wait(NULL);
		printf("thankyou");
	}else{
		char rec[256];
		memset(rec,0,sizeof(rec));
		read(fds[0],rec,256);
		printf("from parent: %s\n",rec);
		memset(rec,0,sizeof(rec));
		read(0,rec,256);
		write(fds[1],rec,256);

		close(fds[1]);
		close(fds[0]);
	}
	return 0;
}
