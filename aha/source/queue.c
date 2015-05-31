/*************************************************************************
	> File Name: queue.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 27 09:45:38 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(){
	queue q;
	int i;
	q.head = 1;
	q.tail = 1;
	for(i = 1; i <= 9 ;i++){
		scanf("%d",&q.data[q.tail]);
		q.tail++;
	}

	while(q.head< q.tail){
		printf("%d ",q.data[q.head]);
		q.head++;
		
		q.data[q.tail++] = q.data[q.head++];
	}

	return 0;

}
