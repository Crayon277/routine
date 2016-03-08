/*************************************************************************
	> File Name: 1096.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 13:16:43 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i;
		for(i=0;i<n;i++){
			int sum=0,m,t;
			int j;
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d",&t);
				sum+=t;
			}
			printf("%d\n",sum);
			if(i!=n-1){
				printf("\n");
			}
		}
	}
	return 0;
}
