/*************************************************************************
	> File Name: test.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 23 12:12:08 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int e[3][3]={
		1,2,3,
		4,5,6,
		7,8,9
	};
	int book[3];
	book = e[0];

	int i;
	for(i = 0;i<3;i++){
		printf("%d ",book[i]);
	}
	return 0;
}
