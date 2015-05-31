/*************************************************************************
	> File Name: time.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 26 09:04:28 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{

	struct tm t;
	time_t t_of_day;
	t.tm_year=1997-1900;
	t.tm_mon=6;
	t.tm_mday=1;
	t.tm_hour=0;
	t.tm_min=0;
	t.tm_sec=1;
	t.tm_isdst=0;
	t_of_day=mktime(&t);
	printf(ctime(&t_of_day));
	return 0;
}

