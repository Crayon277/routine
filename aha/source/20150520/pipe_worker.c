/*************************************************************************
	> File Name: pipe_worker.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed May 20 08:38:06 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 5
#define MARGIN_Y 4

int book[MARGIN_X][MARGIN_Y];
int puzzle[MARGIN_X][MARGIN_Y] = {
	5,3,5,3,
	1,5,3,0,
	2,3,5,1,
	6,1,1,5,
	1,5,5,4
};

typedef struct node{
	int x;
	int y;
}stack;
stack path[50];
int top;
void dfs(int x, int y, int infall){
	int i;
	
	if(x == MARGIN_X -1 && y == MARGIN_Y){
		printf("Found the way");
		for(i = 0 ;i!= top; i++){
			printf("(%d,%d) ",path[i].x,path[i].y);
		}
	}


	if(puzzle[x][y] ==0 || x<0 || y<0 || x>= MARGIN_X || y >= MARGIN_Y || book[x][y] == 1){
		return;
	}
	path[top].x = x;
	path[top].y = y;
	top++;
	book[x][y] = 1;
	if(puzzle[x][y] == 5 || puzzle[x][y] == 6){
		if(infall == 1){
			dfs(x,y+1,1);
		}
		if(infall == 2){
			dfs(x+1,y,2);
		}
		if(infall == 3){
			dfs(x,y-1,3);
		}
		if(infall == 4){
			dfs(x-1,y,4);
		}
	}
	else{
		if(infall == 1){
			dfs(x-1,y,4);
			dfs(x+1,y,2);
		}
		if(infall == 2){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
		if(infall == 3){
			dfs(x-1,y,4);
			dfs(x+1,y,2);
		}
		if(infall == 4){
			dfs(x,y+1,1);
			dfs(x,y-1,3);
		}
	}
	book[x][y] = 0;
	top --;
}

int main(){
	dfs(0,0,1);

	return 0;
}
