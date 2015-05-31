/*************************************************************************
	> File Name: word_cnt.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Apr 21 16:49:33 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int word_cnt(char* str){
	int cnt = 0;
	int index = 0;
	
	while(str[index] != '\n' && str[index]){

		while(isspace(str[index]) && str[index] != '\n'){
			index++;
		}
		if(str[index] != '\n'){
			cnt ++;
		}
		while(isalpha(str[index]) && str[index] != '\n'){
			index++;
		}
		
		/* printf("pass\n"); */
	}	
	

	return cnt;
}

int main(int argc, char ** argv){
	FILE* fd;
	/* printf("%s",argv[1]); */
	fd = fopen(argv[1],"r");
	
	char str[256];
	int sum = 0;

	while(memset(str,0,256),fgets(str,256,fd)){
		/* printf("%s",str); */
		sum +=word_cnt(str);
	}

	printf("%d words in %s",sum , argv[1]);
	return 0;
	
}
