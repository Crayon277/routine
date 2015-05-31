/*************************************************************************
	> File Name: land_scope.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 20:34:09 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 10
#define MARGIN_Y 10


struct coordinate{
	int x;
	int y;
};

int main(int argc,char **argv){
	int land[51][51];
	int book[MARGIN_X][MARGIN_Y] = {
		0
	};
	int next[4][2] = {
		0,1,1,0,0,-1,-1,0
	};
	int index_i,
		index_j,
		head = 0,
		tail = 1,
		N_x ,
		N_y,
		SCOPE = 0;

	struct coordinate BFS[256];
	BFS[head].x = 6;
	BFS[head].y = 8;
	book[6][8] = 1;
	SCOPE ++;
	FILE * fp = fopen(argv[1],"r");

	for(index_i = 0 ;index_i < MARGIN_X ;index_i++ ){
		for(index_j = 0 ;index_j< MARGIN_Y; index_j++){
			fscanf(fp,"%d",&land[index_i][index_j]);
		}
	}
	
	while(head < tail){
		for(index_i = 0 ;index_i <= 3 ;index_i ++){
			N_x = BFS[head].x + next[index_i][0];
			N_y = BFS[head].y + next[index_i][1];

			if(N_x < 0 || N_y < 0 || N_x > MARGIN_X || N_y > MARGIN_Y){
				continue;
			}
			if(land[N_x][N_y] != 0 && book[N_x][N_y] == 0){
				SCOPE++;
				book[N_x][N_y] = 1;
				BFS[tail].x = N_x;
				BFS[tail].y = N_y;
				tail++;
			}
		}
		head++;
	}
	printf("Land has %d\n",SCOPE);
	return 0;

}
