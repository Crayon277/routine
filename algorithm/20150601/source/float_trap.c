/*************************************************************************
	> File Name: float_trap.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 11:14:52 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main(){
	double i;
	for(i = 0; i!=10;i+=0.1){ // It can't be stoped by the condition i != 10 . Check it out
		printf("%.1lf\n",i);
	
	}
	return 0;
}

// (gdb)
// p i
// $2 = 0.10000000000000001
//
//so, type double is blamed. Adding 0.1, it's not real plus 0.1. 
//0.1 isn't exactly, 0.1 because of converting to binary
