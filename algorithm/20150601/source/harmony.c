/*************************************************************************
	> File Name: harmony.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 16:05:47 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,n;
	double sum,fraction;
	scanf("%d",&n);
	sum = 0;
	for(i = 1; i<=n ;i++){
		fraction = (double)1/i;
		sum += fraction;
	}
	printf("%.3lf\n",sum);

	return 0;
}
