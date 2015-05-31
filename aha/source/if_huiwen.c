/*************************************************************************
	> File Name: if_huiwen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 27 09:52:28 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char * stack,int* top,char c){
	if(*top == 9){
		printf("full\n");
	}
	stack[*top] = c;
	(*top) ++;
}



int main(){
	char test[10];
	char stack[10];
	int top = 0;
	int len,index_t;
	while(memset(test,0,10),scanf("%9s",test)!=EOF){
		len = strlen(test);
		index_t = 0; top = 0;
		while(index_t < len / 2){
			push(stack,&top,test[index_t]);
			index_t ++;
		}
		if(len % 2 != 0){
			index_t++;
		}
		for(top--;top>=0 ;top--){
			if(test[index_t] != stack[top]){
				printf("It's not huiwen\n");
				break;
			}
			index_t++;
		}
		if(top == -1){
			printf("It's huiwen\n");
		}
	}
	return 0;
}
