/*************************************************************************
	> File Name: cantor.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 11:26:42 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int sum(int i){
	return (1+i)*i/2;
}

int main(){
	int n;
	while(scanf("%d",&n) !=EOF){
		int i=1;
		while(n > sum(i)){
			i++;
		}
		if(!(i & 1)){
			printf("%d/%d\n",n-sum(i-1),i-n+sum(i-1)+1);
		}else{
			printf("%d/%d\n",i-n+sum(i-1) + 1,n-sum(i-1));
		}
	}
	return 0;
}
