/*************************************************************************
	> File Name: stack.h
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Aug 14 17:06:02 2015
 ************************************************************************/

/*
 * Operation
 * InitStack(*s)
 * DestroyStack(*s)
 * ClearStack(*s)
 * StackEmpty(s) return true if empty
 * StackLength(s)
 * GetTop(s,*e) return the topest element if stack is exist and not empty
 * =======important below====
 * Push(*s,e)
 * Pop(*s,*e)
 * ==========================
*/

#include"common.h"

typedef int SElemType;
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack;



Status InitStack(SqStack *s);
Status DestroyStack(SqStack *s);


Status Push_sqstack(SqStack *s, SElemType e);
Status Pop_sqstack(SqStack *s, SElemType *e);

#define MAXSIZE2 200
typedef struct{
	SElemType data[MAXSIZE2];
	int top1;
	int top2;
}SqDoubleStack;

Status Push_sqdoublestack(SqDoubleStack *s, SElemType e, int stackNumber);
Status Pop_sqdoublestack(SqDoubleStack *s, SElemType *e, int stackNumber);

typedef struct node{
	SElemType data;
	struct node * link;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;

Status Push_LinkStack(LinkStack *s, SElemType e);
Status Pop_LinkStack(LinkStack *s, SElemType *e);
