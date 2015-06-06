/*************************************************************************
	> File Name: decToany.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 08:23:44 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int main(){
	int base,dec;
	scanf("%d %d",&base,&dec);
	int remain,i = 0;
	char res[50];
	assert(base<=16);
	while(dec != 0){
		switch(dec%base){
			case 15:res[i++] = 'F';break;
			case 14:res[i++] = 'E';break;
			case 13:res[i++] = 'D';break;
			case 12:res[i++] = 'C';break;
			case 11:res[i++] = 'B';break;
			case 10:res[i++] = 'A';break;
			default:res[i++] = dec%base+'0';
		};
		dec /= base;
	}
	i--;
	while(i>=0){
		printf("%c",res[i]);
		i--;
	}
	printf("\n");
	return 0;

}

