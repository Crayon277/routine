/************************************************************************
	> File Name: talk_f_s.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 19 22:00:40 2016
 ************************************************************************/

/*
 * 这个程序实现的是父子进程的单向传输信息，一次
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define nbyte 10  //为了测试是读发的边界问题

int main(int argc,char *argv[]){
	/* pid_t son; */
	int fds[2];

	if(pipe(fds) == -1){
		exit(1);
	}

	if(fork()>0){
		close(fds[0]);
		char send[nbyte];
		printf("this is father %d\n",getpid());		
		while(read(0,send,nbyte)){

			write(fds[1],send,nbyte);
		}//0是标准输入的描述符，意思是从标准输入中读nbyte个字符到send字符数组中去
		/* close(fds[1]);	 */

		printf("father leaving....\n");
	}else{
		close(fds[1]);
		char rece[nbyte];
		while(read(fds[0],rece,nbyte)){
			printf("from father %d : %s\n",getppid(),rece);
		}
		/* close(fds[0]); */
		printf("son leaving...\n");
	}

	close(fds[1]);
	close(fds[0]);
	return 0;
}
