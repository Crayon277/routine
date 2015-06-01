/*************************************************************************
	> File Name: stat.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 15:41:02 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,m,i,j,count;
	#ifdef REDIRECTION
	freopen("stat.in","r",stdin);
	freopen("stat.out","w",stdout);
	#endif
	scanf("%d\n",&n);
	scanf("%d\n",&m);
	count = 0;
	for(i = 0; i< n;i++){
		scanf("%d",&j);
		if(j < m){
			count++;
		}
	}
	
	printf("%d\n",count);
	return 0;
}
