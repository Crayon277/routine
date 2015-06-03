/*************************************************************************
	> File Name: word_len.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 22:17:31 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 50


int main(){
	char *word[size][size];
	int i = 0,sum = 0;
	while(scanf("%s",word[i]) != EOF){
		sum += strlen(word[i]);
		i++;
	}
	printf("average len %lf\n",(double)sum/i);

	return 0;
}
