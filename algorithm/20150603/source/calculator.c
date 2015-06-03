/*************************************************************************
	> File Name: calculator.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 23:03:08 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 100

int main(){
	char expression[size];
	char op;
	int op1,op2;
	fgets(expression,size,stdin);
	printf("%s\n",expression);
	int i = strlen(expression)-1;
	int temp=0,weishu = 1;
	while(isspace(expression[i])){
		i--;
	}
	while(isdigit(expression[i])){
		temp = temp + (expression[i]-'0') * weishu;
		weishu *= 10;
		i--;
	}
	op1 = temp;
	printf("op1 :%d\n",op1);
	while(isspace(expression[i])){
		i--;
	}
	op = expression[i];
	i--;
	while(isspace(expression[i])){
		i--;
	}
	temp = 0;weishu = 1;
	while(isdigit(expression[i]) && i>=0){
		temp = temp + (expression[i]-'0')*weishu;
		weishu *= 10;
		i--;
	}
	op2 = temp;
	printf("op2 :%d\n",op2);
	switch(op){
		case '+':printf("%d + %d = %d\n",op2,op1,op1+op2);break;
		case '-':printf("%d - %d = %d\n",op2,op1,op2-op1);break;
		case '*':printf("%d * %d = %d\n",op2,op1,op2*op1);break;
		case '/':printf("%d / %d = %lf\n",op2,op1,(double)op2/op1);break;
	}

	return 0;
}
