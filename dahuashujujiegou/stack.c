/*************************************************************************
	> File Name: stack.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Aug 15 14:58:44 2015
 ************************************************************************/

#include "stack.h"

Status Push_sqstack(SqStack *s, SElemType e){
	if(s->top==MAXSIZE){
		return Error;
	}
	s->top ++;
	s->data[s->top] = e;
	return Ok;
}

Status Pop_sqstack(SqStack *s, SElemType *e){
	if(s->top == -1){
		return Error;
	}
	*e = s->data[s->top--];
	return Ok;
}

Status Push_sqdoublestack(SqDoubleStack *s, SElemType e, int stackNumber){
	if(s->top1 +1 == s->top2){
		return Error;
	}
	if(stackNumber == 1){
		s->data[++s->top1] = e;
		return Ok;
	}
	else if(stackNumber == 2){
		s->data[--s->top2] = e;
		return Ok;
	}
	return Error;
}
Status Pop_sqdoublestack(SqDoubleStack *s, SElemType *e, int stackNumber){
	if(stackNumber == 1){
		if(s->top1 == -1){
			return Error;
		}
		*e = s->data[s->top1--];
		return Ok;
	}
	else if(stackNumber == 2){
		if(s->top2 == MAXSIZE2){
			return Error;
		}
		*e = s->data[s->top2++];
		return Ok;
	}
	//
	return Error;
}

Status Push_LinkStack(LinkStack *s, SElemType e){
	LinkStackPtr newNode = (StackNode *)malloc(sizeof(StackNode));
	newNode->data = e;
	/* newNode->link = NULL; */
	/* if(count == 0){ */
		/* s->top = newNode; */
	/* }else{ */
		/* LinkStackPtr traceNode = s->top; */
		/* while(!traceNode->link){ */
			/* traceNode = traceNode->link; */
		/* } */
		/* traceNode->link = newNode; */
	/* } */
	//头插！！
	newNode->link = s->top;
	s->top = newNode;

	s->count++;
	return Ok;
}

Status Pop_Linkstack(LinkStack *s, SElemType *e){
	if(s->count == 0){
		return Error;
	}
	LinkStackPtr deleNode = s->top;
	s->top = s->top->link;
	*e = deleNode->data;
	free(deleNode);
	s->count--;
	return Ok;
}


