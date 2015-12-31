/*************************************************************************
	> File Name: size_strlen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Oct  9 09:33:23 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char* byte_point;
typedef char integer;
typedef unsigned char uninteger;

void show_bytes(byte_point bp, int size ){
	int i = 0;
	for(i = 0 ; i <= size-1; i++){
		printf("%02x ",bp[i]);
	}
	printf("\n");
}
void show_float(float x){
	show_bytes((byte_point)&x,sizeof(float));
}

int main(){
   /*  const char*s = "abcdef"; */
	/* printf("sizeof = %d\nstrlen = %d\n",sizeof(s),strlen(s)); */
	/* printf("1<<2 = %d",1<<2); */
	/* printf("\n3<<4 = %d\n",3<<4); */
	/* printf("1<<2 + 3<<4 = %d\n",1<<2 + 3 << 4); */
	/* short x = -12345; */
	/* short mx = -x; */
	/* int ix = x; */
	/* unsigned int uix = (unsigned short)x; */

	/* show_bytes((byte_point)&x,sizeof(short)); */
	/* show_bytes((byte_point)&mx,sizeof(short)); */
	/* show_bytes((byte_point)&ix,sizeof(int)); */
	/* show_bytes((byte_point)&uix,sizeof(unsigned int)); */
	
   /*   int y = 0x70000000; */
	 // printf("%i\n",y);
	 // int x = -y;
	 /* printf("%i\n",x); */

	/* float i = 137728321; */
	/* float j = 3510593; */
	/* float k = 204837185; */
	/* float m = 20.59375; */
	/* show_float(i); */
	/* show_float(j); */
	/* show_float(k); */
	/* show_float(m); */
	uninteger x = 134;
	uninteger y = 246;
	integer m = x;
	integer n = y;
	uninteger z1 = x-y;
	uninteger z2 = x + y;
	integer k1 = m - n;
	integer k2 = m + n;
	show_bytes((byte_point)&x,1);
	show_bytes((byte_point)&y,1);
	show_bytes((byte_point)&m,1);
	show_bytes((byte_point)&n,1);
	show_bytes((byte_point)&z1,1);
	show_bytes((byte_point)&z2,1);
	show_bytes((byte_point)&k1,1);
	show_bytes((byte_point)&k2,1);
	printf("m=%d\nn=%d\nk1=%d\n",m,n,k1);
	
	return 0;
}
