/*************************************************************************
	> File Name: huiwen_book.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 09:32:34 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAXN 500+10

char buf[MAXN],s[MAXN];
int p[MAXN];

int main(){
	int n,m = 0,max = 0,x,y;
	int i,j;
	fgets(buf,sizeof(s),stdin);
	clock_t t1 = clock();

	n = strlen(buf);
	for(i = 0;i<n;i++){
		if(isalpha(buf[i])){
			p[m] = i;
			s[m++] = toupper(buf[i]);
		}
	}
	for(i = 0;i<m;i++){//i是回文的中间位置
		for(j = 0; i-j >= 0 && i+j < m; j++){ // j 是离i的相对距离 , 回文是奇数时候
			if(s[i-j] != s[i+j])
				break;
			if(j*2+1 > max){
				max = j*2+1;
				x = p[i-j];
				y = p[i+j];
			}
		}
		for(j = 0;i-j >= 0 && i+j+1 < m;j++){ // 回文是偶数时候。
			if(s[i-j]!=s[i+j+1]) // j从0开始的，s[i] ?= s[i+1] abccba,偶数时相邻的c是否相等
				break;
			if(j*2+2 > max){
				max = j*2+2;
				x = p[i-j];
				y = p[i+j+1];
			}
		}
	}
	for(i = x;i<=y ; i++){
		printf("%c",buf[i]);
	}
	clock_t t2 = clock();

	printf("\nTime used %.7lf\n",(double)(t2-t1)/CLOCKS_PER_SEC); //0.0000700 比我的思路快

	printf("\n");

	return 0;

