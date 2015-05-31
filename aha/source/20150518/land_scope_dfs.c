/*************************************************************************
	> File Name: land_scope_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 20:58:54 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 10
#define MARGIN_Y 10

int SCOPE,book[MARGIN_X][MARGIN_Y];

void dfs(int x, int y, int (*land)[MARGIN_Y],int color){
	int next[4][2] = {
		0,1,1,0,0,-1,-1,0
	};

	int k,
		N_x,
		N_y;

	for(k = 0 ;k <= 3; k++){
		N_x = x + next[k][0];
		N_y = y + next[k][1];
		
		if(N_x < 0 || N_y < 0 || N_x > MARGIN_X || N_y > MARGIN_Y){
			continue;
		}
		if(book[N_x][N_y] == 0 && land[N_x][N_y] != 0){
			SCOPE ++;
			book[N_x][N_y] = 1;
			land[N_x][N_y] = color;
			dfs(N_x,N_y,land,color);
		}
	}
}

int main(int argc, char **argv){
	int land[MARGIN_X][MARGIN_Y] ;
	
	int head = 0,
		tail = 1;
	int index_i,index_j;
	FILE * fp = fopen(argv[1],"r");

	for(index_i = 0 ;index_i < MARGIN_X ;index_i++){
		for(index_j = 0 ;index_j < MARGIN_Y;index_j ++){
			fscanf(fp,"%d",&land[index_i][index_j]);
		}
	}
	book[6][8] = 1;
	SCOPE++;
	dfs(6,8,land,-1);
	printf("%d\n",SCOPE);

	for(index_i = 0; index_i < MARGIN_X; index_i ++){
		for(index_j = 0; index_j < MARGIN_Y; index_j ++){
			printf("%3d",land[index_i][index_j]);
		}
		printf("\n");
	}
	return 0;
}
