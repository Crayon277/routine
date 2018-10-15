/*************************************************************************
	> File Name: reviewFork.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Nov 11 11:00:46 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>



int main(int argc, char * argv[]){
	int fds[2];
	pipe(fds);
	//fds[0] read descriptor, fds[1] write descriptor
	
	if(fork()>0){
		char msg[256];
		while(memset(msg,0,sizeof(msg)),read(0,msg,256)!=0){
			write(fds[1],msg,strlen(msg));
		}
		close(fds[0]);
		close(fds[1]);
		printf("wait....\n");
		wait(NULL);
		printf("wait over\n");
	}else{
		char buf[256];
		close(fds[1]);
		while(memset(buf,0,sizeof(buf)),read(fds[0],buf,256)){
			printf("from parent: %s\n",buf);
		}
		close(fds[0]);
	}
	
	return 0;
}
