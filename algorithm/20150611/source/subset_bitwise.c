/*************************************************************************
	> File Name: subset_bitwise.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jun 12 08:47:15 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


void print_subset(int n, int cur){
	for(int i = 0;i<n;i++){
		if(cur&(1<<i)){
			printf("%d ",i+1);
		}
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ;i<(1<<n);i++){
		print_subset(n,i);
	}
	return 0;
}
