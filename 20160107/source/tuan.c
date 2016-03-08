/*************************************************************************
	> File Name: tuan.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 11:02:37 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


void tuan1(){
	int i,j;
	for(i=1;i<=4;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}

void tuan2(){
	int i,j;
	for(i=4;i>=1;i--){
		for(j=0;j<4-i;j++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}

void tuan3(){
	int i,j;
	for(i=1;i<=4;i++){
		for(j=0;j<4-i;j++){
			printf(" ");
		}
		for(j=1;j<=2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(){
	tuan1();
	printf("\n\n");
	tuan2();
	printf("\n\n");
	tuan3();
	printf("\n\n");
	return 0;
}
