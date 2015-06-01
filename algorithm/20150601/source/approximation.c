/*************************************************************************
	> File Name: approximation.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 16:09:35 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,flag = 1;
	double sum,fraction;
	sum = 0;
	for(i = 1;;i+=2){
		fraction = (double)1/i;
		if(fraction < 10e-6){
			break;
		}
		sum += flag*fraction;
		flag *= -1;
	}

	printf("%.3lf\n",sum);

	return 0;
}
