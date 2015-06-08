/*************************************************************************
	> File Name: railway.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 15:55:34 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int *stack,
		top = -1;
	int *carriage,
		i;
	int flag = 1,
		step = 0;
		
	scanf("%d",&n);
	carriage = (int*)calloc(n+1,sizeof(int));
	stack = (int *)calloc(n+1,sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d",&carriage[i]);
	}
	
	for(i = 1; step<n  ;){
		if(top != -1 && carriage[step] < stack[top]){
			flag = 0;
			break;
		}
		if(top != -1 && stack[top] == carriage[step]){
			step ++;
			top --;
		}else{
			stack[++top] = i++;
		}
	}
	if(!flag){
		printf("No\n");
	}else{
		printf("Yes\n");
	}

	free(carriage);
	free(stack);
	return 0;
}
