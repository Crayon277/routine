/*************************************************************************
	> File Name: chapter2_list.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jul 13 21:11:40 2015
 ************************************************************************/

#include "sqlist.h"

void InitList(Sqlist *L){
	int i;
	for(i = 0 ; i< L->length; i++){
		L->data[i] = rand()%10;
	}
}

void InitSeqList(Sqlist *L){
	int i;
	for(i = 0; i< L->length; i++){
		L->data[i] = i+1;
	}
}
void ShowList(Sqlist L){
	int i;
	printf("=======Sqlist=========\n");
	for(i = 0 ; i< L.length; i++){
		printf("%d ",L.data[i]);
	}
	printf("\n=====listLen: %d =====\n",L.length);
	printf("\n");
}
int ListInsert(Sqlist *L, int i ,Elemtype e){
	if(i<1 || i > (*L).length+1){
		return False;
	}
	if((*L).length >= MAXSIZE){
		return False;
	}
	int k;
	for(k = (*L).length ; k>=i; k--){
		(*L).data[k] = (*L).data[k-1];	
	}	
	(*L).data[k] = e;
	(*L).length ++;
	return True;
}

int ListDelete(Sqlist *L, int i, Elemtype *e){
	if(i < 1 || i > L->length){
		return False;
	}
	int j;
	*e = L->data[i-1];
	for(j = i-1; j < L->length-1 ; j++){
		L->data[j] = L->data[j+1];
	}
	L->length-- ;
	return True;
}

int ListSearch_by_elem(Sqlist L, int *pos, Elemtype e){
	int i;
	for(i = 0 ; i < L.length; i++){
		if(L.data[i] == e){
			break;
		}
	}
	if(i<L.length){
		printf("Find it ! in pos : %d\n",i+1);
		*pos = i+1;
		return True;
	}else{
		printf("No such element:%d\n",e);
		return False;
	}	
}

int ListSearch_by_pos(Sqlist L, int pos, Elemtype *e){
	if(pos < 1 || pos > L.length){
		printf("Pos invaild\n");
		return False;
	}
	printf("Pos %d is %d\n",pos,L.data[pos-1]);
	*e = L.data[pos-1];
	return True;

}

