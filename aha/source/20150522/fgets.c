/*************************************************************************
	> File Name: fgets.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 21:07:31 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int hoge;
	char buf[10];
	
	printf("&hoge ...%p\n",&hoge);
	printf("Input initial value.\n");
	fgets(buf,sizeof(buf),stdin);
	sscanf(buf,"%d",&hoge);

	for(;;){
		char c;
		printf("hoge.%d",hoge);

		c=getchar();

		hoge++;
	}

	return 0;
}
