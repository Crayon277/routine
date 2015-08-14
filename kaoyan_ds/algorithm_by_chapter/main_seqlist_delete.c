/*************************************************************************
	> File Name: main_seqlist_delete.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jul 17 15:08:52 2015
 ************************************************************************/
#include"sqlist.h"

int main(){
	Sqlist L;
	L.length  =  10;
	InitSeqList(&L);
	ShowList(L);
	SortListDelete_s_t(&L,3,5);
	ShowList(L);

	return 0;
}
