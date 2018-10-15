/*************************************************************************
	> File Name: solve.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar  5 20:45:25 2018
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct route{
	int stack[24][2];
	int top;
}ROUTE;
int total = 24;
ROUTE path;

int flag = 0;

void print_path(){
	int top = path.top;
	flag = 1;
	while(top >= 0){
		printf("(%d,%d) --> ", path.stack[top][0],path.stack[top][1]);	
		top --;
	}
	printf("\n\n\n");
}

int Already_exist(x,y){
	for(int i = 0; i <= path.top;i++){
		if(x == path.stack[i][0] && y == path.stack[i][1]){
			return 1;
		}
	}
	return 0;
}

int valid(x,y){
	if(x<0 || y<0 || x>4 || y > 4 || (x == 0 && y == 1)){
		return 0;
	}
	if(Already_exist(x,y)){
		return 0;
	}
	return 1;
}

void save_route(x,y){
	path.top ++;
	path.stack[path.top][0] = x;
	path.stack[path.top][1] = y;
}

void clean_route(x,y){
	path.top --;
}

void next(int x, int y,int count){
	/* printf("pass,%d,(%d,%d),%d\n",count,x,y,path.top); */
	/* getchar(); */
   if( 24 == count && 23 == path.top){
	   print_path();
	   return;
   }	   
   for(int i = -1;i<=1;i+=2){
		if(valid(x+i,y)){
			save_route(x+i,y);
			next(x+i,y,count+1);
			clean_route(x+i,y);
		}
   }
   for(int i = -1;i<=1;i+=2){
		if(valid(x,y+i)){
			save_route(x,y+i);
			next(x,y+i,count+1);
			clean_route(x,y+i);
		}
   }
}

int main(){
	path.top = 0;
	int start_x=0,start_y = 0;
	path.stack[0][0] = start_x;
	path.stack[0][1] = start_y;
	next(start_x,start_y,1);
	if(!flag){
		printf("no solution!\n");
	}
	return 0;	
}
