/*************************************************************************
	> File Name: test_sizeofstrlen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jan 12 14:42:58 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s[] = "chenye";
	
	printf("sizeof %s is %d \nstrlen %s is %d\n",s,sizeof(s),s,strlen(s));
	return 0;
}
