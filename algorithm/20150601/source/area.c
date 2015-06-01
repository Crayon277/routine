/*************************************************************************
	> File Name: area.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 08:07:31 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Aware of how pi defined
//
int main(){
	const double pi = 2.0 * asin(1);//can't do this: double pi = 3.14; lose precision
	
	double r,h,s1,s2;
	
	scanf("%lf %lf",&r,&h);

	s1 = pi * r * r;
	s2 = 2 * pi * r * h;

	printf("Area = %.3lf\n",s1*2 + s2);

	return 0;
	
}
