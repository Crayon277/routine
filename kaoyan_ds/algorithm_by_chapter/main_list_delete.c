/*************************************************************************
	> File Name: main_list_delete.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jul 22 21:38:36 2015
 ************************************************************************/

#include"sqlist.h"

int main(){
	Sqlist L;
	L.length = 10;
	InitList(&L);

	ShowList(L);

	ListDelete_s_t(&L,5,7);

	ShowList(L);

	return 0;
}
