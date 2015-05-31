/*************************************************************************
	> File Name: c3_bomber.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Apr 30 21:56:31 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char**argv){
	char map[20][21];


	int index_i,index_j, temp,max = 0,max_i,max_j,len,wide,sum,x,y;
	
	scanf("%d %d",&len,&wide);

	FILE * pf = fopen(argv[1],"r");

	for(index_i = 0 ;index_i < len ;index_i ++){
		memset(map[index_i],0,sizeof(map[index_i]));
		fgets(map[index_i],21,pf);
		//scanf("%19s",map[wide]);
	//	fscanf(pf,"%s",map[index_i]);
	}

	for(index_i = 0 ;index_i < len ;index_i ++){
		//for(index_j = 0 ;index_j < wide;index_j ++){
		printf("%s",map[index_i]);
		//}
	}

	for(index_i = 0 ;index_i < len  ; index_i ++){
		for(index_j = 0 ;index_j < wide ;index_j ++){
			//printf("==pass==");
			if(map[index_i][index_j] == '.'){
				printf("\n==gethere==\n[%d,%d]\n",index_i,index_j);
				sum = 0;
				//count upward
				x = index_i;
				y = index_j;
				while(map[x][y] != '#'){
					if(map[x][y] == 'G'){
						sum ++;
					}
					x --;
				}
				
				
				//count downward
				//temp = index_i;
				x = index_i;
				y = index_j;
				while(map[x][y] != '#'){
					if(map[x][y] == 'G'){
						sum++;
					}
					x++;
				}
				/* index_i = temp; */

				//count for right side
				/* temp = index_j; */
				x = index_i;
				y = index_j;
				while(map[x][y] != '#'){
					if(map[x][y] == 'G'){
						sum++;
					}
					y ++;
				}
				/* index_j = temp; */

				//count left side
				x = index_i;
				y = index_j;
				while(map[x][y] != '#'){
					if(map[x][y] == 'G'){
						sum++;
					}
					y --;
				}
				/* index_j = temp; */

				printf("\n==total %d ==\n[%d,%d]\n",sum,index_i,index_j);
				//printf("%d",sum);
				if(sum > max){
					max = sum;
					max_i = index_i;
					max_j = index_j;
				}
			}
		}
	}

	printf("\nthe max opition is locating the bomb on [%d,%d],then kill %d enemies\n",max_i,max_j,max);
	
	return 0;
}
