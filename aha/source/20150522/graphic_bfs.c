/*************************************************************************
	> File Name: graphic_bfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 21:36:23 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int e[5][5] = {
	0,1,1,0,0,
	1,0,1,1,0,
	1,1,0,1,1,
	0,1,1,0,1,
	0,0,1,1,0
},
	book[5];

typedef struct node{
	int x;
	int step;
	int father;
}stack;
stack que[10];
int head = 0,
	tail = 1;

int output[5],
   top = 0;	

int main(){
	que[head].x = 0;
	que[head].step = 0;
	que[head].father = -1;
	book[0] = 1;
	int des = 5;
	while(head != tail){
		int i = 0;
		int flag = 0;
		/* if(que[head].x == des-1){ */
			/* printf("step is %d\n",que[head].step); */
			/* break; */
		/* } */
		for(i = 0 ;i<5;i++){
			if(e[que[head].x][i] == 1 && book[i] == 0){
				
				book[i] = 1;
				que[tail].x = i;
				que[tail].step = que[head].step + 1;
				que[tail].father = head;
				tail ++;
				if(i == des - 1){
					flag = 1;
					break;
				}
			}
		}
		if(flag == 1){
			break;
		}
		head++;
	}
	tail --;
	printf("%d\n",que[tail].step);
	while(tail != -1){
		output[top++] = que[tail].x;
		tail = que[tail].father;
	}
	top--;
	while(top != -1){
		printf("%d\n",output[top--]);
	}
	return 0;
}
