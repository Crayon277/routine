/*************************************************************************
	> File Name: testscanf.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Nov  1 12:04:38 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/*
 * 我想测试的是， scanf输入\n ，就是字符\,字符n，会不会自动停止。
 * 结果是没有，那她是怎么判断输入结束的？？
 */

int main(){
	char s;
	printf("I'm going to input \\n \n");
	scanf("this%c",&s);
	printf("%c\n",s);
	return 0;
}
