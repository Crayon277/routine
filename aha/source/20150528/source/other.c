/*************************************************************************
	> File Name: other.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu May 28 11:00:42 2015
 ************************************************************************/

#include"prim.h"


void insert_adjacency(ADLIST * adlist, int v1, int v2, int w){
	EG * new = (EG *)calloc(1,sizeof(EG));
	new->ver = v2;
	new->weight = w;
	new->link = adlist->node[v1].link;
	adlist->node[v1].link = new;

	new = (EG*)calloc(1,sizeof(EG));
	new->ver = v1;
	new->weight = w;
	new->link = adlist->node[v2].link;
	adlist->node[v2].link = new;
}

void maintenance(distance * dis, int vertex, ADLIST* adlist){
	int i;
	EG* search;
	for(i = 1; i <= total_vertex; i++){
		if(dis[i].book == 0){
			search = adlist->node[i].link;
			/* printf("%d:%d %d\n",i,search->ver,search->weight); */
			while(search != NULL){
				if(search->ver == vertex){
					break;
				}
				search = search->link;
			}
			if(search != NULL){
				if(dis[i].w > search->weight){
					dis[i].w = search->weight;
					dis[i].v = vertex;
				}
			}
		}
	}
}

int select_min(distance *dis){
	int min = inf,
		t = 0;
	int i;
	for(i = 1 ; i <= total_vertex; i++){
		if(dis[i].book == 0){
			if(dis[i].w < min){
				min = dis[i].w;
				t = i;	
			}
		}
	}
	return t;
}
