/*************************************************************************
	> File Name: addr_save.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon May 25 20:56:21 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int global_value;
static int i_static_value;

void func_1(int arg){
	int value_func1;
	static int i_static_value_func1;
	printf("string literal in func_1 is ... %p\n","abc");
	printf("arg in func_1 is ... %p\n",&arg);
	printf("value in func1 is ... %p\n",&value_func1);
	printf("static value in func1 is ... %p\n",&i_static_value_func1);
}

int main(int argc,char **argv){
	int *p;
	int array[100];
	p = (int*)malloc(sizeof(int));
	printf("argv in main ... %p\t%p\n",argv[0],argv[1]);
	printf("string literal in main ... %p\n","abc");	
	printf("malloc value in main ... %p\n",p);
	printf("array in main... %p\n",array);
	printf("global_value ... %p\n",&global_value);
	printf("static global_value ... %p\n",&i_static_value);
	func_1(1);

	return 0;
}
