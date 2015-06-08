/*************************************************************************
	> File Name: fallingball.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 22:46:03 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 10500000
int balltree[size] = {
	0
};
int main(){
	int Depth,ballNum;
	int i,id,leafnode;
	
	scanf("%d %d",&Depth,&ballNum);
	id = (int)pow(2,Depth)-1;
	leafnode = (int)pow(2,Depth-1);

	for(i=1;i<=ballNum;i++){
		int path = 1;
		while(path < leafnode){
			if(balltree[path] == 0){
				balltree[path] = 1;
				path = path*2;
			}else{
				balltree[path] = 0;
				path = path*2 +1;
			}
		}
		if(i == ballNum){
			printf("%d\n",path);
		}
	}
	
	return 0;
}
