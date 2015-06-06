/*************************************************************************
	> File Name: qwerty.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 08:55:50 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	const char *s = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; /* \\要转义 */ 
	int ch,i;
	while((ch = getchar()) != EOF){
		for(i = 0 ; s[i] && s[i]!=ch;i++);
		if(s[i]){
			//思维，打错了是q 弄成 w， 所以打印出原来的是往前。i-1,而不是i+1
			putchar(s[i-1]);
		}else{ //找不到就打印原来的，比如空格。
			putchar(ch);
		}
	}
	printf("\n");

	return 0;

}
