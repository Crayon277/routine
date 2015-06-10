/*************************************************************************
	> File Name: topologicalsort.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  9 14:37:21 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main(){
	int degree[MAX] = {
		0
	},
		book[MAX] = {
			0
		},
		first[MAX],
		next[MAX],
		u[MAX],
		v[MAX];
	int n,m,i,count = 0;

	scanf("%d %d",&n,&m);
	for(i = 1; i<= n;i++){
		first[i] = -1;
	}
	for(i = 1 ; i<=m ; i++){
		scanf("%d %d",&u[i],&v[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
		degree[v[i]] ++;
	}
	
	while(count < n){
		for(i = 1; i<=n;i++){
			if(0 == book[i] && 0 == degree[i]){
				count ++;
				if(count <n){
					printf("%d<",i);
				}else{
					printf("%d",i);
				}
				book[i] = 1;
				int k = first[i];
				while(k!=-1){
					degree[v[k]]--;
					k = next[k];
				}
			}
		}
	}
	printf("\n");
	return 0;

}
