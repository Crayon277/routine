/*************************************************************************
	> File Name: subset.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 25 21:05:09 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define size 100

void print_subset(int n, int *arr, int cur){
	for(int i = 0 ; i<cur;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	int s = cur?arr[cur-1]+1:0;
	for(int i = s; i<n;i++){
		arr[cur] = i;
		print_subset(n,arr,cur+1);
	}
}

int main(){
	int n;
	int arr[size];
	scanf("%d",&n); // produce subset of 1~n
	print_subset(n,arr,0);
	return 0;
}
