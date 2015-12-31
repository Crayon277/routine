/*************************************************************************
	> File Name: shell.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Dec 15 22:56:07 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define len 10
/* #define step len/2 */

void insert_sort(int*arr,int step,int start){
	int i ,j;
	for(i = start+step; i < len; i+=step){
		int tmp = arr[i];
		for(j=i-step;tmp<arr[j] && j>=start;j-=step){
			arr[j+step] = arr[j];
		}
		arr[j+step] = tmp;
	}
}

void shell_sort(int *arr){
	int step = len / 2;
	while(step>=1){
		int i = 0;
		while(i<step){
			insert_sort(arr,step,i);
			i++;
		}
		step/=2;
	}	
}
//上面我的思想是每次对一个表就进行一次性的处理

//===========
//这个思想是以插入为基础，每次步进是改变步长
void shell(int *arr){
	int step;
	for(step = len/2 ; step>=1; step/=2){
		int i;
		for(i = 0+step; i<len; i++){ // 这里还是一步一步的来
			int tmp = arr[i];
			int j;
			for(j = i-step ; tmp<arr[j] && j>=0; j-=step){//这里变成步长，每个插入到相应步长的表
				arr[j+step] = arr[j];
			}
			arr[j+step] = tmp;
		}
	}
}

//==========

void set(int a){
	a=rand()%20;
}

void output(int a){
	printf("%d ",a);
}

void arrControl( void (*fun)(int), int *arr){
	int index;
	for(index = 0; index < len; index++){
		fun(arr[index]);
	}
	printf("\n");
}	

int main(){
	int a[len];
	int i;
	/* srand(time(NULL)); */
	/* arrControl(set,a); */
	for(i=0;i<len;i++){
		a[i] = rand()%20;
		printf("%d ",a[i]);
	}
	printf("\n");
	/* shell_sort(a); */
	shell(a);
	/* arrControl(output,a); */
	for(i=0;i<len;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
