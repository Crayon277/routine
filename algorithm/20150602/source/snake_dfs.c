/*************************************************************************
	> File Name: snake_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 17:37:26 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define size 10

int a[size][size];
int count = 0;
typedef struct node{
	int index;
	int next_i;
	int next_j;
	struct node* link;
}move,*pmove;

void dfs(pmove p_move,int (*a)[size],int n,int i,int j){
	int x = i + p_move->next_i,
		y = j + p_move->next_j;
	if(count >= n*n || i > n-1 || j > n-1 || i < 0 || j < 0){
		//count >= n*n not just > n*n 
		return;
	}
	if(i <= n-1 && j <= n-1 && i >= 0 && j >= 0 && a[x][y] == -1){ // 这里有bug， 0，3传进来的时候就动不了了。
		//因为 i < n-1 ,j < n-1, i> 0 , j> 0 是在不同情况下比较的
		a[x][y] = ++count;
		dfs(p_move,a,n,x,y);
	}

	p_move = p_move->link;
	dfs(p_move,a,n,i,j);

}

int main(){
	int n,i,j,index;
	pmove p_down,p_right,p_up,p_left,p_move;
	p_down =(move *)calloc(1,sizeof(move)); p_down->index = 1;p_down->next_i = 1;p_down->next_j = 0;
	p_right= (move *)calloc(1,sizeof(move)); p_right->index = 2; p_right->next_i = 0;p_right->next_j = -1;
	p_up = (move*)calloc(1,sizeof(move)); p_up->index = 3; p_up->next_i = -1;p_up->next_j = 0;
	p_left = (move*)calloc(1,sizeof(move));p_left->index = 4;p_left->next_i = 0;p_left->next_j = 1;

	p_down->link = p_right;
	p_right->link = p_up;
	p_up->link = p_left;
	p_left->link = p_down;

	scanf("%d",&n);
	for(i = 0;i<n;i++){
		for(j = 0;j<n;j++){
			a[i][j] = -1;
		}
	}
	p_move = p_down;
	a[0][n-1] = ++count;
	dfs(p_move,a,n,0,n-1);

	for(i = 0; i<=n;i++){
		for(j = 0;j<=n; j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;	
}
