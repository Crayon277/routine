/*************************************************************************
	> File Name: strchr.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 10:12:23 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *my_strchr( char*str, int c){
	char *s = str;
	while((*s) != '\0'){
		if((*s) == c){
			return s;
		}
		s++;
	}
	return NULL;
}

char *my_strrchr(char *s, char c){
	int i = strlen(s);
	char *search = s+i-1;
	while(search != s){
		if((*search) == c){
			return search;
		}
		search--;
	}	
	return NULL;
}

int main(){
	char test[100];

	fgets(test,sizeof(test),stdin);
	char *first = my_strchr(test,'a');
	char *last = my_strrchr(test,'a');

	printf("test: %p\n",test);
	printf("first: %p\n",first);
	printf("last: %p\n",last);

	return 0;
}
