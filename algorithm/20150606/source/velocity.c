/*************************************************************************
	> File Name: velocity.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 21:49:09 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int v,t;
	while(scanf("%d %d",&v,&t) != EOF){
		printf("%d\n",2*v*t);
	}
	return 0;
}
