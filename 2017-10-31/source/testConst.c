#include<stdio.h>

/*
 *  测试一下const int 通过指针能不能修改它
 *  结果是不能
 */

int main(){
    // const int a = 1;
    // int *p = &a;

    // printf("%p\n%d\n",&a,a);
    // *p = 2;
    // printf("%p\n%d\n",&a,a);
    printf("%lu",sizeof(int)); 
    return 0;
}

/*
 * 0x7fff4fd58618
 * 1
 * 0x7fff4fd58618
 * 1
 *
 * 其实 int *p = &a 会报错，
 * initializing 'int *' with an expression of type ' const int *' discards 
 * qualifiers (可修饰)
 * 根据结果看，即使通过指针也不能修改这个已经定义为const单元的常量。
 */