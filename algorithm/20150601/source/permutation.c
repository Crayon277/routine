/*************************************************************************
	> File Name: permutation.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 17:41:27 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int book[10];  /* book is using for check if the index-digit is used */ 
int a[10]; /* fill the blank */ 
void dfs(int step){
	int i;
	if(step == 10){
		int x = a[1] * 100 + a[2] * 10 + a[3];
		int y = a[4] * 100 + a[5] * 10 + a[6];
		int z = a[7] * 100 + a[8] * 10 + a[9];
		if(y / x  == 2 && y % x == 0 && z / x == 3 && z % x == 0){
			printf("%d%d%d;%d%d%d;%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
		}
		return;
	}

	for(i=1;i<10;i++){ // step is box index for inputing digit, i is digit candidate number
		if(book[i] == 0 ){
			a[step] = i;
			book[i] = 1;
			dfs(step+1);
			book[i] = 0;
		}
	}
}

int main(){
	int i;
	
	dfs(1);

	return 0;

}
