/*************************************************************************
	> File Name: pointeradd.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Oct 27 21:39:18 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[5] = {1,9,3,4,5};
	int (*p)= &a;
	printf("%p: %d\n%p: %d\n",p,*p,p+1,*(p+1));
	return 0;
}
