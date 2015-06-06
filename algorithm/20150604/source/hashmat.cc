/*************************************************************************
	> File Name: hashmat.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 22:00:14 2015
 ************************************************************************/

#include<cstdio>
#include<cmath>

int main(){
	// int a,b; //trap 1: 2^32, > max(int can denote)
	long long a,b;
	while(scanf("%d %d",&a,&b) !=EOF){
		if(b>a){
			printf("%d\n",b-a);
		}else{
			printf("%d\n",a-b);
		}
	}
	return 0;
}
