/*************************************************************************
	> File Name: cut_vertex.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu May 28 20:02:37 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define total_vertex 6
/* #define inf 99999999 */
int count = 0;
int book[total_vertex];
void dfs(int (*e)[total_vertex],int candidate, int start){
	int i;
	book[start] = 1;
	count ++;
	for(i = 0; i< total_vertex; i++){
		if(i != candidate && e[start][i] == 1){
			dfs(e,candidate,i);
		}
	}
}


int main(){
	int e[total_vertex][total_vertex];
	/* int cut_select[total_vertex]; */
	FILE *fp = fopen("cut.txt","r");
	int i,
		j;
	for(i = 0; i<total_vertex; i++){
		for(j = 0 ; j < total_vertex; j++){
			e[i][j] = 0;
		}
	}

	while(fscanf(fp,"%d %d",&i,&j) != EOF){
		e[i][j] = 1;
		e[j][i] = 1;
	}

	for(i = 0 ; i < total_vertex; i++){
		/* cut_select[i] = 1; */
		for(j = 0;j < total_vertex;j++){
			if(i != j ){
				count = 0;
				memset(book,0,sizeof(book));
				dfs(e,i,j);
				if(count < total_vertex - 1){
					printf("%d is cut vertex\n",i);
					break;
				}
			}
		}
	}

	return 0;

}
