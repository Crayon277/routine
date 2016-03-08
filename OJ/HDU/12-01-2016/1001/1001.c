/*************************************************************************
	> File Name: 1001.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jan 12 12:06:37 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	while(~scanf("%d",&n)){
		int i,sum=0;
		for(i=1;i<=n;i++){
			sum+=i;
		}
		printf("%d\n\n",sum);
	}
	return 0;
}
