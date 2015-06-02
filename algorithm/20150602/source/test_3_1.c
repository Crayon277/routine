/*************************************************************************
	> File Name: test_3_1.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 09:20:42 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define size 10000000

int main(){
	int a[size]; // It will cause segment fault
	int i = 0;
	for(i = 0 ; i< size; i++){
		a[i] = i;
	}
	for(i = 0;i<size;i++)
		printf("%d\n",a[i]);

	return 0;
}


