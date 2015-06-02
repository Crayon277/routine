/*************************************************************************
	> File Name: test.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 08:51:57 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int count = 0;
	printf("%d %d %d\n",count++,count++,count++);//0,1,2
	count = 1;
	count = count++;
	printf("%d\n",count);//1
	int i = 0,j = 0;
	int u[10] = {
		0
	},v[10] = {
		0
	};

	while(scanf("%d %d",&u[i++],&v[i]) != EOF){
	}

	for(j = 0 ;j <10; j++){
		printf("%d %d\n",u[j],v[j]);
		
	}
	return 0;
}
/* 
 *test :data
 1 1
 2 2
 3 3
 
 
 1 0
 2 1
 3 2
 0 3
 0 0
 0 0
 0 0
 0 0
 0 0
 0 0
 *
 * 第一个先赋值。
 * */ 
