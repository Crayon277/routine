/*************************************************************************
	> File Name: graphic_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 11:02:45 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int sum = 0;
int n;
int e[10][10];
int book[10];

void dfs(int cur){
	int i;
	printf("current is %d\n",cur);
	sum++;
	if(sum == n){
		return;
	}
	for(i = 0 ; i< n ;i++){
		if(e[cur][i] == 1 && book[i] == 0){
			book[i] = 1;
			dfs(i);
		}
	}
}

int main(){
	int que[10];
	int head = 0, tail = 1;
	que[head] = 0;
	scanf("%d",&n);	
	
	int i ,j,edge,a,b;
	for(i = 0 ;i < n ;i ++){
		for(j = 0 ;j<n; j++){
			if(i == j){
				e[i][j] = 0;
			}
			else{

			e[i][j] = 0x7fff;
			}
		}
	}	
	scanf("%d",&edge);
	for(i = 0 ; i<edge;i++){
		scanf("%d%d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1;
	}
	for(i = 0; i<n;i++){
		for(j = 0;j<n ;j++){
			if(0x7fff == e[i][j]){
				printf("  #");
			}
			else{
				printf("%3d",e[i][j]);
			}
		}
		printf("\n");
	}	
	printf("=======dfs========\n");
	book[0] = 1;
	dfs(0);
	printf("=======dfs end====\n");

	printf("=======bfs========\n");
	for(i = 0;i<n;i++){
		book[i] =0;
	}
	book[0] = 1;
	while(head != tail){
		printf("current %d\n",que[head]);
		for(i = 0 ;i<n;i++){
			if(e[que[head]][i] == 1&& book[i] == 0){
				book[i] = 1;
				que[tail++] = i;
			}
		}
		head++;
	}
	printf("=======bfs end====\n");

	return 0;
}
