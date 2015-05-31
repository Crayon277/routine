/*************************************************************************
	> File Name: prim.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu May 28 09:07:41 2015
 ************************************************************************/

#include"prim.h"

int main(){
	//init
	//use struct to save edge info
	distance dis[total_vertex + 1];
	ADLIST* adjacency_list = (ADLIST*)calloc(1,sizeof(ADLIST));		
	int	v1,
		v2,
		w,
		count = 0,
		vertex,
		sum = 0,
		index;
	FILE *fp = fopen("prim_test.txt","r");
	
	//init stuff
	
	for(index = 1; index <= total_vertex; index++){
		dis[index].v = 0;
		dis[index].w = inf;
		dis[index].book = 0;
	}
	//
	while(fscanf(fp,"%d %d %d",&v1,&v2,&w) != EOF){
		insert_adjacency(adjacency_list,v1,v2,w);
	}
	fclose(fp);

	//add vertex until it have n-1 edges in set which contains only one vertex at first place.
	vertex = 1;
	dis[1].v = 0;
	dis[1].w = 0;
	dis[1].book = 1;	
	while(count != total_vertex-1){  // Also, use book is fine
		// select vertex which most close to the spanning tree, not just individual vertex.
		maintenance(dis,vertex,adjacency_list);
		vertex = select_min(dis);
		dis[vertex].book = 1;
		printf("%d %d %d\n",dis[vertex].v,vertex,dis[vertex].w);
		count ++;
	}
	
	return 0;

}
