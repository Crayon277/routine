/*************************************************************************
	> File Name: hanxin.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 15:28:38 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	for(i = 10; i<=100; i++){
		if(i % 3 == a && i% 5 == b && i % 7 == c){
			printf("%d\n",i);
			return 0;
		}
	}
	printf("No answer\n");
	return 0;
}
