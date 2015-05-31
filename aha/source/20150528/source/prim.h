/*************************************************************************
	> File Name: prim.h
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu May 28 09:07:56 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define total_vertex 6
#define inf 99999999
typedef struct distance{
	int v;
	int w;
	int book;
}distance;


typedef struct e{
	int ver;
	int weight;
	struct e * link;
}EG;

typedef struct v{
	int ver;
	EG * link; 	
}VER;

typedef struct ad{
	VER node[total_vertex + 1];
}ADLIST;
void insert_adjacency(ADLIST * adlist, int v1, int v2, int w);

void maintenance(distance * dis, int vertex,ADLIST * adlist);

int select_min(distance *dis);
