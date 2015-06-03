/*************************************************************************
	> File Name: rotate.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 23:33:06 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define n 4

void rotate(int left_i,int left_j,int right_i,int right_j, char (*a)[n]){
	int l_i = left_i,
		l_j = left_j;

	char temp = a[left_i][left_j];
	while(l_j<right_j){
		a[l_i][l_j] = a[l_i][l_j+1];
		l_j++;
	}
	while(l_i < right_i){
		a[l_i][l_j] = a[l_i+1][l_j];
		l_i++;
	}
	while(l_j > left_j){
		a[l_i][l_j] = a[l_i][l_j-1];
		l_j--;
	}
	while(l_i>left_i+1){
		a[l_i][l_j] = a[l_i-1][l_j];
		l_i--;
	}
	a[l_i][l_j] = temp;
}

void print_array(char (*a)[n]){
	int i,j;
	for(i = 0 ;i<n;i++){
		for(j = 0;j<n;j++){
			printf("%3c",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	char rool[n][n] = {
		'1','2','3','a',
		'4','5','6','b',
		'7','8','9','c',
		'd','e','f','g'
	};

	int i,j,li,lj,ri,rj;//
	for(i = 0; i<n/2;i++){
		li = lj = i;
		
		ri = rj = n-1-i;
		//printf("pass\n");
		for(j = 0;j<n-1-i*2;j++){ // 最外圈转3次，然后里面的圈转1次，2递减
			rotate(li,lj,ri,rj,rool); //可以优化只传入0和n-1
			printf("pass\n");
			print_array(rool);
		}
	}

	for(i = 0;i<n;i++){
		for(j = 0 ;j<n;j++){
			printf("%3c",rool[i][j]);
		}
		printf("\n");
	}
	return 0;
}
