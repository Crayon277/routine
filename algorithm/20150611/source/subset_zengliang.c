/*************************************************************************
	> File Name: subset_zengliang.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 11 15:56:40 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void print_set(int size,int *set,int cur){
	for(int i = 1; i<cur;i++){//决定了打印的个数，1，2，3？
		printf("%d ",set[i]);
	}
	printf("\n");
	int start = cur==1?1:set[cur-1] + 1;//第一个元素还是1，2，3遍历。
	for(int i = start; i<= size;i++){
		set[cur] = i;
		print_set(size,set,cur+1);
	}
}

int main(){
	int set[MAX];
	int n;
	scanf("%d",&n);

	print_set(n,set,1);

	return 0;
	
}
