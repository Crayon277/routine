/*************************************************************************
	> File Name: subset_index.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 25 21:55:34 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define size 100

void print_subset(int n, int *book,int cur){
	if(cur > n){	
	for(int i = 1 ; i <= cur ;i++){
		if(book[i]){
			printf("%d ",i);
		}
	}
	printf("\n");
	return ;
	}
	book[cur] = 1;
	print_subset(n,book,cur+1);
	book[cur] = 0;
	print_subset(n,book,cur+1);
}

int main(){
	int n;
	scanf("%d",&n);
	int book[size];
	print_subset(n,book,1);
	return 0;
}
