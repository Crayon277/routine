/*************************************************************************
	> File Name: ctime.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 08:02:17 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	time_t biggest = 0x7fffffff;

	printf("biggest = %s\n",asctime(gmtime(&biggest)));
	printf("%s\n",ctime(&biggest));
	return 0;
}
