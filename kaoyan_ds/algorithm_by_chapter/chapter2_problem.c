/************************************************************************* > File Name: chapter2_problem.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jul 15 20:58:41 2015
 ************************************************************************/

#include "sqlist.h"

void ListReverse(Sqlist *L){
	int i = 0, j = L->length-1;
	while(i < j){
		L->data[i] = L->data[i] + L->data[j];
		L->data[j] = L->data[i] - L->data[j];
		L->data[i] = L->data[i] - L->data[j];
		i++;j--;
	}
}

void ListDelete_all_x(Sqlist *L, Elemtype e){
	int i = 0, j = 0 ;
	while(i<L->length){
		if(L->data[i] != e){ //不删的
			L->data[j] = L->data[i]; //j指向的位置就是待放的。
			j++;
		}
		i++;
	}
	L->length = j;//不是j+1，j意思是这个位置待放入，已经是最后一个的后一个
}	

int SortListDelete_s_t(Sqlist *L,Elemtype s, Elemtype t){
	if(s >=t){
		printf("Invaild section\n");
		return False;		
	}
	int i = 0, j = 0;

	while(L->data[i] < s && i < L->length){
		i++;
	}
	if(i >= L->length){
		printf("Invaild t \n");
		return False;
	}
	j = i ;
	while(L->data[j] <= t && j < L->length){
		j++;
	}
	while(j<L->length){
		L->data[i] = L->data[j];
		i++;
		j++;
	}
	L->length = i;
	return True;
}

int ListDelete_s_t(Sqlist *L, Elemtype s, Elemtype t){
	if(s > t){
		printf("s or t is improper\n");
		return False;
	}

	int i = 0, j = 0;

	while(i < L->length){
		if(L->data[i] >=s && L->data[i] <=t){
			j++;// 这是需要删除的，也就是这些位置被下面的给替换
		}else{
			L->data[i-j] = L->data[i];//是的话就往前挪 
		}
		i++;
	}
	L->length -= j;
	return True;
}
