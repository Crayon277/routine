/*************************************************************************
	> File Name: euler.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  9 15:33:15 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define VER 4

int G[VER][VER] = {
	0,1,1,1,
	1,0,0,1,
	1,0,0,1,
	1,1,1,0
},
	vis[VER][VER] = {
	0
	};
void euler(int u){
	for(int v = 0;v<VER;v++){
		if(G[u][v] && ! vis[u][v]){
			vis[u][v] = vis[v][u] = 1;
			euler(v);
			printf("%d %d\n",u,v);
		}
	}
}

int main(){
	euler(0);
	return 0;

}
