/*************************************************************************
	> File Name: falling.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  8 08:57:20 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int depth,balls;
	while(scanf("%d %d",&depth,&balls) != EOF){
		int leafnode = 1;
		int i;
		for(i = 1; i<=depth-1;i++){
			if(balls & 1){
				leafnode *= 2;
				balls = (balls+1)/2;
			}else{
				leafnode = leafnode*2+1;
				balls = balls/2;
			}
		}
		printf("%d\n",leafnode);
	}
	return 0;
}
