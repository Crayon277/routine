/*************************************************************************
	> File Name: testswith.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Nov  1 14:35:44 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/*
 * 测试看一下switch 把default放在最前面会不会先进入这个
 * 结果是：不会，还是先比较case去了。但是需要注意default 的 break. 如果没有这个break还是会往下顺序执行。
 */


int main(){
	int n = 3;
	switch(n){
		default:
			printf("this is default in the first place\n");
			break;
		case 1:
			printf("second\n");
			break;
		case 2:
			printf("third\n");
			break;
	}
	
	return 0;
}
