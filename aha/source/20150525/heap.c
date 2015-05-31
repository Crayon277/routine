/*************************************************************************
	> File Name: heap.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon May 25 10:23:38 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define SWAP(a,i,j) {int t; t = a[i];a[i] = a[j]; a[j]=t;}



void shift_down(int *a,int size,int i,int feature){  // set heap to min_heap if feature = 1
	int temp ;

	while(i*2 <= size){
		temp = i;
		if(feature == 1){
			if(a[i] > a[i*2]){
				temp = i*2;
			}
		}else{
			if(a[i] < a[i*2]){
				temp = i*2;
			}
		}
		if(i*2+1 <= size){
			if(1 == feature){
				if(a[temp] > a[i*2+1]){
					temp = i*2 + 1;
				}
			}else{
				if(a[temp] < a[i*2 + 1]){
					temp = i*2+1;
				}
			}
		}
		if(temp == i){
			break;
		}
		
		SWAP(a,i,temp);
		i = temp;
	}
}

void shift_up(int *a,int size,int i,int feature){
	int flag = 0;
	if(feature == 1){
		while(i!=1){
			if(a[i] < a[i/2]){
				SWAP(a,i,i/2);
				i = i/2;
			}else{
				flag = 1;
			}
			if(1 == flag){
				break;
			}
		}
	}else{
		while(i != 1){
			if(a[i] > a[i/2]){
				SWAP(a,i,i/2);
				i = i/2;
			}else{
				flag = 1;
			}
			if(1 == flag){
				break;
			}
		}
	}

}

void create_min_heap(int *a,int size){
	int i;
	for(i = size/2; i>=1; i--){
		shift_down(a,size,i,1);
	}
}

void create_max_heap(int *a, int size){
	int i;
	for(i = size/2;i>=1;i--){
		shift_down(a,size,i,0);
	}
}

void heap_sort(int *heap, int size){/*  , int feature){ // sort ascending order if feature = 1, descending if feature = 0 */
	int count = size;	

	while(count != 1){
		SWAP(heap,1,count);
		count --;
		shift_down(heap,count,1,0);
	}	
}

int main(){
	int heap_min[100],
		heap_max[100];
	int size,
		i;
	
	scanf("%d\n",&size);
	for(i = 1 ; i<= size; i++){
		scanf("%d",&heap_min[i]);
		heap_max[i] = heap_min[i];
	}

	printf("======================\n");
	printf("min\tmax\n");
	for(i = 1 ; i<= size; i++){
		printf("%3d\t%3d\n",heap_min[i],heap_max[i]);
	}
	printf("======================\n");
	create_min_heap(heap_min,size);
	create_max_heap(heap_max,size);
	printf("min\tmax\n");
	for(i = 1 ; i<= size; i++){
		printf("%3d\t%3d\n",heap_min[i],heap_max[i]);
	}

	heap_sort(heap_max,size);
	for(i = 1; i<=size;i++){
		printf("%d ",heap_max[i]);
	}
	printf("\n");
	return 0;

}
