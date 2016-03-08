/*************************************************************************
	> File Name: ungetc_test.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 13:10:30 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	char ch;
	int num;
	while((ch=getchar())!='\n'){
		if(ch==' '){
			continue;
		}
		ungetc(ch,stdin);
		scanf("%d",&num);
		printf("%d ",num);
	}

	return 0;
}
