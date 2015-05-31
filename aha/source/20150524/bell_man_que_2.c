/*************************************************************************
	> File Name: bell_man_que.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun May 24 20:58:37 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define inf 99999999
#define vertex 5
#define edge 7

int main(){
	int dis[vertex] = {
		0,inf,inf,inf,inf
	};
	int book[vertex]={
		0
	};
	int que[100],//根据51行，数组长度要改长一点。本测试用例中安全。
		head = 0,
		tail = 1;
	int ver_in[edge],
		ver_out[edge],
		weight[edge],
		first[vertex] = {
			-1,-1,-1,-1,-1
		},
		next[edge];

	int i,
		k;

	for(i = 0 ;i< edge;i++){
		scanf("%d %d %d\n",&ver_in[i],&ver_out[i],&weight[i]);
		next[i] = first[ver_in[i]];
		first[ver_in[i]] = i;

	}

	que[head] = ver_in[0]; //这里有一个错误，因为我dis是算从0顶点开始的，这里第一个输入的数据刚好是0顶点开始
	book[ver_in[0]] = 1; //所以正确，但是如果第一个数据不是0顶点开始就出问题了。
	
	while(head != tail){
		k = first[que[head]];
		while(k != -1){
			if(dis[ver_out[k]] > dis[ver_in[k]] + weight[k]){
				dis[ver_out[k]] = dis[ver_in[k]] + weight[k];
				if(book[ver_out[k]] == 0){
					book[ver_out[k]] = 1;
					que[tail++] = ver_out[k];
				}
			}
			k = next[k];
		}

		head ++;
		book[que[head]] = 0;//书上答案有这么一句,在这里的测试用例中没有这一句照样可以运行。
		//但是为什么要置为0呢？也就是说并不是贪心的，也就是每一步走完之后并不能确认是最短路径。
		//这样的话，另一个注意的问题是que数组长度不能是vertex+1,因为有可能一个顶点多次出入，不然就越界了。
	}
	i = 0;
	while(i!=head){
		printf("%d ",que[i]);
		i++;
	}
	printf("\n");
	for(i = 0 ;i< vertex; i++){
		printf("%d ",dis[i]);
	}
	printf("\n");
	return 0;

}
