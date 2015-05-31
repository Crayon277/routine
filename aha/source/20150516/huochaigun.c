/*************************************************************************
	> File Name: huochaigun.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 16 18:29:46 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int stick_count[10] = {
	6,2,5,5,4,5,6,3,7,6
};


int theStickNum(int x){
	int num = 0;
	
	while(x / 10 ){
		num += stick_count[x%10];
		x /= 10;
		//printf("%d pass\n",x);
		/* printf("pass\n"); */
	}
	num += stick_count[x];
	return num;
}

int main(){
	int stick;
	int i,j,k;
	printf("How many sticks in total? ");
	scanf("%d",&stick);
	
	for(i = 0; i < 11111; i ++){
		for(j = 0 ;j < 11111;j++){
			k = i+j;
			if(theStickNum(i) + theStickNum(j) + theStickNum(k) == stick - 4){
				printf("%d + %d = %d\n",i,j,k);
			}
		}
	}
	/* printf('\n'); */
	return 0;
}
