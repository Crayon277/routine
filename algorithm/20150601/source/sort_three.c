/*************************************************************************
	> File Name: sort_three.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 08:46:24 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a,b,c,t;
	int x,y,z;
	scanf("%d %d %d",&a,&b,&c);

	if(a > b){
		t = a;
		a = b;
		b = t;
	}
	//if compare b and c first , what will happen? (Wrong!!)
	// 2 3 1 . The result is 2 1 3. We expect 1 2 3. 
	if(b > c){
		t = b;
		b = c;
		c = t;
	}
	if(a > c){
		t = a;
		a = c;
		c = t;
	}

	printf("%d %d %d\n",a,b,c);
	//Other solutino
	x = a ; if(b < x) x = b; if(c < x) x = c; // x = min
	z = a ; if(b > z) z = b; if(c > z) z = c; // z = max
	y = a+b+c - x -z;	
	printf("%d %d %d\n",x,y,z);
	return 0;
}
