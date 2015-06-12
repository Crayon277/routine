/*************************************************************************
	> File Name: queen8.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jun 12 09:28:44 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define size 8

int c[size];
int count = 0;
void queens(int (*queen)[size],int row){
	if(row == size){
		count ++;
		printf("==========count = %d=======\n",count);
		for(int i = 0 ; i < size; i++){
			for(int j = 0 ;j<size;j++){
				if(queen[i][j] == 1){
					printf("%3d",1);
				}else{
					printf("%3d",0);
				}
			}
			printf("\n");
		}
		printf("===========================\n\n");
	}
	/* printf("#1.running\n"); */
	for(int i = 0 ; i < size ;i++){
		int flag = 1;
		for(int j = 0 ; j<row;j++){
			if(i == c[j] || c[j] - j == i - row || j+c[j] == i+row ){
				flag = 0;
				break;
			}
		}
		if(flag){
			c[row] = i;
			queen[row][i] = 1;
			queens(queen,row+1);
			queen[row][i] = 0;
		}
	}
	/* printf("running\n"); */
}
int tot;
int vis[2][100];
void search(int cur){
	int i,j;
	if(cur == size){
		tot++;
	}
	else{
		for(i = 0; i < size; i++){
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+size]){
				c[cur] = i;
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+size] = 1;
				search(cur+1);
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+size] = 0;
			}
		}
	}
}

int main(){
	int queen[size][size] = {
		0
	};
	
	search(0);
	printf("%d\n",tot);
	//queens(queen,0);

	return 0;
}
