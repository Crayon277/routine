/*************************************************************************
	> File Name: twin_prime.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 11:35:12 2015
 ************************************************************************/
#define IMPROVE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

/* do NOT use this if candidate is very large or small */ 

int if_prime(int candidate){
	int i;
	for(i = 2; i< sqrt(candidate) ;i++){ // if candidate = 1, it will pass this sentence, and return 1. But 1 is not prime 
//  for(i = 2; i*i <= candidate;i++)  这是书上的写法，当candidate很大的时候，i*i 有可能会溢出。
//  如果n是一个接近int的最大值素数，则当循环到i = 46340时i*i = 2147395600 < n 但i = 46341 时 i*i ＝ 2147488281 ，超过了int
//  的最大值，溢出变为负数，但是仍然满足i*i < n
		if(candidate % i == 0){
			return 0;
		}
	}
	return 1;
}

#ifdef IMPROVE
int is_prime(int x){
	int i, m;
	assert(x>=0);
	if(1==x){
		return 0;
	}
	m = floor(sqrt(x) + 0.5);
	for(i =2 ;i <= m;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
#endif

int main(){
	int m,i;
	scanf("%d",&m);

	for(i = m;i>=5;i--){
		if(if_prime(i) && if_prime(i-2)){
			printf("%d,%d\n",i,i-2);
			return 0;
		}
	}

}
