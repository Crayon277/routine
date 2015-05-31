/*************************************************************************
	> File Name: span_tree.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May  8 04:23:46 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define total_vertex 6
#define edge_num 9

#define SWAP(a,i,j) {int t; t = a[i] ; a[i] = a[j];a[j] = t; }

typedef struct edge_node{
	int vertex;
	int weight;
	int index;
	struct edge_node* link;
}EG;

typedef struct ver_node{
	int vertex;
	EG* link; 
}VER;

int flag ;
int book[total_vertex + 1];
void AdjustDown(int *a, int size, int start,int *w){
	int min ;

	while(start * 2 <= size){
		min = start;
		if(w[a[start]] > w[a[start * 2]]){
			min = start * 2; 
		}
		if( start*2 + 1 <= size){
			if(w[a[min]] > w[a[start*2 + 1]]){
				min = start*2 + 1;
			}
		}
		if(min != start){
			SWAP(a,min,start);
			start = min;
		}else{
			break;
		}

	}
}

void AdjustUp();

void create_min_heap(int *a, int size, int *w){
	int i;
	for(i = size/2 ; i>=1 ; i--){
		AdjustDown(a,size,i,w);
	}
}

void heap_sort(int *a,int size,int *w){
	while(size !=1 ){
		SWAP(a,1,size);
		size--;
		AdjustDown(a,size,1,w);
	}
}

void dfs_check(int start,int target,VER * graph,int edge_rid,int *rid){
	EG*search ;
	search = graph[start].link;
	
	if(start == target){
		flag = 1;
		return;
	}
	
	while(search != NULL && flag != 1){
		if(search->index != edge_rid && rid[search->index] == 0){
			if(book[search->vertex] == 0){
				book[search->vertex] = 1;
				dfs_check(search->vertex,target,graph,edge_rid,rid);
				book[search->vertex] = 0;
			}
		}
		search = search->link;
	}
}

int main(){
	//init
	/* int edge_num = 9; */
	/* scanf("%d",&edge_num); */
	int rid[edge_num + 1] = {
		0
	};
	int sort_array[edge_num + 1];
	/* int first[total_vertex + 1],next[edge_num + 1]; */
	VER graph[total_vertex + 1];
	memset(graph,0,sizeof(graph));
	int u[edge_num+1],v[edge_num+1],w[edge_num+1];

	int count = 1,
		edge_count = edge_num,
		top = 1, // get the largest path after sort
		index;

	/* for(count = 1; count <= total_vertex; count++){ */
		/* first[count] = -1; */
	/* } */
	for(index = 1; index <= edge_num ; index++){
		sort_array[index] = index;
	}

	//save graph
	FILE *fp = fopen("span.txt","r");
	count = 1;
	while(fscanf(fp,"%d %d %d",&u[count],&v[count],&w[count]) != EOF){
		/* next[count] = first[u[count]]; */
		/* first[u[count]] = count; */
		EG* new = (EG*)calloc(1,sizeof(EG));
		new->link = graph[u[count]].link;
		graph[u[count]].link = new;
		new->vertex = v[count];
		new->weight = w[count];
		new->index = count;

		new = (EG*)calloc(1,sizeof(EG));
		new->link = graph[v[count]].link;
		graph[v[count]].link = new;
		new->vertex = u[count];
		new->weight = w[count];
		new->index = count;

		count ++;
	}
	fclose(fp);
	//create minimum heap
	create_min_heap(sort_array,edge_num,w);	
	//heap sort , descending
	heap_sort(sort_array,edge_num,w);	


	//take the first in current place and check if graph getting splited until n-1 edges left
	while(edge_count != total_vertex-1 && top <= edge_num){
		//check 
		flag = 0; //表示这条边不能去
		memset(book,0,sizeof(book));
		book[u[sort_array[top]]] = 1;
		dfs_check(u[sort_array[top]],v[sort_array[top]],graph,sort_array[top],rid);
		if( flag == 1){
			rid[sort_array[top]] = 1;//表示这条边已经去掉了
			edge_count --;
		}
		//always do
		top++;
	}
	//print left edge
	for(index = 1; index <= edge_num ;index++){
		if(rid[index] != 1){
			printf("%d %d %d\n",u[index],v[index], w[index]);
		}
	}

	return 0;
}


