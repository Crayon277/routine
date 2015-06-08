/*************************************************************************
	> File Name: cantor_book.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 11:57:44 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		int k = 1,s = 0;
		for(;;){
			s+=k;
			if(s>=n){
				printf("%d/%d\n",s-n+1,k-s+n);
				break;
			}
			k++;
		}
	}
	return 0;
}
