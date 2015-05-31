/*************************************************************************
	> File Name: diamond.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 20 14:08:22 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LEN 5

void diamond_solid(){
	//print above
	int index_i,index_j;
	for(index_i = 0; index_i != LEN; index_i ++){
		// print space
		index_j = LEN - index_i-1;
		while(index_j){
			printf(" ");
			index_j --;
		}
		//print star
		while(index_j != (index_i + 1)){
			printf("* ");
			index_j ++;
		}
		//new line
		printf("\n");
	}
	//print below
	for(index_i = LEN-1 ; index_i != 0 ;index_i --){
		index_j = LEN - index_i;
		while(index_j){
			printf(" ");
			index_j -- ;
		}
		//print star
		while(index_j != index_i){
			printf("* ");
			index_j ++;
		}
		//new line
		printf("\n");
	}
}

void diamond_hollow(){
	int index_i, index_j;

	for(index_i = LEN; index_i ;index_i --){
		for(index_j = 1; index_j < index_i ; index_j ++){
			printf(" ");
		}
		//the very left star
		printf("*");
		//print space between left star and right star
		/* for(index_j = 0 ; index_j != (LEN - index_i) ; index_j ++){ */
			/* printf(" "); */
		/* } */
		
		index_j = LEN - index_i;
		
		if(index_j){
			index_j = index_j*2 - 1;
			while(index_j){
				printf(" ");
				index_j --;
			}
			printf("*");		
		}		

		printf("\n");
		//the very right star & new line
		//printf("*\n");
	}

	//print below
	index_i = LEN - 1;
	while(index_i){
		index_j = LEN - index_i;
		while(index_j){
			printf(" ");
			index_j --;
		}
		printf("*");
		index_j = index_i - 1;
		if(index_j){
			index_j = 2*index_j - 1;
			while(index_j){
				printf(" ");
				index_j --;
			}
			printf("*");
		}
		printf("\n");
		index_i -- ;
	}
}


int main(){
//	diamond_solid();
	printf("=========\n");
	diamond_hollow();
	system("color 2B");	
	printf("hello world!\n");
	return 0;
}

