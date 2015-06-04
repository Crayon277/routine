/*************************************************************************
	> File Name: precision_fact.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Jun  4 14:34:48 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 3000

int multiply(int *from,int *to,int icur , int i){//icur是当前from有几位
	int ifrom;
	int to_cur = 0; //为中间过程辅助，24*15，＊5的时候从下标0开始，＊1的时候从下标1开始，因为乘法不是每一位往左空一格么
	int to_index = 0;
	int weishu;
	//from * i
	while(i!=0){
		to_index = to_cur;
		int temp = i%10;
		int carry = 0;
		int mid ;
		for(ifrom = 0; ifrom < icur ;ifrom++){
			mid = from[ifrom]*temp + carry;
			carry = mid/10;
			to[to_index] += mid%10;
			to_index++;
		}
		if(carry){//最后有进位的话，当前结果的位数再加一个。
			to[to_index] = carry;
			weishu = to_index+1;	
		}else{
			weishu = to_index;
		}
		i/=10;
		to_cur++;
	}

	return weishu;
}
//我的思路 比如11！,10！＝3628800, 然后3628800 *11,这个顺序很重要,我是把3628800 放在前面,如果是11*3628800就简单许多了
//因为3628800 *11, 按照模拟乘法，中间过程可能会溢出，所以还是需要数组保存下来。
//11*3628800，就不用，最多乘以1000，3628800，的每一位乘以1000都不会超出，所以只需一个临时变量保存下来就可以了。
//而且，我中间过程的时候更细化，每一个和每一个相乘取进位，11*3628800,直接乘以11,而不是和1乘，再往左空一格，再和1乘，
//比如很大，111*1231312，111*2,结果222,把2放入相应位数，22整个当作进位。！！！，因为我那样可能涉及溢出，所以不能
//把整个当作进位。这就是换个位置的好处。！！！！！
int main(){
	int op1[size],iop1,op1_cur,
		op2[size],iop2,op2_cur;

	int iFact,i;
	scanf("%d",&iFact);
	op1[0] = 1;
	op1_cur = 1;
	for(i = 1;i <= iFact;i++){
		if(i%2 != 0){
			//multi with op1 and put res to op2
			op2_cur = multiply(op1,op2,op1_cur,i);
			memset(op1,0,sizeof(op1));		
			
		}else{
			//multi with op2 and put res to op1
			op1_cur = multiply(op2,op1,op2_cur,i);
			memset(op2,0,sizeof(op2));
			
		}
	}
	if(iFact % 2== 0){
		for(i = op1_cur-1;i>=0;i--){
			printf("%d",op1[i]);
		}
		printf("\n");
	}else{
		for(i = op2_cur-1;i>=0;i--){
			printf("%d",op2[i]);
		}
		printf("\n");
	}

	return 0;

}
