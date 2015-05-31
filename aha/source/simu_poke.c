/***********************************************:**************************
	> File Name: simu_poke.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 27 10:48:57 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int data[1000];
	int head;
	int tail;
}queue;

typedef struct stack{
	int data[10];
	int top;
}stack;

void handle(queue * pq, stack * ps){
	int temp = (*pq).data[(*pq).head++];
	int index,flag = 0;
	for(index = 0; index < (*ps).top; index++ ){
		if((*ps).data[index] == temp){
			flag = 1;
			break;
		}
	}
	if(flag){
		(*pq).data[(*pq).tail++] = temp;
		while((*ps).data[(*ps).top - 1] != temp){
			(*pq).data[(*pq).tail++] = (*ps).data[(*ps).top - 1] ;
			(*ps).top --;
		}
		//还要再放一次
		//因为栈中相同的部分也要取出来

		/* (*pq).data[(*pq).tail++] = (*ps).data[(*ps).top - 1] ; */
		/* (*ps).top --; */

	}else{
		(*ps).data[(*ps).top++] = temp;
	}
}

int main(){
	queue q1,q2;
	stack s;
	int turn = 1;
	int temp;
	q1.head = q1.tail = q2.head = q2.tail = 1;
	s.top = 0;
	int index;
	for(index = 1; index <= 6 ; index++){
		scanf("%d",&q1.data[q1.tail++]);
	}
	for(index = 1; index<= 6;index++){
		scanf("%d",&q2.data[q2.tail++]);
	}

	while(q1.head < q1.tail && q2.head < q2.tail){
		if(turn){
			//q1			
			handle(&q1,&s);
			turn = 0;
		}
		else{
			//q2
			handle(&q2,&s);
			turn = 1;
		}
	}

	printf("===debug===\n");
	for(index = q1.head;index!= q1.tail; index++){
		printf("%d " ,q1.data[index]);
	}
	printf("\n");
	printf("===debug===\n");
	if(q1.head == q1.tail){
		printf("q2 win \n");
		printf("q2 have:\n");
		for(index = q2.head; index != q2.tail; index++){
			printf("%d ",q2.data[index]);
		}
		printf("desktop have :\n");
		for(index = 0 ;index != s.top ;index ++){
			printf("%d ",s.data[index]);
		}
	}
	else{
		printf("q1 win \n");
		printf("q1 have :\n");
		for(index = q1.head; index != q1.tail; index++){
			printf("%d ",q1.data[index]);
		}
		printf("desktop have :\n");
		for(index = 0 ;index != s.top ;index ++){
			printf("%d ",s.data[index]);
		}
	}
	return 0;
}
