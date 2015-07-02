/*************************************************************************
	> File Name: subset_bit.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 25 21:35:14 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void print_sub(int n,int cur){
	int i;
	for(i=0;i<n;i++){
		if(1<<i & cur){
			printf("%d ",i);
		}
	}
	printf("\n");
}

void bitsubset(int n){
	for(int i = 0 ;i<(1<<n) ;i++){
		print_sub(n,i);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	bitsubset(n);
	return 0;
}
