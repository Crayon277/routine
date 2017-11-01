/*************************************************************************
	> File Name: buildbinarytree.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Oct 31 15:23:09 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 256;

typedef struct TreeNode{
	int val;
	struct TreeNode * lchild;
	struct TreeNode * rchild;
}TreeNode,*BiTree;

void visit(int val){
	printf("%d ",val);
}

void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T->val);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T->val);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T->val);
	}
}



void levelOrder(BiTree T){
	int array [SIZE] = {-1};	
	int index = 0;
	array[index] = T->val;
	while(array[index]!= -1){
		
	}
}

void buildBiTreeFromPreOrderAndInOrder()


int main(){
	
}


