#include<stdio.h>
//#include<conio.h>
/* 
 *  getch是无缓冲的。也就是它是即时读取的，不会等按下enter建。
 * 意味着不能用backspace来纠正错误，getchar里面如果输入错误
 * 可以用一个backspace来冲走错误的输入。todo:这里冲走原理是什么？
 * 
 */

int main(){
    char firstchar = getch();
    char secondchar = getch();
    putch(firstchar);
    putch(secondchar);


    return 0;
}

/*
 *  用clang编译的时候报了一个错误，implicit declaration of function 'getch' 
 * is invalid in c99. 
 * 
 * 网上的资料显示需要引入头文件conio.h，但是编译的时候说没有这个文件，因为平台的原因吗
 * 
 * 用getchar()它是从“流”中间去读取，所以第一个getchar()接受的是刚刚中断的流队列中即将出列的第
 * 一个字符（不限于回车符，上面举过例子了），如果流队列不为空，执行getchar()就继续放水，直到把回
 * 车符也放空为止，空了之后再在执行getchar()就停下等待你的输入了；我们用getch()为什么每次都是
 * 等待用户的输入呢？因为getch()是从键盘接收，即时的接收，并不是从stdin流中去读取数据。
 */
