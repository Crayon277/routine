/*************************************************************************
	> File Name: TeX.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 09:08:42 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int flag = 0;
	char s[100];
	fgets(s,sizeof(s),stdin);
	/* printf("%s\n",s); */
	/* return 0; */
	int i;
	for(i = 0;s[i];i++){
		if(s[i] == 34){
			if(!flag){
				putchar(96);
				putchar(96);
				flag = !flag;
			}else{
				putchar('~');
				putchar('~');
				flag = !flag;
			}
		}else{
			putchar(s[i]);
		}
	}
	return 0;
}
