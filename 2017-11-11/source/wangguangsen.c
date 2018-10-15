/*************************************************************************
	> File Name: wangguangsen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Nov 23 21:08:16 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int num;
	int max = 0,min = 1000000001;
	int mincount=0,maxcount = 0;
	scanf("%d",&n);
	while(n){
		scanf("%d",&num);
		if(num > max){
			max = num;
			maxcount  = 1;
		}else if(num == max){
			maxcount ++;
		}

		if(num < min){
			min = num;
			mincount =1;
		}else if(num == min){
			mincount++;
		}
		n--;
	}
	printf("%d %d\n",max-min,mincount*maxcount);
	return 0;
}
