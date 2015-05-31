/*************************************************************************
	> File Name: diamond.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 20 16:30:42 2015
 ************************************************************************/

#include<iostream>
using namespace std;

void diamond(){
	int max_cnt,index_row,index_column;
	while(fflush(stdin),cin>>max_cnt){
		for(index_row = max_cnt ; index_row ; index_row --){
			for(index_column = 1; index_column < index_row ; index_column++){
				printf(" ");
			}

			for(;index_column <= 2*max_cnt - index_row ; index_column += 2){
				printf("* ");
			}
			printf("\n");
		}

		for(index_row = 1; index_row <= max_cnt - 1 ;index_row ++){
			for(index_column = 1; index_column <= index_row; index_column ++){
				printf(" ");
			}
			for(; index_column <= 2*max_cnt - index_row ;index_column += 2){
				printf("* ");
			}
			printf("\n");
		}
		printf("\n");
	}
}

int main(){
	diamond();
	return 0;
}
