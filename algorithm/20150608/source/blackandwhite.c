/*************************************************************************
	> File Name: blackandwhite.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  9 08:44:01 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
	int x;
	int y;
}coordinate;

int main(){
	int map[MAX][MAX],
	   	book[MAX][MAX],
		next[8][2] ={
			0,1,
			1,1,
			1,0,
			1,-1,
			0,-1,
			-1,-1,
			-1,0,
			-1,1
		},
		head = 0,
		tail = 0,
		count = 0;
	coordinate black[MAX],seq[MAX];
	int n,i,j;
	scanf("%d",&n);
	for(i = 0; i<n;i++){
		for(j = 0 ;j < n; j++){
			map[i][j] = 0;
			book[i][j] = 0;
		}
	}
	i = 0;
	while(scanf("%d%d",&black[i].x,&black[i].y) != EOF){
		map[black[i].x][black[i].y] = 1;
		i++;
	}

	for(j = 0 ;j<i;j++){
		head = 0 ;
		tail = 0;
		if(book[black[j].x][black[j].y] == 1){
			continue;
		}
		seq[tail].x = black[j].x;
		seq[tail].y = black[j].y;
		tail ++;
		book[black[j].x][black[j].y] = 1;
		while(head!=tail){
			int move;
			for(move = 0; move < 8;move ++){
				int n_x = seq[head].x + next[move][0];
				int n_y = seq[head].y + next[move][1];
				
				if(map[n_x][n_y] == 1 && book[n_x][n_y] == 0){
					seq[tail].x = n_x;
					seq[tail].y = n_y;
					tail ++;
					book[n_x][n_y] = 1;
				}

			}
			head++;
		}
		count++;
	}
	printf("%d\n",count);
	return 0;

