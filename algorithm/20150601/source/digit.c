/*************************************************************************
	> File Name: digit.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 15:04:50 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int ival,count = 0;
	scanf("%d",&ival);

	while(ival != 0){
		count ++;
		ival /= 10; //ival /2 == ival >> 1
	}
	printf("%d\n",count);
}
