/*************************************************************************
	> File Name: bipartite.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 30 21:53:40 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define TOTAL_VERTEX 3
#define inf 99999999

int match[TOTAL_VERTEX*2 + 1];
int book[TOTAL_VERTEX+1];

int dfs(int cur, int (*graph)[TOTAL_VERTEX+1]){
	int i;
	for(i = 1; i<=TOTAL_VERTEX;i++){
		if(graph[cur][i] == 1 && book[i] == 0){
			book[i] = 1;
			if(match[i+3] == 0 || dfs(match[i+3],graph)){
				match[cur] = i+3;
				match[i+3] = cur; 
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int graph[TOTAL_VERTEX + 1][TOTAL_VERTEX + 1];
	int i,j;
	int current[TOTAL_VERTEX+1],stack[TOTAL_VERTEX],
		c_top = 0,s_top = 0,max = 0;
	FILE*fp = fopen("bipartite.txt","r");
	int u[TOTAL_VERTEX+1],v[TOTAL_VERTEX+1],index = 1;
	int sum = 0;
	for(i =1;i <= TOTAL_VERTEX; i++){
		for(j = 1; j<=TOTAL_VERTEX;j++){
			graph[i][j] = inf;
		}
	}


	while(fscanf(fp,"%d %d",&u[index],&v[index]) != EOF){
		graph[u[index]][v[index]] = 1;
		index++;		
	}
	
	
	for(i = 1 ; i <= TOTAL_VERTEX;i++){
		for(j=1;j<=TOTAL_VERTEX;j++){
			book[j]= 0;
		}
		if(dfs(i,graph)){
			sum++;
		}
	}

	printf("%d\n",sum);
	return 0;
}
