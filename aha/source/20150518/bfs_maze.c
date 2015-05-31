/*************************************************************************
	> File Name: bfs_maze.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 08:42:32 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 5
#define MARGIN_Y 4
#define DES_X 3
#define DES_Y 2
typedef struct coordinate{
	int x;
	int y;
	int step;
}coordinate,*pcoordinate;



int main(){
	coordinate que[2048];//big enough to contain all the element
	int record[100];
	int head = 0,tail = 1,index_re = 0;
	int book[MARGIN_X][MARGIN_Y] = {0};		
	que[head].x = 0;
	que[head].y = 0;
	que[head].step = 0;
	book[0][0] = 1;
	int next[4][2] = {
		{
			0,1
		},
		{
			1,0
		},
		{
			0,-1
		},
		{
			-1,0
		}

	};
	int maze[MARGIN_X][MARGIN_Y] = {
		0,0,1,0,
		0,0,0,0,
		0,0,1,0,
		0,1,0,0,
		0,0,0,1
	};
	int N_x,N_y;
	int k,flag = 1;
	int index_traver = 0;
	while(head != tail){
		if(que[head].x == DES_X && que[head].y == DES_Y){
			record[index_re++] = que[head].step;
			flag = 0;	
		}
		if(flag){	
			for(k = 0; k<=3;k++){
				N_x = que[head].x + next[k][0];
				N_y = que[head].y + next[k][1];
				if(N_x < 0 || N_y < 0 || N_x > MARGIN_X || N_y > MARGIN_Y){
					continue;
				}
				if(book[N_x][N_y] == 1 || maze[N_x][N_y] == 1){
					continue;
				}
				que[tail].x = N_x;
				que[tail].y = N_y;
				que[tail].step = que[head].step+1;
				book[N_x][N_y] = 1;
				tail ++;
			}
		}
		//current coordinate finish
		head++; // pop the current coordinate
		flag = 1;
	}
	for(index_traver = 0 ; index_re!= index_traver ; index_traver++ ){
		printf("%d \n",record[index_traver]);
	}
//	printf("(%d,%d) step is %d\n",que[head].x , que[head].y ,que[head].step);
	return 0;
}
