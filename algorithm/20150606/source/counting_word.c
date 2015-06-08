/*************************************************************************
	> File Name: counting_word.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 23:43:33 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	char ch ;
	int begin = 0;
	int count = 0;
	while((ch = getchar()) != EOF){
		if(ch == '\n'){
			printf("%d\n",count);
			begin = 0;
			count = 0;
		}
		if(!isalpha(ch) && begin == 1){
			count ++;
			begin = 0;
		}
		if(isalpha(ch) && begin == 0){
			begin = 1;
		}
		
	}

	return 0;

}
