/*************************************************************************
	> File Name: ex1.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon May 25 23:44:51 2015
 ************************************************************************/
#include<stdio.h>

char *color[] = {
	"red",
	"blue",
	"green"
};
#define color_num (sizeof(color)/sizeof(char*))
int main(int argc, char *argv[]){
	printf("size %d\n",color_num);
	return 0;
}
