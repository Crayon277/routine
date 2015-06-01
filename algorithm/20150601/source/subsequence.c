/*************************************************************************
	> File Name: subsequence.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 16:15:21 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,m,i;
	double sum,fraction;
	scanf("%d %d",&n,&m);
	sum = 0;
	for(i = n; i<=m ;i++){
		fraction = (double)1/i/i; // careful of overflow!!! can't do this: 1/(i*i)
		sum += fraction;
	}	
	printf("%.5lf\n",sum);

	return 0;
}
