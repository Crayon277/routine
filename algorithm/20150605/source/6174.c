/*************************************************************************
	> File Name: 6174.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jun  5 15:11:25 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define size 1000
int smalltobig(int cur){
	int a[4];
	int i,j= 4;
	int ret = 0,min,index;
	for(i = 0; i< 4;i++){
		a[i] = cur%10;
		cur/=10;
	}
	while(j>0){
		min = 10;
		for(i = 0;i<4;i++){
			if(min > a[i]){
				index = i;
				min = a[i];
			}
		}
		a[index] = 10;
		ret = ret * 10 + min;
		j--;
	}

	return ret;
}

int bigtosmall(int a){//reverse small to big
	int i;
	int ret = 0;
	for(i = 0 ;i<4;i++){
		ret = ret * 10 + a%10;
		a/=10;
	}

	return ret;
}



int main(){
	int cur; // 当前的数字
	int produce[size],p_i = 0;
	scanf("%d",&cur);
	produce[p_i++] = cur;

	while(1){
		int small = smalltobig(cur);
		int big = bigtosmall(small);
		/* printf("%d %d\n",big,small); */
		int search = p_i-1,flag = 0;

		cur = big - small;
		while(search>=0){ // 不采用插入排序，直接就是比较
			if(produce[search] ==  cur){
				flag = 1;
				break;
			}
			search--;
		}
		if(flag){
			printf("%d is itself again\n",cur);
			break;
		}else{
			produce[p_i++] = cur;
		}
	}
	return 0;
}
