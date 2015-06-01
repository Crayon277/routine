/*************************************************************************
	> File Name: decimal.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 17:24:45 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(){
	int a,b,c,i,f,t;
	scanf("%d %d %d",&a,&b,&c);
	//Option 1
	printf("%.*lf\n",c,(double)a/b);	
	
	Option 2
	printf("%d.",a/b);
	for(i = 1; i< c;i++){
		a = a%b; // 这两步模拟除法
		a *= 10;
		printf("%d",a/b);
	}
	//第c位涉及四舍五入，要特殊处理！！
	a = a%b;
    a*=10;
	t = a/b;
	//第c＋1位
	a = a%b;
	a*=10;
	f = a/b;
	if(f>5){
		printf("%d",t+1);
	}
	else{
		printf("%d",t);
	}
	printf("\n");
	return 0;
}
