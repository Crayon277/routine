/*************************************************************************
	> File Name: subset.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 11 11:01:26 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int output[MAX],
	book[MAX];
void print_set(int cur,int num, int *set,int size){
	int i;
	if(cur == num){
		if(0 == num){
			printf("$");//表示空集
		}else{
			for(i = 0 ; i< num;i++){
				printf("%d ",output[i]);
			}
		}
		printf("\n");
		return ;
	}
	for(i = 0; i<size;i++){
		
		book[set[i]] = 1;
		output[cur] = set[i];
		print_set(cur+1,num,set,size);
		//book[set[i]] = 0;//有也不行，没有也不行，（2，3）这个集合没有打印出来
	}
}

void print_set_2(int cur,int num, int *set,int size){
	int i;
	if(cur == num){
		if(0 == num){
			printf("$");//表示空集
		}else{
			for(i = 0 ; i< num;i++){
				printf("%d ",output[i]);
			}
		}
		printf("\n");
		return ;
	}
	for(i = cur; i<size;i++){
	//这个也不行，重复了，比如打印出2，2了。	
		if(book[set[i]] || (cur>0 && set[i] < output[cur-1])){ // overflow
			continue;
		}
		book[set[i]] = 1;
		output[cur] = set[i];
		print_set_2(cur+1,num,set,size);
		book[set[i]] = 0;
	}
}
void print_subset(int n, int *A, int cur){
	for(int i = 0 ; i<cur;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	int s = cur ? A[cur-1] + 1:0;
	for(int i = s;i<n;i++){
		A[cur] = i;
		print_subset(n,A,cur+1);
	}
} 

void prin_subset(int n, int*A, int cur){
	if(cur == n+1){
		for(int i = 1; i<= cur;i++){
			if(A[i]){
				printf("%d ",i);
			}
		}
		printf("\n");
		return;
	}
	A[cur] = 1;
	prin_subset(n,A,cur+1);
	A[cur] = 0;
	prin_subset(n,A,cur+1);
}

int main(){
	int set[MAX];;
	int n,i,j;
	scanf("%d",&n);

	for(i = 0 ; i<n;i++){
		set[i] = i+1;
	}
	/* prin_subset(n,set,1); */
	/* print_subset(n,set,0);	 */

	for(i = 0; i<=n;i++){ 
		memset(book,0,sizeof(book));
		/* print_set(0,i,set,n); */
		print_set_2(0,i,set,n);
	}

	return 0;
}
