/*************************************************************************
	> File Name: two_point.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 19:11:41 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void tarver(char (*test)[size_y],int size_x){
	int i;
	for(i = 0; i < size_x ; i++){
		printf("%s\n",test[size_x]);
	}
}


int main(){
	int size_x,size_y;
	int index_i, index_j;
	scanf("%d%d",&size_x,&size_y);
	char test[size_x][size_y];
	for(index_i = 0 ;index_i < size_x;index_i ++){
		fgets(test[index_i],size_y-1,stdin);
	}

	traver(test);

	return 0;
}
