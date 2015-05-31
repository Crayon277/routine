/*************************************************************************
	> File Name: dijkstra.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 23 09:52:23 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define inf 99999999

int main(){
	int e[6][6] = {
		0,1,12,inf,inf,inf,
		inf,0,9,3,inf,inf,
		inf,inf,0,inf,5,inf,
		inf,inf,4,0,13,15,
		inf,inf,inf,inf,0,4,
		inf,inf,inf,inf,inf,0
	};
	int start;//start with zero!!!
	int dis[6];
	int book[6]= {
		0
	};
	
	while(scanf("%d",&start) != EOF){
		int i,
			next,
			set;
		for(i = 0 ;i < 6 ;i++){
			book[i] = 0;
		}
		book[start] = 1;
		set = 1;
		for(i = 0 ;i < 6;i++){
			dis[i] = e[start][i];
		}		
		
		while(set <= 5){
			next = 0;

			for(i = 0 ; i < 6 ; i++){
				if(book[next] == 1){
					next = i+ 1;
				}
				else if(dis[next] > dis[i] && book[i] == 0){
					next = i;
				}
			}
			book[next] = 1;
			set ++;
			for(i = 0;i<6;i++){
				if(e[next][i] < inf ){
					if(book[i] == 0 && dis[i] > e[next][i] + dis[next]){
						dis[i] = e[next][i] + dis[next];
					}
				}
			}
		}
		for(i = 0 ; i<6 ;i ++){
			printf("%d ",dis[i]);
		}
		printf("\n");
	}
	return 0;
}
