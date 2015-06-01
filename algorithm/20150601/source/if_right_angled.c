/*************************************************************************
	> File Name: if_right_angled.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 09:06:45 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int e1,e2,e3,x,y,z;

	scanf("%d %d %d",&e1,&e2,&e3);
	//test
	/* printf("%d %d %d\n",e1^2,e2^2,e3^2); */ /* ^ is binary XOR operator */ 

	z = e1; if(x < e2) x = e2; if(x < e3) x = e3;
	y = e1; if(y > e2) y = e2; if(y > e3) y = e3;

	x = e1+e2+e3 - z-y;
	
	if(x*x +y*y  == z*z){
		printf("yes\n");
	}else{
		printf("no\n");
	}

	return 0;
}
