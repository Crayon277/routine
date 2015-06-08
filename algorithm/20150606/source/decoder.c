/*************************************************************************
	> File Name: decoder.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 23:26:41 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	char ch;
	while((ch = getchar()) != EOF){
		if(ch != 10){
			putchar(ch-7);
		}else{
			printf("\n");
		}
	}
	return 0;
}
