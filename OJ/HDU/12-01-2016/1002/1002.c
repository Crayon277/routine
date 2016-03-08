/*************************************************************************
	> File Name: 1002.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jan 12 12:41:17 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int count=1;
	int n;
	scanf("%d",&n);
	while(n--){
		unsigned long long a,b;
		scanf("%ulld%ulld",&a,&b);
		printf("Case %d:\n",count++);
		printf("%ulld + %ulld = %ulld\n\n",a,b,a+b);
	}
	return 0;
}
