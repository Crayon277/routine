/*************************************************************************
	> File Name: 2_simu_node.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Apr 28 16:59:15 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int data[101],
		right[101];
	int len,
		index,
		n,
		index_r;

	scanf("%d",&n);
	len = n;
	for(index = 1 ;index <= n; index++ ){
		scanf("%d",&data[index]);
		right[index] = index + 1;
	}
	
	right[len] = 0;
		for(index = 1; index <= len ; index ++){
			printf("%d ",data[index]);
		}
		printf("\n");
		for(index= 1; index<=len; index ++){
			printf("%d ",right[index]);
		}
		printf("\n");

	while(fflush(stdin),scanf("%d",&n)!=EOF){
	
		
		data[++len] = n; 

		index_r = 1;
		while(index_r){
			if(data[right[index_r]] > data[len]){
				right[len] = right[index_r];  // right[index_r]	相当于 index_r->next;
				right[index_r] = len;
				break;
			}
			index_r = right[index_r];
		}

		//不能单单这样，要遍历right数组，找到最后的一个元素，类似于单链表。	
		/* if(!index_r){ */
			/* right[len-1] = len; */
			/* right[len] = 0; */
		/* } */
		
		if(!index_r){
			for(index = len - 1 ;index >= 1; index--){
				if(right[index])
					continue;
				else{
					break;
				}
			}
			right[index] = len;
			right[len] = 0;
		}

		for(index = 1; index <= len ; index ++){

			printf("%d ",data[index]);
		}
		printf("\n");
		for(index= 1; index<=len; index ++){
			printf("%d ",right[index]);
		}
		printf("\n");

		for(index = 1; index !=0 ;index = right[index]){
			printf("%d ",data[index]);
		}
		
	}
	
}
