/*************************************************************************
	> File Name: product.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 22:25:29 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 100
int main(){
	char input[size];
	int num[size],count = 0,index = 0,multi = 1;
	scanf("%s",input);
	int i = strlen(input) - 1;
	while(i>=0){
		int weishu = 1;
		int temp =0;
		int flag = 0;
		while(isdigit(input[i])){
			flag = 1;
			temp = temp + (input[i]-'0') * weishu;
			weishu *=10;
			i--;
		}
		if(flag){
			num[count++] = temp;
		}else{
			i--;
		}
	}
	for(index = 0 ;index < count ; index++){
		multi *= num[index];
		printf("%d\n",num[index]);
	}

	printf("%d\n",multi%1000);

	return 0;
}
