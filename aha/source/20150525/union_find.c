/*************************************************************************
	> File Name: union_find.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue May 26 11:29:32 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define crime 10
#define clue 9

int main(){
	int u,v;
	int group[11];
	int book[11];
	int i,t;

	for(i = 1 ; i<= 10 ; i++){
		group[i] = i;
		book[i] = 1;
	}

	/* for(i=1; i <= clue ; i++){ */
	while(scanf("%d %d\n",&u,&v) != EOF){
		/* scanf("%d %d",&u,&v); */

		if(u > v){ //每次就是把group[u]中的当作老大
			u ^= v;
			v ^= u;
			u ^= v;
		}
		
		book[u] = 0;
		book[v] = 0;

		if(group[v] != v){ // 如果不想等，说明已经有老大，要将老大也归顺过去
			t = group[v];
			group[v] = group[u];
			v = t;
			//下面一步很关键
			book[v] = 0; //这时v就是原来的老大，因为要归顺了，老大也就不能当了。置0，
		}

		group[v] = group[u];
		book[group[u]] = 1;
	}
	t = 0;
	for(i = 1;i<=crime;i++){
		printf("%d ",group[i]);
		t+= book[i];
	}
	printf("All group is %d\n",t);
	printf("\n");

	return 0;
}
