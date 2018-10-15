/*************************************************************************
	> File Name: mainpipe.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Nov 13 21:04:30 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<string.h>
#include<fcntl.h>
/*
 * 往pipe里面写数据的时候会把\n也一起写进去，
 * 可以用strlen(char *) 来计算出字符数组的字符长度，它是不包含\0的，注意处理\n
 * sizeof(char*)是包含\0的，可以理解为计算字符数组的数组长度。
 */

void client(int,int),server(int,int);

int main(int argc,char**argv){
	int pipe1[2],pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	
	if(fork() > 0){
		close(pipe2[0]);
		close(pipe1[1]);
		client(pipe1[0],pipe2[1]);
		wait(NULL);
		printf("bye\n");
	}else{
		close(pipe2[1]);
		close(pipe1[0]);
		server(pipe2[0],pipe1[1]);
		exit(0);	
	}

	return 0;

}


void client(int readfd,int writefd){
	char buf[256];
	memset(buf,0,sizeof(buf));
	read(0,buf,256);
	write(writefd,buf,256);
	/* memset(buf,0,sizeof(buf)); */
	/* read(readfd,buf,256); */
	/* printf("%s",buf); */
	while(memset(buf,0,sizeof(buf)),read(readfd,buf,256)>0){
		printf("%s",buf);
		printf("zus\n");
	}

}

void server(int readfd,int writefd){
	char buf[256];
	memset(buf,0,sizeof(buf));
	read(readfd,buf,256);
	buf[strlen(buf)-1] = '\0';
	/* FILE* fp = fopen(buf,"r"); */
	/* fscanf(fp,"%s",buf); */
	/* printf("kaka\n"); */
	/* while(memset(buf,0,sizeof(buf)),fread(buf,256,1,fp)){ */
		/* printf("1\n"); */
		/* if(feof(fp)){ */
			/* break; */
		/* } */
		/* printf("2\n"); */
		/* write(writefd,buf,256); */
		/* printf("dddd\n"); */
	/* } */
	/* fclose(fp); */
	printf("%s\n",buf);
	int fd = open(buf,O_RDONLY);
	memset(buf,0,sizeof(buf));
	while(read(fd,buf,256)>0){
		write(writefd,buf,256);
		memset(buf,0,sizeof(buf));
		printf("kaka\n");
	}
	close(fd);
}

/*
 * fread(void*restrict ptr,size_t size,size_t nitems, FILE * restrict stream);
 * nitems意思就是从stream中读nitems个size那么长的.
 * 那相当于读取nitems*size 那么长的字符串进来么。
 */


