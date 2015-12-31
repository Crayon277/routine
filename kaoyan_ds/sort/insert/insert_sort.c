/*************************************************************************
	> File Name: insert_sort.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Dec 15 21:29:55 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define len 20
void insert_sort(int* arr){
	int i,j;
	for(i=1;i<len;i++){
		int tmp = arr[i];
		for(j=i;tmp<arr[j-1] && j>=0 ; j--){
			arr[j] = arr[j-1];
		}
		arr[j] = tmp;
	}
}

int main(){
	int a[len];
	int i = 0;
	srandom(time(NULL));
	for(;i<len;i++){
		a[i]=random()%20;
		printf("%d ",a[i]);
	}
	printf("\n");
	insert_sort(a);
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}


