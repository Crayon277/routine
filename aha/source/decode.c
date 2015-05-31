/*************************************************************************
	> File Name: decode.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 27 08:13:19 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void move_left(int *a, int begin,int end, int step){
	 int index = begin;
	 while(index<= end){
		a[index-step] = a[index];
		 index++;
	 }
}

int main(){
	int pwd[10] = {
		0,6,3,1,7,5,8,9,2,4
	};
	int decode[10] ={
		0
	};

	int index = 1;
	int len = 9;
	int index_de = 1;
	while(index = 1, len){
		decode[index_de++] = pwd[index++];
		len--;
		if(len >=2){
			pwd[0] = pwd[index++];
			move_left(pwd,index,index+len-2,2);
			pwd[index+len-3] = pwd[0]; 
		}
		if(len == 1){
			pwd[1] = pwd[index];
		}
	}
	for(index_de = 1; index_de <= 9;index_de ++){
		printf("%d ",decode[index_de]);
	}

	return 0;

}
