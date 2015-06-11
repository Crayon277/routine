/*************************************************************************
	> File Name: enum_arrange.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun 10 21:41:03 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define MAX 256
int n;
int book[MAX],
	output[MAX];

void dfs(int step){
	int i;
	if(step == n+1){
		for(i = 1;i<=n;i++){
			if(1== i){
				printf("(%d,",output[i]);
			}
			else if(n == i){
				printf("%d)",output[i]);
			}else
				printf("%d,",output[i]);
		}
		printf("\n");
		return ;
	}
	
	for(i =  1; i<=n;i++){
		if(1 == book[i]){
			continue;
		}
		output[step] = i;
		book[i] = 1;
		dfs(step+1);
		book[i] = 0;
	}
}

int main(){
	//int n;
	scanf("%d",&n);
	dfs(1);	
	return 0;
}
