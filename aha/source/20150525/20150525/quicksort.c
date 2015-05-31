/*************************************************************************
	> File Name: quicksort.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed May 27 21:04:42 2015
 ************************************************************************/
#include"minimum_spanning_tree.h"

int partion(int *a , int begin,int end, int *w){
	int temp;
	temp = a[begin];


	while(begin < end){
		while(w[a[end]] >= w[temp] && begin < end){
			end--;
		}
		a[begin] = a[end];
		while(w[a[begin]] < w[temp] && begin < end){
			begin ++;
		}
		a[end] = a[begin];
	}	
	
	a[begin] = temp;
	return begin;
}

void quicksort(int *a, int begin, int end, int *w){
	int p;
	if(begin >= end){
		return;
	}

	p = partion(a,begin,end,w);
	printf("%d\n",p);
	quicksort(a,begin,p-1,w);
	quicksort(a,p+1,end,w);
}

void QUICK(int *a, int size ,int *w){
	printf("In QUICK %d\n",size);
	quicksort(a,1,size,w);
}
