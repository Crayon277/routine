/*************************************************************************
	> File Name: point.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 20 17:19:04 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char* returnstr(){
	char* p = "hello world";
	
	printf("%p\n",p);
	printf("%p\n",&("hello world"));
	return p;
}

char* returnstr2(){
	static char p[] = "hello world!";
	printf("%p\n",p);
	printf("%p\n",&("hello world!"));
	return p;
}

int main(){
	char *str;
	str=returnstr();
	printf("%p\n",str);
	printf("%s\n",str);

	printf("==========\n");
		
	str=returnstr2();
	printf("%p\n",str);
	printf("%s\n",str);
	
	return 0;
}


