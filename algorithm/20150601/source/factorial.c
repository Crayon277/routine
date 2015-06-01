/*************************************************************************
	> File Name: factorial.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 09:54:04 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main(){
	const int MOD = 1000000;
	int i,j,factorial = 1, n,sum;
	scanf("%d",&n);
	for(i = 1;i<=n;i++){
		factorial = factorial * i % MOD; // factorial also will be overflowed . It have to % MOD
		sum = (sum + factorial) % MOD;
		/* printf("%d  %d\n",factorial,sum); */
	}
	//25!的末尾有6个0，所以从第5项开始，后面的所有项都不会影响和的末6位数字
	//因为26！就是25!*6, 25!后面六个0随便乘以什么还是6个零，所以这后面的末6位都是6个零了。

	printf("%d\n",sum);
	return 0;
}
