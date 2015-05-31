/*************************************************************************
	> File Name: bellman_ford.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun May 24 11:28:52 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define inf 99999999

#define vertex 5
#define edge 6

int main(){
	int dis[vertex]={
		0,inf,inf,inf,inf
	};
	int bak[vertex];
	int u[edge],v[edge],w[edge];
	int i,
		k,
		check = 0,
		flag = 0,
		count = 0; 
	for(i = 0 ;i<edge;i++){
		scanf("%d %d %d\n",&u[i],&v[i],&w[i]);
	}

	// test if data is received correctly
	for(i = 0 ; i<edge;i++){
		printf("%d %d %d\n",u[i],v[i],w[i]);
	}
	//
	
	for(k = 0 ;k<vertex-1;k++){   // relax at most vertex-1 time
		count ++;
		/* check = 0; */
		/* for(i = 0 ;i<vertex ;i++){ */
			/* bak[i] = dis[i]; */
		/* } */
		for(i = 0 ;i<edge;i++){
			if(dis[v[i]] > dis[u[i]] + w[i]){ 
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}
		
		/* for(i = 0;i<vertex;i++){ */
			/* if(bak[i] != dis[i]){ */
				/* check = 1; */
				/* break; */
			/* } */
		/* } */
		/* if(check == 0){ */
			/* break; */
		/* } */
	}
	for(i = 0 ; i< edge ;i++){   // test if have negative circle
		if(dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;
	}
	if(flag == 1){
		printf("Have circle\n");
	}
	else{
		printf("No circle\n");
	
		for(i = 0 ; i< vertex;i++){
			printf("%d ",dis[i]);
		}
	}

	printf("\ncount = %d \n",count);

	return 0;
}
