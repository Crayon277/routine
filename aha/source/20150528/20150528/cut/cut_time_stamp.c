/*************************************************************************
	> File Name: cut_time_stamp.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May  8 02:54:20 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define n 8
#define m 9

int e[10][10],root;

int num[10],low[10],flag[10],index_me;

int min(int a, int b){
	return a< b ? a:b;
}

void dfs(int cur, int father){
	int child = 0, i, j;
	index_me ++;

	num[cur] = index_me;
	low[cur] = index_me;

	for(i = 1; i<= n ;i++){
		if(e[cur][i] == 1){
			if(num[i] == 0){
				child++;
				dfs(i,cur);
				low[cur] = min(low[cur],low[i]);
				if(cur != root && low[i] >= num[cur]){
					flag[cur] = 1;
				}
				if(cur == root && child == 2){
					flag[cur] = 1;
				}
			}
			else if(i != father){
				low[cur] = min(low[cur],low[i]);
			}
		}
	}
}

int main(){
	int i, j ,x, y;
	/* scanf("%d %d",&n,&m); */
	FILE *fp = fopen("cut_time.txt","r");
	for(i = 1; i <= n; i++){
		for(j = 1; j<= n; j++){
			e[i][j] = 0;
		}
	}
	
	for( i= 1; i<= m; i++){
		fscanf(fp,"%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	}

	root = 1;
	dfs(1,root);

	for(i = 1; i <= n; i++){
		if(flag[i] == 1){
			printf("%d is cut vertex\n",i);
		}
	}

	for(i = 1 ; i<= n; i++){
		printf("%d ",low[i]);
	}
	printf("\n");
	return 0;
}
