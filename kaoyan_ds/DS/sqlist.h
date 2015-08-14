/*************************************************************************
	> File Name: sqlist.h
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jul 13 20:12:24 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 100
#define INCREMENT 10

#define False 0
#define True 1
typedef int Elemtype; 
typedef struct sqlist{
	Elemtype data[MAXSIZE];
	int length;
}Sqlist;
typedef struct seqlist{
	Elemtype *data;
	int maxsize,length;
}Seqlist;
//basic
void ShowList(Sqlist L);
void InitList(Sqlist *L);
void InitSeqList(Sqlist *L);

int ListInsert(Sqlist *L, int i, Elemtype e);
int ListDelete(Sqlist *L, int i, Elemtype *e);
int ListSearch_by_elem(Sqlist L, int *pos, Elemtype e); // 第一个elem在哪
int ListSearch_by_pos(Sqlist L, int pos, Elemtype *e);	//pos 处的元素是什么


//special
int SortListDelete_s_t(Sqlist *L, Elemtype s, Elemtype t);
void ListReverse(Sqlist *L);
void ListDelete_all_x(Sqlist *L, Elemtype e);
int ListDelete_s_t(Sqlist *L, Elemtype s, Elemtype t);

