/*************************************************************************
	> File Name: cut.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 30 19:00:35 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TOTAL_VERTEX 7
#define TOTAL_EDGE 8 
int num[TOTAL_VERTEX+1],
	low[TOTAL_VERTEX+1],
	time_index;

typedef struct edge_node{
	int vertex;
	int edge_index;
	struct edge_node* link;
}EG;

typedef struct ver_node{
	int vertex;
	EG* link;
}VER;

int min(int a, int b){
	return a>b?b:a;
}

int dfs(int cur, int root, VER* graph){
	int i,child = 0,check,
		linked[TOTAL_VERTEX+1] = {
			0
		};

	EG * search = graph[cur].link;
	while(search!=NULL){
		linked[search->vertex] = 1;
		search = search->link;
	}
	time_index++;
	num[cur] = time_index;
	low[cur] = time_index;
	for( i = 1; i <= TOTAL_VERTEX ; i++){
		if(linked[i] == 1){
			if(num[i] == 0){
				child++;
				check = dfs(i,cur,graph);
				low[cur] = min(low[cur],low[i]);
			    if(low[i] >= num[cur] && num[cur] != 1){
					printf("%d is cut vertex\n",cur);
				}
				if(num[cur] == 1 && check == 0){
					printf("%d is cut vertex\n",cur);
				}	

			}
			else if(i != root){ // 不能经过父结点
				low[cur] = min(low[cur],num[i]);
			}
		}
	}
	return child;
}


int main(){
	//int first[TOTAL_VERTEX + 1], next[TOTAL_EDGE + 1];
	VER graph[TOTAL_VERTEX+1];
	memset(graph,0,sizeof(graph));
	
	FILE *fp = fopen("cut.txt","r");
	/* int u[TOTAL_EDGE + 1],v[TOTAL_EDGE + 1]	, index; */
	/* index = 1; */
	int u,v;
	while(fscanf(fp,"%d %d",&u,&v) != EOF){
		EG* new = (EG*)calloc(1,sizeof(EG));
		new->vertex = v;
		new->link = graph[u].link;
		graph[u].link = new;
		
		new = (EG*)calloc(1,sizeof(EG));
		new->vertex = u;
		new->link = graph[v].link;
		graph[v].link = new;

		//index ++;
	}	

	dfs(1,1,graph);

	return 0;

}
