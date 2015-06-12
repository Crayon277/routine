/*************************************************************************
	> File Name: subset_bit.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 11 21:10:41 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


void print_subset(int n,int s){
	for(int i = 0;i<n;i++){
		if(s&(1<<i)){
			printf("%d ",i);
		}
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);

	for(int i = 0 ; i<(1<<n);i++){
		print_subset(n,i);
	}

	return 0;
}
