/*************************************************************************
	> File Name: all_permutation.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat May 16 19:39:58 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


void permutation(int current,int input_num,int *Box,int*book){
	int i;
	
	if(current == input_num+1){
		for(i = 1;i <= input_num ;i++){
			printf("%d",Box[i]);
		}
		printf("\n");
		return;
	}

	for(i = 1; i<= input_num ;i++){
		if(book[i] == 0){
			Box[current] = i;
			book[i] = 1;
			permutation(current+1,input_num,Box,book);
			book[i] = 0;
		}
	}
}
void threeofthree_add(int current,int input_num,int *Box,int*book){
	int i;
	
	if(current == input_num+1 && (Box[1]*100 + Box[2]*10+Box[3] + Box[4]*100+Box[5]*10+Box[6] )==(Box[7]*100+Box[8]*10+Box[9]) ){
		printf("%d%d%d + %d%d%d = %d%d%d",Box[1],Box[2],Box[3],Box[4],Box[5],Box[6],Box[7],Box[8],Box[9]);
		printf("\n");
		return;
	}

	for(i = 1; i<= input_num ;i++){
		if(book[i] == 0){
			Box[current] = i;
			book[i] = 1;
			permutation(current+1,input_num,Box,book);
			book[i] = 0;
		}
	}
}


int main(){
	int input_num = 0,
		front_of_box = 1;
	int book[10] = {
		0
	};
	int Box[10] ={
		0
	};


	scanf("%d",&input_num);
	/* permutation(front_of_box,input_num,Box,book); */
	threeofthree_add(front_of_box,input_num,Box,book);
	return 0;
}
