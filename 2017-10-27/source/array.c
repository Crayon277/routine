/*************************************************************************
	> File Name: array.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Oct 27 21:04:11 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[3][4] = {
		{
			1,9,3,4
		},
		{
			4,5,6,7
		},
		{
			8,9,10,11
		}
	};
	
	/* int (*p) [4]; */
	int *p = a;	
	printf("%d\n",*(p+4*2+2));
	/* printf("%d",*(*a+1)); */
	return 0;
}
