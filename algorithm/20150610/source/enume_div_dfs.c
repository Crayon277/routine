/*************************************************************************
	> File Name: enume_div_dfs.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun 10 09:13:50 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int book[10];
int divi[10];
int n;
void dfs(int step){
	if(step == 10){
		int divisor = divi[0]*10000+ divi[1]*1000+divi[2]*100+divi[3]*10+divi[4];
		int dividend= divi[5]*10000+ divi[6]*1000+divi[7]*100+divi[8]*10+divi[9];
		if(dividend == divisor * n){//can't do this: dividend / divisor == n
			printf("%d / %d = %d\n",dividend,divisor,n);
		}
	}
	int i;
	for(i = 0 ;i<=9;i++){
		if(book[i]){
			continue;
		}
		book[i] = 1;
		divi[step]= i;
		dfs(step+1);
		book[i] = 0;
	}
}

int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}
