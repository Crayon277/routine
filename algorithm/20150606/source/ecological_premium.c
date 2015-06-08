/*************************************************************************
	> File Name: ecological_premium.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 22:02:17 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	while(scanf("%d\n",&n) != EOF){
		while(n){
			int f;
			int size,number,env;
			int premium = 0;
			scanf("%d",&f);
			while(f){
				scanf("%d %d %d",&size,&number,&env);
				premium += size * env;
				f--;
			}
			printf("%d\n",premium);
			n--;
		}
	}

	return 0;
}
