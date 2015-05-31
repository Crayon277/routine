/*************************************************************************
	> File Name: land_scope_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 20:58:54 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MARGIN_X 10
#define MARGIN_Y 10

int SCOPE,book[MARGIN_X][MARGIN_Y];
int dep_land = 0;
void dfs(int x, int y, int (*land)[MARGIN_Y],int color){//用一个color参数更具有扩展性，改颜色的话只要改color参数就可以了
	int next[4][2] = {
		0,1,1,0,0,-1,-1,0
	};

	int k,
		N_x,
		N_y;

	land[x][y] = color;//本来放在if语句里面的，挪到外面更好，这样第一次的坐标就能一起被染色了，不用在主函数中另外写。
	
	for(k = 0 ;k <= 3; k++){
		N_x = x + next[k][0];
		N_y = y + next[k][1];
		
		if(N_x < 0 || N_y < 0 || N_x > MARGIN_X || N_y > MARGIN_Y){
			continue;
		}
		if(book[N_x][N_y] == 0 && land[N_x][N_y] != 0){
			SCOPE ++;
			book[N_x][N_y] = 1;
			dfs(N_x,N_y,land,color);
		}
	}
}

int main(int argc, char **argv){
	int land[MARGIN_X][MARGIN_Y] ;
	
	int head = 0,
		tail = 1;
	int index_i,index_j;
	FILE * fp = fopen(argv[1],"r");

	for(index_i = 0 ;index_i < MARGIN_X ;index_i++){
		for(index_j = 0 ;index_j < MARGIN_Y;index_j ++){
			fscanf(fp,"%d",&land[index_i][index_j]);
		}
	}
	/* book[6][8] = 1; */
	/* SCOPE++; */
	/* dfs(6,8,land,-1); */
	/* printf("%d\n",SCOPE); */
	
	for(index_i = 0 ;index_i <MARGIN_X ; index_i ++){
		for(index_j = 0 ;index_j < MARGIN_Y ; index_j ++){
			if(land[index_i][index_j] > 0 ){// !!! 重点!!!这里用>0 判断，而不是!=0 ，因为染色之后的陆地也是!=0所以会进循环，导致在计数独立小岛的时候会算进去，这样就有50多个独立小岛了，其实这都是循环遍历的结果。
				book[index_i][index_j] = 1;
				/* dep_land++;can't placed here */
				dep_land++;
				dfs(index_i,index_j, land,-(dep_land));
								
			}
		}
	}


	for(index_i = 0; index_i < MARGIN_X; index_i ++){
		for(index_j = 0; index_j < MARGIN_Y; index_j ++){
			printf("%3d",land[index_i][index_j]);
		}
		printf("\n");
	}
	printf("There are %d dependant lands\n",dep_land);
	return 0;
}
