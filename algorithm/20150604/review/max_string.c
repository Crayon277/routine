/*************************************************************************
	> File Name: max_string.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 09:41:48 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char s[100];
	fgets(s,100,stdin); //fgets will keep '\n'
	/* printf("%s : %d\n",s,strlen(s)); */
	int ptail,n = 1,
		i,j;
	while(s[n] != '\n'){
		if(s[n] == s[0]){
			int flag = 0;
			ptail = n;
			for(i = 0,j=n;s[j] != '\n';i++,j++){
				if(s[i] != s[j]){
					flag = 1;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		n++;
	}

	printf("min cycle :%d\n",n);
}
