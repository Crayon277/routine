/*************************************************************************
	> File Name: anonymous_pipe.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Sep  3 20:14:58 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/uio.h>


int main(int argc,char* argv[]){
	int fds[2];

	pipe(fds);
	// after fork(), if pipe() will duplicate????
	// that means if there is two pipe 
	// but from result , it won't copy, otherwise, the message won't be able to send correctly,
	// coz there're two pipe, it's ambiguous!!

	if(fork()>0){// father read msg from standard input and sent it to son
		char msg[256];
		printf("father fds[0]:%x\nfather fds[1]:%x",fds[0],fds[1]);
		close(fds[0]);
		while(memset(msg,0,sizeof(msg)),read(0,msg,sizeof(msg))){
			printf("father sending....\n");
			write(fds[1],msg,sizeof(msg));
		}
		close(fds[1]);
		printf("waiting....\n");
		wait(NULL);
		printf("wait over\n");
	}else{
		char buf[256];
		printf("son fds[0]:%x\nson fds[1]:%x",fds[0],fds[1]);
		close(fds[1]);
		while(memset(buf,0,sizeof(buf)),read(fds[0],buf,sizeof(buf))){
			printf("from parent:%s\n",buf);
		}
		close(fds[0]);
	}

	return 0;
}
