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
		while(w[a[end]] >= w[temp]){
			end--;
		}
		a[begin] = a[end];
		while(w[a[begin]] < w[temp]){
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

void quicksort_2(int *a, int begin, int end, int *w){
	if(begin >= end){
		return;
	}
	int o_b = begin,
		o_e = end;
	a[0] = a[begin];

	while(begin < end){
		while(begin < end && w[a[end]] >= w[a[0]]){
			end --;
		}
		a[begin] = a[end];

		while(begin < end && w[a[begin]] < w[a[0]]){
			begin ++;
		}
		a[end] = a[begin];
	}

	a[begin] = a[0];
	
	quicksort_2(a, o_b, begin-1, w);
	quicksort_2(a, begin+1, o_e, w);

	
}
void QUICK(int *a, int size ,int *w){
	/* printf("%d\n",size); */
	/* quicksort(a,1,9,w); */
	quicksort_2(a,1,size,w);
}

