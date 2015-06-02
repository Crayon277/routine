/*************************************************************************
	> File Name: memcpy.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 09:27:59 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int a[10],
		b[10] ={
			0
		},
		i;

	for( i = 0  ; i<10 ;i++){
		a[i] = i;
	}
	memcpy(b,a,sizeof(int)*5);
	
	for(i = 0; i< 10 ; i++){
		printf("%d\n",b[i]);
	}
	return 0;

}
