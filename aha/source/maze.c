/*************************************************************************
	> File Name: maze.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon May 18 14:32:42 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_x 5
#define MARGIN_y 4
#define des_x 3
#define des_y 2

int book[MARGIN_x][MARGIN_y],maze[MARGIN_x][MARGIN_y];
int next[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};
int min = 0x7fff;

void puzzel(int current_x,int current_y,int step){
	int N_x,N_y,k;
	if(current_x == des_x && current_y == des_y){
		if(step < min){
			min = step;
		}
		return;
	}

	for(k = 0; k <= 3 ;k++){
		N_x = current_x + next[k][0];
		N_y = current_y + next[k][1];

		if(N_x < 0 || N_y < 0 || N_x >= MARGIN_x || N_y >= MARGIN_y ){
			continue;
		}
		if(maze[N_x][N_y] == 1 || book[N_x][N_y] == 1){
			continue;
		}
		book[N_x][N_y] = 1;
		puzzel(N_x,N_y,step+1);
		book[N_x][N_y] = 0;
	}
}

int main(){
	int index_i, index_j;
	for(index_i = 0 ;index_i < MARGIN_x ;index_i ++){
		for(index_j = 0 ;index_j < MARGIN_y ; index_j ++){
			scanf("%d",&maze[index_i][index_j]);
		}
	}	
	puzzel(0,0,0);
	book[0][0] = 1;
	printf("Minium step is : %d\n",min);

	return 0;
}
