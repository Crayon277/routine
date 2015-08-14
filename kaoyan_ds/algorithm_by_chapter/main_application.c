/*************************************************************************
	> File Name: main_application.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jul 15 20:31:51 2015
 ************************************************************************/

#include "sqlist.h"

int main(){
	Sqlist test;
	test.length = 11;
	InitList(&test);
	ShowList(test);
	
	ListReverse(&test);
	ShowList(test);
	
	ListDelete_all_x(&test,3);
	ShowList(test);
	return 0;	
}
