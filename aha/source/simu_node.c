/*************************************************************************
	> File Name: simu_node.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Apr 28 16:31:14 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int data[101],right[101];
	int len=0,index_d=0,index_r=0,n,tmp;
	scanf("%d",&n);
	tmp = n;
	while(tmp){
		scanf("%d",&data[index_d++]);
		len++;
		right[index_r++] = index_d;
		tmp--;
	}
	right[len-1] = 0;

	for(;tmp<n;tmp++){
		printf("%d ",data[tmp]);
	}
	printf("\n");

	for(tmp = 0; tmp<n;tmp++){
		printf("%d ",right[tmp]);
	}
	printf("\nwhat to insert : \n");
	
	scanf("%d",&tmp);
	
	data[len++] = tmp;

	for(index_d = 0;index_d < len ; index_d++){
		if(data[index_d] > tmp){
			break;
		}
	}

	if(index_d == len){
		right[len - 2] = len - 1;
		right[len - 1] = 0;
	    index_r++;	
	}else{
		right[len - 1] = index_d;
		right[index_d-1] = len-1;
	}

	for(tmp = 0; tmp < len ; tmp ++){
		printf("%d ",data[tmp]);
	}
	printf("\n");
	for(tmp = 0 ; tmp < len; tmp ++){
		printf("%d ",right[tmp]);
	}
	printf("\n");
	return 0;


}
