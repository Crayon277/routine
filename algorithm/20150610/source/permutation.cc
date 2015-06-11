/*************************************************************************
	> File Name: permutation.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun 11 10:50:28 2015
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,p[10];
	scanf("%d",&n);
	for(int i = 0 ;i <n; i++){
		scanf("%d",&p[i]);
	}
	sort(p,p+n);
	do{
		for(int i = 0;i<n;i++){
			printf("%d ",p[i]);
		}
		printf("\n");
	}while(next_permutation(p,p+n));
	return 0;
}
