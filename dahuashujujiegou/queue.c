/*************************************************************************
	> File Name: queue.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Aug 22 09:19:34 2015
 ************************************************************************/

#include"queue.h"

Status InitQueue(SqQueue *q){
	q->front = 0;
	q->rear = 0;
	return Ok;
}

Status QueueLength(SqQueue q){
	return ((q.rear - q.front + MAXSIZE)%MAXSIZE);
}

Status EnQueue(SqQueue *q, QElemType e){
	if((q->rear + 1)%MAXSIZE== q->front){
		return Error;
	}
	q->data[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;
	return Ok;
}

Status DeQueue(SqQueue *q, QElemType *e){
	if(q->rear == q->front){
		return Error;
	}
	*e = q->data[q->front];
	q->front = (q->front+1) %MAXSIZE;
	return Ok;
}


Status InitLinkQueue(LinkQueue *q){
	QueuePtr headnode = (QueuePtr)malloc(sizeof(Qnode));
	headnode->link = NULL;
	q->front = headnode;
	q->rear = headnode;
	return Ok;
}
Status EnLinkQueue(LinkQueue *q, QElemType e){
	QueuePtr newnode = (QueuePtr)malloc(sizeof(Qnode));
	if(!newnode){
		return Error;
	}

	newnode->data = e;
	newnode->link = NULL;
	q->rear->link = newnode;
	q->rear = newnode;
	return Ok;
}
Status DeLinkQueue(LinkQueue *q,QElemType *e){
	QueuePtr deletenode;
	if(q->front == q->rear){
		return Error;
	}
	
	deletenode = q->front->link;
	q->front->link = deletenode->link;
	*e = deletenode->data;
	if(q->rear == deletenode){
		q->rear = q->front;
	}
	free(deletenode);
	return Ok;
}
