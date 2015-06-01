/*************************************************************************
	> File Name: daffodil.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 15:23:41 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;

	for(i = 100; i<=999; i++){
		int a = i / 100 ;
		int b = i / 10 % 10;
		int c = i % 10;
		/* printf("%d %d %d\n",a,b,c); */
		if(i == a*a*a + b*b*b + c*c*c){
			printf("%d is daffodil\n",i);
		}
	}

	return 0;
}
