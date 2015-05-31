/*************************************************************************
	> File Name: 2_simu_poke.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Apr 27 11:41:24 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct queue{
	int data[1000];
	int head;
	int tail;
};

struct stack{
	int data[10];
	int top;
};

int main(){
	struct queue q1,q2;
	struct stack s;

	int book[10];

	int i,t;

	q1.head = q1.tail = q2.head = q2.tail = 1;
	s.top = 0;

	for(i = 1; i<= 9 ;i++){
		book[i] = 0;
	}
	for(i = 1; i <= 6; i++){
		scanf("%d",&q1.data[q1.tail++]);
	}
	for(i = 1; i <= 6; i++){
		scanf("%d",&q2.data[q2.tail++]);
	}

	while(q1.head < q1.tail && q2.head < q2.tail){
		t = q1.data[q1.head];
		if(!book[t]){
			q1.head ++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else{
			q1.head ++;
			q1.data[q1.tail] = t;
			q1.tail ++;

			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;//桌子上的牌肯定都是不一样的，如果出现一样的话就会回收，book数组最大的值就是1
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
			/* book[t] = 0; */
			/* q1.data[q1.tail++] = s.data[s.top--]; // 这步是将相等的那张牌取出来 */
		}

		t = q2.data[q2.head];
		
		if(!book[t]){
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}else{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while(s.data[s.top]!=t){
				book[s.data[s.top]] = 0; //这个目的是回收两个相等卡片之间的所有卡片，所以这里出现过的要再book数组置0
				q2.data[q2.tail++] = s.data[s.top--];
			}	
			/* book[t] = 0; //这一步不要忘了。 */
			/* q2.data[q2.tail++] = s.data[s.top--]; */
		}
	}

	if(q2.head == q2.tail){
		printf("q1 win\n");
		printf("q1 have: \n");
		for(i = q1.head ; i <= q1.tail-1; i++){
			printf("%d ",q1.data[i]);
		}
		printf("desktop have:\n");
		for(i = 1; i<=s.top;i++){
			printf("%d ",s.data[i]);
		}
	}else{
		printf("q2 win\n");
		printf("q2 have: \n");
		for(i = q2.head ; i <= q2.tail-1; i++){
			printf("%d ",q2.data[i]);
		}
		printf("desktop have:\n");
		for(i = 1; i<=s.top;i++){
			printf("%d ",s.data[i]);
		}
	}

	return 0;
	
}
