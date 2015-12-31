/*************************************************************************
	> File Name: test_main.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Aug 22 10:00:20 2015
 ************************************************************************/

#include"stack.h"
#include"queue.h"

int main(){
	SqQueue test_sq;
	LinkQueue test_linksq;
	int traver;
	int index;
	int delelem;
	QueuePtr traver_link;
	/*
	InitQueue(&test_sq);
	for(index=1; index<=10;index++){
		EnQueue(&test_sq,index);
	}
	printf("\n");
	DeQueue(&test_sq,&delelem);
	traver = test_sq.front;
	while((traver+1)%MAXSIZE != test_sq.rear){
		printf("%d ",test_sq.data[index]);
		traver++;
	}
	printf("\nQueue length is : %d\n",QueueLength(test_sq));
	*/

	InitLinkQueue(&test_linksq);
	for(index = 1 ; index<=10; index++){
		EnLinkQueue(&test_linksq,index);
	}
	traver_link = test_linksq.front->link;
	while(traver_link != NULL){
		printf("%d ",traver_link->data);
		traver_link = traver_link->link;
	}
	printf("\n");
	
	DeLinkQueue(&test_linksq,&delelem);
	printf("elem %d is coming out\n",delelem);

	return 0;

}
