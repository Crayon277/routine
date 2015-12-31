/*************************************************************************
	> File Name: date.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Oct 18 05:14:04 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int month_days[2][13]={
	{
		0,31,28,31,30,31,30,31,31,30,31,30,31
	},
	{
		0,31,28,31,30,31,30,31,31,30,31,30,31
	}
};

typedef struct data{
	int year;
	int month;
	int day;
}data;

int main(){
	data today = {
		2015,10,18
	};
	data future;
	int indexyear,indexmonth,totaldays = 0;
	printf("enter data:");
	scanf("%d %d %d",&future.year,&future.month,&future.day);
	for(indexmonth=today.month;indexmonth <future.month;indexmonth++){
			totaldays += month_days[1][indexmonth];
	}
	totaldays = totaldays+future.day-today.day;
	printf("%d\n",totaldays);
	return 0;
}
