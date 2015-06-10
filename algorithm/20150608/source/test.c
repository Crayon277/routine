/*************************************************************************
	> File Name: test.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  8 09:43:43 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int d;
	char s[10];
	scanf("%s",s);
	sscanf(&s[1],"%d",&d);
	printf("%d\n",d);
	return 0;
}
