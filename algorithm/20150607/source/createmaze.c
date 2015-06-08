/*************************************************************************
	> File Name: createmaze.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 11:21:54 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 140
#define arr 2048
#define increment 1000
int main(){
	char maze[size];
	int newarr = 1,leng,arr_index = 0;
	char * output;
	while(fgets(maze,size,stdin) != NULL){
		if(newarr){
			output = (char *)calloc(arr,sizeof(char));
			leng = arr;
			arr_index = 0;
			newarr = 0;
		}
		if(maze[0] == '\n'){
			printf("%s",output);
			printf("\n");
			free(output);
			newarr = 1;
		}
		int len = strlen(maze)-1;

		int i,sum = 0;
		for(i = 0;i<len;){
			sum = 0;
			while(isdigit(maze[i])){
				sum+=maze[i]-'0';
				i++;
			}
			switch(maze[i]){
				case 'b':while(sum) {
							if(arr_index>=leng-1){
								output = (char *)realloc(output,(leng+increment)*sizeof(char));
								leng +=increment;	
							}
							output[arr_index++] = ' ';
							sum--;
						 }break;
				case '!':if(arr_index>=leng-1){
							 output = (char *)realloc(output,(leng+increment)*sizeof(char));
							 leng += increment;
						 }
						 output[arr_index++] = '\n';break;
				default: while(sum){
							 if(arr_index>=leng-1){
								output = (char *)realloc(output,(leng+increment)*sizeof(char));
								leng +=increment;
							 }
							 output[arr_index++] = maze[i];
							 sum--;
						 }break;
			}
			
			i++;
		}
		if(arr_index>=leng-1){
			 output = (char *)realloc(output,(leng+increment)*sizeof(char));
			 leng += increment;
		 }
		output[arr_index++] = '\n';
		
	}

	return 0;
}
