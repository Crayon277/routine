/*************************************************************************
	> File Name: 3_1.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 08:44:48 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int array[101];
	int n = 0;
	while(scanf("%d",&array[n]) != EOF){
		n++;
	}
	n--;
	while(n>=0){
		printf("%d ",array[n]); // 竞赛中一般要求行首行尾没有空格，所以最后一个要分开写
		n--;
	}
	printf("\n");

	return 0;
}
