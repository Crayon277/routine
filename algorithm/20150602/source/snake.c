/*************************************************************************
	> File Name: snake.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 10:01:10 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define size 10

int next[4][2] = {
	1,0,
	0,-1,
	-1,0,
	0,1
};
void dfs(int (*a)[size],int n, int i, int j,int count){
	int index,x,y;
	if(count > n*n || i>n ||j >n || i <1 || j<1){
		return;
	}
	a[i][j] = count++;
	for(index = 0;index<4;index++){
		x = i + next[index][0];
		y = j + next[index][1];
		if(a[x][y] == 0 && x >= 1 && y>= 1 && x <=n && y<=n){
			dfs(a,n,x,y,count);
		}

	}
}

int main(){
	int a[size][size] ;
	int n,i,j,count = 1;
	scanf("%d",&n);
	for(i = 1;i<=n;i++){
		for(j = 1; j<=n;j++){
			a[i][j] = 0;
		}
	}
	/* dfs(a,n,1,n,1); */
	i = 1;
	j = n;
	a[i][j]  = 1;//这个原先没有的。
	count ++;//对应的count 要++，不然循环退不出去了。
	while(count <= n*n){ // 问题出现在最后一个赋值上。我的思路是总是给当前的赋值。这样就导致了最后一个比较的时候总是false
		//总是不能给最后一个赋值，另一种思路是总是给给下一个赋值！！！
		//比较的和赋值的应该同步！！！
		//比较当前是否满足的会多出一个步骤，要把坐标置为下一个。因为比如第一列的最后一个是已经赋值了的，下一次行的时候这个
		//这个就不用赋值了。
		while(a[i+1][j] == 0 &&count <= n*n && i < n ){ //!!!!!判断的是下一个，但是赋值的是当前的就没有意义了
			/* a[i][j] = count++; */
			/* i++; */
			a[++i][j] = count++;
		}
		while(a[i][j-1] == 0 && count <= n*n && j> 1){
			/* a[i][j] = count ++;` */
			/* j--; */
			a[i][--j] = count++;
		}
		while(a[i-1][j] == 0 && count <= n*n && i> 1){
			/* a[i][j] = count++; */
			/* i--; */
			a[--i][j] = count++;
		}
		while(a[i][j+1] == 0 && count <= n*n && j<n){
			/* a[i][j] = count ++; */
			/* j++; */
			a[i][++j] = count ++;
		}

		//修改，a[][] =0 的比较，放在i , j 越界判断的后面，因为短路运算的优势，不然，潜在bug,a[][]将访问非法内存。！！！
	}

	for(i = 1; i <=n; i++){
		for(j = 1;j<=n;j++){
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
