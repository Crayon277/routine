/*************************************************************************
	> File Name: game_card.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 15:18:40 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define LEN 2048
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int seq[LEN];
		int head = 0,
			tail  = 0,
			i;
		for(tail = 0;tail < n; tail++){
			seq[tail] = tail+1;
		}
		while(head+2  != tail){
			printf("%d ",seq[head++]);
			seq[tail++] = seq[head++];
		}
		printf("%d %d\n",seq[head],seq[head+1]);
	}

	return 0;
}
