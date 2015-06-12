/*************************************************************************
	> File Name: prime_circle.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jun 12 11:38:36 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 

#define size 100
int isp[size];
int pc[size];
int vis[size];

int isprime(int n){
	for(int i = 2; i <= (int)sqrt(n) ; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

void init_isp(int n){
	for(int i = 2; i <= n*2; i++){//为什么n*2 因为判断的是相加的。
		isp[i] = isprime(i);
	}
}

void dfs(int n,int cur){
	if(cur == n && isp[pc[0] + pc[n-1]]){
		for(int i = 0 ; i<n;i++){
			printf("%d ",pc[i]);
		}
		printf("\n");
		return ;
	}
	for(int i = 2 ; i<= n;i++){//从1开始的话，会有问题，pc［0］放不进去了
		if(!vis[i] && (isp[i + pc[cur-1]])){ 
			vis[i] = 1;
			pc[cur] = i;
			dfs(n,cur+1);
			vis[i] = 0;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	init_isp(n);
	isp[1]=1;
	pc[0]=1;
	dfs(n,1);
	return 0;
}
