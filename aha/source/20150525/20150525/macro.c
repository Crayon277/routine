/*************************************************************************
	> File Name: macro.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed May  6 02:48:16 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char *color_name[] = {
	"red",
	"blue",
	"green"
};

#define color_num (sizeof(color_name)/sizeof(char*))

int main(){
	printf("size %d \n",color_num);
	return 0;
}
