/*************************************************************************
	> File Name: change_val.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 08:33:13 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b;

	scanf("%d %d",&a,&b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n",a,b);
	
	//====bitwise operation=====
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("%d %d\n",a,b);

	return 0;
}
