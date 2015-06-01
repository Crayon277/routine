/*************************************************************************
	> File Name: reverse_digit.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 08:25:04 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int ival,ival_re;

	scanf("%d",&ival);
	ival_re = ival % 10 * 100+ ival /10 % 10 *10 + ival /100;
	printf("%d\n",ival_re);// printf("%03d\n",ival_re);
	return 0;
}
