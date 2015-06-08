/*************************************************************************
	> File Name: linklist.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 21:17:55 2015
 ************************************************************************/
/* #define DEBUG */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	struct node*pre;
	int elem;
	struct node*link;
}Ball,*pBall;

int main(){
	int n,m;
	char cmd[10];
	scanf("%d",&n);
	pBall phead = (Ball*)calloc(1,sizeof(Ball)),
		  ptail = phead,
		  psearch1,
		  psearch2;
	int i;
	for(i = 1; i<=n ; i++){
		pBall pnew = (Ball*)calloc(1,sizeof(Ball));
		pnew->elem = i;
		pnew->pre = ptail;
		ptail->link = pnew;
		ptail = pnew;
	}
	scanf("%d",&m);
	#ifdef DEBUG
	for(psearch1 = phead->link; psearch1 != NULL;psearch1 = psearch1->link){
		printf("%d ",psearch1->elem);
	}
	printf("\n");
	#endif
	while(m){
		int temp;
		scanf("%s",cmd);

		psearch1 = phead->link;
		psearch2 = phead->link;
		while(psearch1->elem != (cmd[1]-'0') && psearch1!=NULL){
			psearch1 = psearch1->link;
		 }
		while(psearch2->elem != (cmd[2]-'0') && psearch2!=NULL){
			psearch2 = psearch2->link;
		}
		switch(cmd[0]){
			case 'A':psearch1->pre->link = psearch1->link;
					 psearch1->link->pre = psearch1->pre;
					 psearch1->link = psearch2;
					 psearch2->pre->link = psearch1;
					 psearch1->pre = psearch2->pre;
					 psearch2->pre = psearch1;
					 break;
			case 'B':psearch1->pre->link = psearch1->link;
					 psearch1->link->pre = psearch1->pre;
					 psearch1->link = psearch2->link;
					 psearch2->link = psearch1;
					 psearch2->link->pre = psearch1;
					 psearch1->pre  = psearch2;
		}
		m--;
	}
	for(psearch1 = phead->link; psearch1!=ptail; psearch1 = psearch1->link){
		printf("%d ",psearch1->elem);
	}
	printf("%d\n",ptail->elem);

	psearch1 = phead;
	psearch2 = phead;
	while(psearch1 != NULL && psearch2 != NULL){
		psearch1 = psearch2;
		psearch2 = psearch2->link;
		free(psearch1);
	}
	for(psearch1 = phead->link; psearch1!=ptail; psearch1 = psearch1->link){
		printf("%d ",psearch1->elem);
	}
	printf("%d\n",ptail->elem);
	return 0;
}
