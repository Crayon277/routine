/*************************************************************************
	> File Name: kunnanchuan.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun 13 07:57:35 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

char chuan[MAX];
void dfs(int cur,int l, int n,int cnt){
	if(cnt++ == n){
		printf("%s\n",chuan);
		return ;
	}
	for(int i = 0;i<l;i++){
		 int flag = 1;
		 chuan[cur] = 'A'+i;
		 //test if valid
		 for(int j = 1; j *2 <= cur+1;j++){
			 int e = 1;
			 for(int k = 0; k<j;k++){
				 if(chuan[cur-k] != chuan[cur-j-k]){//不能用＝＝比较，如果ABCB,B都相等，但是A,C不相等
					e = 0;//legal
					break;
				 }
			 }
			if(e){//illegal
				 flag = 0;
				 break;
			 }
		 }
		 if(flag){
			 dfs(cur+1,l,n,cnt);
		 }
	}
}

int main(){
	int n,l,cnt = 0;
	scanf("%d%d",&n,&l);
	dfs(0,l,n,cnt);

	return 0;
}
