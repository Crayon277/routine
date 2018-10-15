#include<stdio.h>

/* 
 *  int array[] , 的array到底是什么？
 */

int main(){
    int vals[5] = {1,2,3,4,5};
    printf("%p\n",vals);
    printf("%p\n",&vals);

    return 0;
}