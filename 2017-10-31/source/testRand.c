#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
 *  rand(), 包含头文件 stdlib
 *  如果不设置随机数产生器的种子，每次程序执行都会是一样的结果。
 * 所以如果要真的随机，要给一个初始的基数值。todo:这是不是以为随机数的产生是在这个基数之上的？
 * 
 */

int main(){
    time_t t;
    int dice;
    srand(time(&t));
    for(int i = 0 ; i<10000; i++){
        dice  = (rand()%5+1);
        //范围应该是1～5, 因为%5范围是0~4
        if(6 == dice){
            printf("6 is indeed exist\n");
        }

    }
    printf("6 has high probability not exists\n");
}


/*
 * 产生随机数写法记住就行了 ,srand(time(&t))
 * typedef long __darwin_time_t;
 * typedef __darwin_time_t time_t;
 * time_t time(time_t *);
 * void srand(unsigned int);
 */