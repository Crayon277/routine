/*************************************************************************
	> File Name: floyd.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 23 09:00:54 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define inf 99999999

int main(){

	int e[4][4] = {
		0,2,6,4,
		inf,0,3,inf,
		7,inf,0,1,
		5,inf,12,0
	};

	int k,i,j;

	for(k = 0; k<4;k++){ // 表示加入顶点
		for(i = 0; i< 4;i++){//两个for循环表示任意两点
			for(j = 0 ;j<4;j++){
				if(e[i][j] > e[i][k] + e[k][j]){
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}


	for(i = 0 ; i< 4;i++){
		for(j = 0 ;j< 4 ; j++){
			printf("%3d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}
