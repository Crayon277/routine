/*************************************************************************
	> File Name: tiny_server.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Sep  4 06:42:47 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/uio.h>

#define SIZE 256

int main(int argc,char*argv[]){
	int fdget[2];
	int fdset[2];

	pipe(fdget);
	pipe(fdset);

	if(fork()>0){
		close(fdget[0]);
		close(fdset[1]);
		char pwd[SIZE];
		memset(pwd,0,SIZE);
		read(0,pwd,SIZE);
		write(fdget[1],pwd,SIZE);
		memset(pwd,0,SIZE);
		read(fdset[0],pwd,SIZE);
		printf("get %s from server\n",pwd);
		close(fdget[1]);
		close(fdset[1]);
		printf("client out\n");
	}else{
		close(fdget[1]);
		close(fdset[0]);
		char buf[SIZE];
		memset(buf,0,SIZE);
		read(fdget[0],buf,SIZE);
		if(strlen(buf)>10){
			write(fdset[1],"ok,login",20);
		}else{
			write(fdset[1],"sorry,off",30);
		}

		close(fdget[0]);
		close(fdset[1]);

		printf("server out\n");
	}
	return 0;
}
