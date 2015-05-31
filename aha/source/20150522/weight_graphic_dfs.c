/*************************************************************************
	> File Name: weight_graphic_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 16:52:01 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define des 5
#define citys 5
int e[5][5]={
	0,2,-1,-1,10,
	-1,0,3,-1,7,
	4,-1,0,4,-1,
	-1,-1,-1,0,5,
	-1,-1,3,-1,0
},
	book[10],
	min = 0x7fff,
	stack[10],
	top = 0;

void dfs(int cur){
	int i = 0;
	if(cur == des-1){
		int sum = 0;
		while(i != top-1){
			sum+=e[stack[i]][stack[i+1]];
			i ++;
		}
		if(sum < min){
			min = sum;
		}
		
		for(i = 0 ; i!= top ; i++)
			printf("%d ",stack[i]);
		printf("\tstep is %d\n",sum);
		return;
	}
	for(i = 0;i<citys;i++){
		if(e[cur][i] > 0 && book[i] == 0){
			book[i] =1;
			stack[top++] = i;
			dfs(i);
			book[i]= 0;
			top--;
		}
	}
}

int main(){
	int test = 0x7fffffffff;
	printf("%d\n",test);
	book[0] =1;
	stack[top++] = 0;	
	dfs(0);
	printf("min is %d\n",min);

	return 0;
}
