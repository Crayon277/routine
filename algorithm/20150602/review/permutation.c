/*************************************************************************
	> File Name: permutation.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 08:18:57 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// *** *** *** filled by 123456789, require that abc : def: ghi = 1:2:3 
int main(){
	int i;
	int s[10];

	int flag = 0;
	for(i = 123; i<= 987/3 ; i++){
		int j;
		int a = i;
		int b = i * 2;
		int c = i * 3;
		memset(s,0,sizeof(s));
		s[a/100] = s[a/10%10] = s[a%10] = 1;
		s[b/100] = s[b/10%10] = s[b%10] = 1;
		s[c/100] = s[c/10%10] = s[c%10] = 1;
		flag =0 ;
		
		for(j = 1; j<=9;j++ ){
			if(s[j] == 0) {
				flag = 1;
				break;
			}
		}
		if(1 == flag){
			continue;
		}else{
			printf("%d,%d,%d\n",a,b,c);
		}

	}

	return 0;
}
