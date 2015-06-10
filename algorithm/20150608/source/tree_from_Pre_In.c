/*************************************************************************
	> File Name: tree_from_Pre_In.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  8 13:41:45 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 100

void post(int n, char*pre, char *in){
	if(n<=0){
		return;
	}
	int root = strchr(in,pre[0])-in;
	post(root,pre+1,in);//left
	post(n-root-1,pre+root+1,in+root+1);//right
	printf("%c ",pre[0]);//root
}

int main(){
	char pre[NUM],
		 in[NUM];
	scanf("%s %s",pre,in);
	int n = strlen(pre);
	post(n,pre,in);	
	printf("\n");
	return 0;
}
