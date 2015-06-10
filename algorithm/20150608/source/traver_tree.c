/*************************************************************************
	> File Name: traver_tree.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  8 10:10:47 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 256

typedef struct node{
	int if_assign;
	int value;
	struct node*lchild,*rchild;
}TNode,*pTnode;

pTnode root;

void add_node(int v,const char *s,pTnode root){
	int end = strlen(s)-1;
	int i;
	pTnode traver = root;
	for(i = 0; i < end;i++){
		if(s[i] == 'L'){
			if(!traver->lchild){
				pTnode new = (pTnode)calloc(1,sizeof(TNode));
				traver->lchild = new;
			}
			traver = traver->lchild;
		}
		if(s[i] == 'R'){
			if(!traver->rchild){
				pTnode new = (pTnode)calloc(1,sizeof(TNode));
				traver->rchild = new;
			}
			traver = traver->rchild;
		}
	}
	
	if(traver->if_assign){
		printf("error. reassign\n");
	}else{
		traver->value = v;
		traver->if_assign = 1;
	}
}

int read_input(pTnode root){
	char s[max+10];
	root = (pTnode)calloc(1,sizeof(TNode));
	while(1){
		if(scanf("%s",s) == EOF){
			return 0;
		}
		if(!strcmp(s,"()")){
			break;
		}
		int v;
		sscanf(&s[1],"%d",&v);
		add_node(v,strchr(s,',')+1,root);
	}
	return 1;
}

void remove_root(pTnode root){
	if(root == NULL){
		return ;
	}
	remove_root(root->lchild);
	remove_root(root->rchild);
	free(root);
}

int main(){
	pTnode seq[270];
	int	  head = 0,
		  tail = 1;
	while(read_input(root)){
	//	pTnode psearch = root;
		head = 0;
		tail = 0;
		seq[tail++] = root;
		while(head != tail){
			if(!seq[head]->if_assign){
				printf("Not assigned\n");
				return 0;
			}
			printf("%d ",seq[head]->value);
            if(seq[head]->lchild){
				seq[tail++] = seq[head]->lchild;
			}
			if(seq[head]->rchild){
				seq[tail++] = seq[head]->rchild;
			}
			head++;
		}
		printf("\n");
		remove_root(root);
	}

	return 0;
}
