/*************************************************************************
	> File Name: anyTodec.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 08:13:35 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	int base;
	char num[100];
	scanf("%d %s",&base,num);
	
	int i,k = strlen(num) - 1;
	double decimal = 0;
	printf("%d\n",strlen(num));
	for(i = k;i>=0;i--){
		decimal = decimal + (num[i]-'0')*pow(base,k-i);
	}
	printf("%.lf\n",decimal);
	return 0;

}
