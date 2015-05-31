/*************************************************************************
	> File Name: common_divisor.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu May  7 08:43:03 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int common_divisor(int a,int b){

	int n = a % b;
	if (n == 0){
		return b;
	}else{
		return common_divisor(b,n);
	}
}

int main(){
	//int a,b;
	int cd;
	cd = common_divisor(153,123);
	printf("The common divisor of 153 and 123 is %d\n",cd);
	return 0;
}
