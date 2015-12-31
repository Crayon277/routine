/*************************************************************************
	> File Name: queue.h
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Aug 19 23:08:14 2015
 ************************************************************************/

#include"common.h"

typedef int QElemType;

typedef struct{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *q);
Status QueueLength(SqQueue q);
Status DeQueue(SqQueue *q, QElemType *e);
Status EnQueue(SqQueue *q, QElemType e);


typedef struct queuenode{
	QElemType data;
	struct queuenode * link;
}Qnode, *QueuePtr;

typedef struct{
	QueuePtr front,rear;
}LinkQueue;

Status InitLinkQueue(LinkQueue *q);
Status EnLinkQueue(LinkQueue * q, QElemType e);
Status DeLinkQueue(LinkQueue * q, QElemType *e);
