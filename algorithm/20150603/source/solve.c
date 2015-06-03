************************************************************************
	> File Name: solve.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 12:30:30 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int c = 0;

void solve(float a,float b,float c,float d,float e,float f){
	                                                                                                                                                                                                                                                               
}

int f(){
	return ++c;
}
int g(){
	return c++;
}

int h(){
	return ;
}

int main(){
	int a = (f()+g()) + h();
	int b = f() + (g() + h());

	printf("%d %d\n",a,b);

	return 0;
}
