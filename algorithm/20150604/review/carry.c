/*************************************************************************
	> File Name: carry.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 11:27:19 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 100

int main(){
	char op1[size],
		op2[size];
	while(memset(op1,0,sizeof(op1)),memset(op2,0,sizeof(op2)),scanf("%s %s",op1,op2)){
		int i = strlen(op1) - 1,
			j = strlen(op2) - 1;
		int flag = 0;
		int carry = 0;
		if(op1[0] == '0' && op2[0] == '0'){
			break;
		}
		while(i>=0 && j>=0){
			flag = ((op1[i] - '0') + (op2[j]-'0') + flag) >= 10 ? 1:0;
			carry+=flag;
			i--;j--;	
		}
		if(i>=0){
			carry += ((op1[i] - '0') + flag ) >=10?1:0;
		}
		if(j >= 0){
			carry+=((op2[j]-'0')+flag) >= 10?1:0;
		}

		printf("%d\n",carry);
	}
	return 0;
}
