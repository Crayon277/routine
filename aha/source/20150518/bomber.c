/*************************************************************************
	> File Name: bomber.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 19 15:33:09 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

// map
// --- bomber - statistic
// --- wall   - can't stand here either
//
// for( four direction ) 
// --- get the statistics of the bomber numbers of this point
// --- compare the max. set the max
//
//

#define MARGIN_X 13
#define MARGIN_Y 13

int book[MARGIN_X][MARGIN_Y];

int statistic(int x, int y,char**map){
	int index_i, index_j ;
	int sum = 0;
	index_i = x;
	index_j = y;
	while(map[index_i][index_j] != '#'){
		if(map[index_i][index_j] == 'G'){
			sum++;
		}
		index_j++;
	}
	index_i = x;
	index_j = y;
	while(map[index_i][index_j] != '#'){
		if(map[index_i][index_j] == 'G'){
			sum++;
		}
		index_i++;
	}
	index_i = x;
	index_j = y;
	while(map[index_i][index_j] != '#'){
		if(map[index_i][index_j] == 'G'){
			sum++;
		}
		index_j--;
	}
	index_i = x;
	index_j = y;
	while(map[index_i][index_j] != '#'){
		if(map[index_i][index_j] == 'G'){
			sum++;
		}
		index_i--;
	}
	return sum;
}

void dfs_bomber(int x, int y, int* max,int* m_x, int* m_y,char **map){
	int next[4][2] = {
		{
			0,1
		},
		{
			1,0
		},
		{
			0,-1
		},
		{
			-1,0
		}
	};
	int k,
		N_x,
		N_y,
		sum;
	sum = statistic(x,y,map);
	
	if(sum > (*max)){
		*max = sum;
		*m_x = x;
		*m_y = y;
	}

	for(k = 0 ; k<=3 ;k++){
		N_x = x + next[k][0];
		N_y = y + next[k][1];
		
		if(N_x < 0 || N_y < 0 || N_x > MARGIN_X || N_y > MARGIN_Y){
			continue;
		}
		if(book[N_x][N_y] == 0 && map[N_x][N_y] == '.'){
			book[N_x][N_y] = 1;
			dfs_bomber(N_x,N_y,max,m_x,m_y,map);		
		}
	}
}

int main(){
	char map[MARGIN_X][MARGIN_Y] = {
		"#############",
		"#GG.GGG#GGG.#",
		"###.#G#G#G#G#",
		"#.......#..G#",
		"#G#.###.#G#G#",
		"#GG.GGG.#.GG#",
		"#G#.#G#.#.#.#",
		"##G...G.....#",
		"#G#.#G###.#G#",
		"#...G#GGG.GG#",
		"#G#.#G#G#.#G#",
		"#GG.GGG#G.GG#",
		"#############"
		
	};
	int max,m_x,m_y;
	
	m_x = 3;
	m_y = 3;
	max = statistic(3,3,map);
	book[3][3] = 1;
	dfs_bomber(3,3,&max,&m_x,&m_y,map);
	
	printf("(%d,%d) max is %d\n",m_x,m_y,max);

	return 0;
}

