/*************************************************************************
	> File Name: enter.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 11:54:38 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b;
	while(scanf("%d%d\n",&a,&b)!=EOF){
		char ch = getchar();
		printf("ch = %x\n",ch);
		printf("%d+%d=%d %c",a,b,a+b,ch);
	}
	return 0;
}
