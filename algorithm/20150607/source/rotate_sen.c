/*************************************************************************
	> File Name: rotate_sen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 09:30:49 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 105
int main(){
	char word[size][size];

	int n = 0,i,j,maxlen = 0;
	while(fgets(word[n],size,stdin)){
		if(maxlen < strlen(word[n])){
			maxlen = strlen(word[n]);
		}
		n++;
	}
	for(i = 0; i < maxlen-1;i++){
		for(j = n-1;j>=0;j--){
			/* if(word[j][i] != '\n' && word[j][i]){ */
				/* printf("%c",word[j][i]); */
			/* } */
			if(i<strlen(word[j])-1){ // strlen(word[j]) -1 had been written to strlen(word[j] - 1) reckless
				printf("%c",word[j][i]);
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
