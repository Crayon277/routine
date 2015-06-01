/*************************************************************************
	> File Name: triangle.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 15:31:38 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int floor,base ,i,space;
	scanf("%d",&floor);
	
	space = 0;
	while(floor != 0){
		base = 2*floor - 1;
		for(i = 0; i<space;i++){
			printf(" ");
		}
		for(i = 0; i< base;i++){
			printf("#");
		}
		printf("\n");
		floor --;
		space++;
	}
	return 0;

}
