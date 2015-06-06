/*************************************************************************
	> File Name: min_cycle.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 10:35:19 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char word[100];
	scanf("%s",word);
	int len = strlen(word);
	for(int i = 1;i <= len;i++) if(len%i == 0) //确保周期是合法的，周期的n倍一定是字符串长度
	{
		int ok = 1;
		for(int j = i ; j< len ;j++){
			if(word[j] != word[j%i]){ //i是周期长度
				ok = 0;
				break;
			}
			if(ok){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
