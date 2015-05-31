/*************************************************************************
	> File Name: node.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Apr 28 15:27:58 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}node,*pnode;

int main(){
	pnode head = NULL,tail = NULL,ptemp = NULL;

	int n;
	scanf("%d",&n);
	while(n){
		ptemp = (pnode)calloc(0,sizeof(node));
		scanf("%d",&(ptemp->data));
		if(head == NULL){
			head = ptemp;
		}else{
			tail->link = ptemp;
		}
		tail = ptemp;
		n--;
	}
	/* tail->link = NULL; */
	ptemp = head;
	while(ptemp!=NULL){
		printf("%d ",ptemp->data);
		ptemp = ptemp->link;
	}

	return 0;
}
