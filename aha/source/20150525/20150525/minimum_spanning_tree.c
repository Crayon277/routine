/*************************************************************************
	> File Name: minimum_spanning_tree.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed May 27 08:41:05 2015
 ************************************************************************/

/* #include<stdio.h> */
/* #include<stdlib.h> */
#include"minimum_spanning_tree.h"
#define SWAP(a,i,j) { int temp; temp = a[i];a[i] = a[j]; a[j] = temp;}

void shift_down(int *a, int size,int i,int *w){
	int t;

	while(i*2 <= size){
		t = i;
		if(w[a[i]] < w[a[i*2]]){
			t = i*2;	
		}
		if( i * 2 + 1 <=size){
			if(w[a[t]] < w[a[i*2+1]]){
				t = i*2+1;
			}
		}
		if(t != i){
			SWAP(a,t,i);
			i = t;
		}else{
			break;
		}
	}
}

void create_max_heap(int *a,int size,int *w){
	int i;
	for(i = size/2 ; i>= 1;i--){
		shift_down(a,size,i,w);
	}
}

void heap_sort(int *a,int size,int *w){
	while(size != 1){
		SWAP(a,1,size);
		size--;
		shift_down(a,size,1,w);
	}
}

int getf(int*union_a,int v){
	if(union_a[v] == v){
		return v;
	}else{
		union_a[v] = getf(union_a,union_a[v]);
		return union_a[v];
	}
}
int main(){
	int union_find[100];

	int u[100],v[100],w[100];
	int *sort_array;
	int n = 1,
		i,
		in,
		out,
		temp;
	FILE * fp = fopen("spanning_tree.txt","r");

	while(fscanf(fp,"%d %d %d\n",&u[n],&v[n],&w[n]) != EOF){	
		n++;
	}


	sort_array = (int*)malloc(sizeof(int) * n);
	for(i = 1; i < n; i++){
		sort_array[i] = i;
	}
	
	/* create_max_heap(sort_array,n-1,w); */
	
	/* heap_sort(sort_array,n-1,w); */
	printf("In main %d\n",n);
	QUICK(sort_array,n-1,w);
	printf("======\n");	
	for(i = 1 ;i < n ;i++){
		printf("%d ",sort_array[i]);
	}
	printf("\n");
	//union_find init
	for(i = 1; i< n; i++){
		union_find[i] = i;
	}

	//get the shortest path and check if produce circle by union-find set
	for(i = 1;i<n;i++){
		int t1 = getf(union_find,u[sort_array[i]]);
		int t2 = getf(union_find,v[sort_array[i]]);

		if(t1 != t2){
			printf("%d %d %d\n",u[sort_array[i]],v[sort_array[i]],w[sort_array[i]]);
			in = u[sort_array[i]];
			out = v[sort_array[i]];

			if(in > out){
				in ^= out;
				out ^= in;
				in ^= out;
			}

			if(union_find[out] != out){
				temp = union_find[out];
				union_find[out] = union_find[in];
				out = temp;
			}
			union_find[out] = union_find[in];
		}	

	}
	free(sort_array);
	return 0;
}
