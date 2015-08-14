/*************************************************************************
	> File Name: main.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jul 14 17:05:31 2015
 ************************************************************************/

#include "sqlist.h"

#define TESTLEN 10

int main(){
	Sqlist test_sl;
	int pos;
	Elemtype e;
	test_sl.length = TESTLEN;
	/* srand(time(NULL)); */
	InitList(&test_sl);
	ShowList(test_sl);

	ListInsert(&test_sl,1,17);
	ShowList(test_sl);
	ListInsert(&test_sl,5,27);
	ShowList(test_sl);
	ListInsert(&test_sl,test_sl.length+1,37);
	ShowList(test_sl);
	
	ListSearch_by_elem(test_sl,&pos,37);
	ListSearch_by_elem(test_sl,&pos,46);
	ListSearch_by_pos(test_sl,10,&e);
	ListSearch_by_pos(test_sl,0,&e);



	return 0;
}
