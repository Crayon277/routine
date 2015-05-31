/*************************************************************************
	> File Name: vmtest.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue 05 May 2015 09:11:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int hoge;
	char buf[256];

	printf("&hoge ... %p\n",&hoge);
	printf("Input initial value. \n");

	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%d",&hoge);

	for(;;){
		printf("hoge .. %d\n",hoge);
		getchar();
		hoge++;
	}
	return 0;
}

