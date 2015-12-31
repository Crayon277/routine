/*************************************************************************
	> File Name: bianjieduiqi.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Dec 16 23:33:03 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


struct A{
	int a;
	char b;
	short c;
};

struct B{
	char a;
	int b;
	short c;
};


int main(){
	printf("sizeof(int)  =%ld\n",sizeof(int));
	printf("sizeof(char) =%ld\n",sizeof(char));
	printf("sizeof(short)=%ld\n",sizeof(short));
	printf("sizeof(A)    =%ld\n",sizeof(struct A));
	printf("sizeof(B)    =%ld\n",sizeof(struct B));

	return 0;
}
