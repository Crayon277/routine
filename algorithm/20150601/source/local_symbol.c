/*************************************************************************
	> File Name: local_symbol.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 10:50:48 2015
 ************************************************************************/
/* #define LOCAL */  //as well using precompile -D=LOCAL option
#include<stdio.h>
#include<stdlib.h>

#define INF 99999999
int main(){
	int count,min,max,i,sum;
	/* double sum,min,max,i; */
	#ifdef LOCAL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	#endif
	min = INF;
	max = -INF;
	sum = 0;
	count = 0;
	while(scanf("%d",&i) != EOF){
		sum += i;
		count ++;
		if(min > i){
			min = i;
		}
		if(max < i){
			max = i;
		}
		/* printf("%d \n",sum); */
	}

	printf("%d %d %.3lf\n",min,max,(double)sum/count);

	return 0;
}
