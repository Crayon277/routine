/*************************************************************************
	> File Name: carrot.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Apr 22 14:40:32 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int a[10] = {
		0
	};
	/* memset(a,0,10); */

	int index = 5,i;

	while(index){
		scanf("%d",&i);
		a[i-1] = 1;
		index--;
	}
	
	for(index = 0 ;index!=10; index++){
		if(!a[index]){
			printf("%d ",index+1);
		}
	}
	return 0;

}
