/*************************************************************************
	> File Name: precision.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 09:44:48 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	long long n; // Not int for a reason. see L19
	int count = 0;
	scanf("%lld",&n);


	while(n > 1){
		if(n % 2 == 1){
			n = (n*3+1)/2;  // careful of overflow, test data 987654321 will reach that error
			count +=2;

		}else{
			n /= 2;
			count ++;
		}
	}

	printf("%d\n",count);
	return 0;
}
