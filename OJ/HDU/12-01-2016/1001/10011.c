/*************************************************************************
	> File Name: 10011.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jan 12 12:26:49 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	while(~scanf("%d",&n)){
		printf("%d\n\n",n&1?((n+1)/2*2):(n/2*(n+1)));
	}
	return 0;
}
