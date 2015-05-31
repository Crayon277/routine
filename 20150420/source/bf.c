/*************************************************************************
	> File Name: bf.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 20 15:56:19 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i = 5;
	
	while(i--){
		printf("%d\n",i);
	}
	printf("========\n");
	i = 5;
	while(i){
		printf("%d\n",i);
		i--;
	}

	return 0;
}
