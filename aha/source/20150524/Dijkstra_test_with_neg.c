/*************************************************************************
	> File Name: Dijkstra_test_with_neg.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun May 24 10:00:36 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define inf 99999999

int main(){
	int book[3] = {
		1,0,0
	};
	int e[3][3] = {
		0,3,inf,
		inf,0,-6,
		2,inf,0
	};


	int dis[3];
	int i,
		k,
		min = inf,
		index;


	for(i = 0 ;i< 3 ;i++){
		dis[i] = e[0][i];
	}

	for(i=0;i<2;i++){
		min = inf;
		for(k = 0;k<3;k++){
			if(book[k] == 0 && min > dis[k]){
				min = dis[k];
				index = k;
			}
		}
		book[index] = 1;
		for(k = 0 ; k< 3;k++){
			if(book[k] ==  0 && dis[k] > dis[index] + e[index][k]){
				dis[k] = dis[index] + e[index][k];
			}
		}
	}

	for(i = 0 ;i< 3;i++){
		printf("%d ",dis[i]);
	}
	printf("\n");
	return 0;
}
