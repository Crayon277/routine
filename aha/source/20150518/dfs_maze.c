/*************************************************************************
	> File Name: dfs_maze.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed May 20 22:00:38 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 5
#define MARGIN_Y 4

typedef struct node{
	int x;
	int y;
	int step;
}coordinate;

int maze[MARGIN_X][MARGIN_Y] = {
	0,0,1,0,
	0,0,0,0,
	0,0,1,0,
	0,1,0,0,
	0,0,0,1
};

int book[MARGIN_X][MARGIN_Y];
coordinate stack[100];
coordinate min_path[100];
int top = 0;
int des_x = 3,
	des_y = 2,
	min = 0x7fff;
int next[4][2] = {
	0,1,1,0,-1,0,0,-1
};
void dfs(int x, int y, int step){
	int n_x,n_y,k;
	if(x == des_x && y == des_y){
		if(min > step){
			min = step;
			for(k = 0 ; k!=top ; k++){
				min_path[k].x = stack[k].x;
				min_path[k].y = stack[k].y;
				min_path[k].step = stack[k].step;
		
			}
		}
		/* printf("====step is %d ======\n",step); */
		/* for(k = 0 ;k!= top; k++){ */
			/* printf("%d . (%d,%d)\n",stack[k].step,stack[k].x,stack[k].y); */
		/* } */
		/* printf("=====================\n"); */
	}
	for(k = 0 ; k<=3;k++){
		n_x = x + next[k][0];
		n_y = y + next[k][1];

		
		if(n_x < 0 || n_y < 0 || n_x >= MARGIN_X || n_y >= MARGIN_Y){
			continue;
		}
		if(book[n_x][n_y] == 0 && maze[n_x][n_y] != 1){
			book[n_x][n_y] = 1;
			stack[top].x = n_x;
			stack[top].y = n_y;
			stack[top].step = step+1;
			top++;
			dfs(n_x,n_y,step+1);
			book[n_x][n_y] = 0;
			top--;
		}
	}
}	

int main(){
	int i = 0;
	stack[top].x = 0;
	stack[top].y = 0;
	stack[top].step= 0;
	top++;
	book[0][0] = 1;

	dfs(0,0,0);
	while(min_path[i].step <= min){
		printf("%d .(%d,%d)\n",i,min_path[i].x,min_path[i].y);
		i++;
	}
	printf("%d\n",min);
}
