/*************************************************************************
	> File Name: snake.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Apr 25 21:31:04 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define LEN 3
int main(){
	int a[LEN][LEN] = {
		0
	};
	
	int index_i = LEN >> 1,
		index_j = index_i,
		cnt = 1;
	
	if(LEN %2 == 0){
		index_j --;
	}
	
	a[index_i][index_j] = cnt++;

	while(cnt != LEN * LEN && (++index_i) != LEN){
		a[index_i][index_j] = cnt++;
	}
	index_i --;
	while(cnt != LEN * LEN && (--index_j)!= -1){
		a[index_i][index_j] = cnt++;
	}

	++index_j;
	while(cnt != LEN * LEN && (--index_i) != -1){
		a[index_i][index_j] = cnt++;
	}
	++index_i;
	while(cnt != LEN *LEN && (++index_j) != LEN ){
		a[index_i][index_j] = cnt ++;
	}
	--index_j;
	while(cnt != LEN * LEN && (++index_i) != LEN){
		a[index_i][index_j] = cnt ++;
	}
	a[++index_i][index_j] = cnt;

	for(index_i = 0 ;index_i != LEN ; index_i ++){
		for(index_j = 0 ;index_j != LEN ; index_j ++){
			printf("%d ",a[index_i][index_j]);
		}
		printf("\n");
	}

	return 0;


}
