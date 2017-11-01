#include<stdio.h>
#define SIZE 10
/*
 * 因为说了getchar是指示c语言把输入接受到缓冲区。缓冲区不会释放，知道用户按下enter建，然后
 * 缓冲区的内容才以一次一个字符的方式释放。
 * 
 * 我想。这是不是意味着getchar会先去缓冲区看看有没有东西，然后如果没有东西的话在提示用户输入
 * 因为在一个循环里面写getchar，只有第一次是停下来等待用户输入的，用户输入的只要很多，下一个循环
 * 会自己从缓冲区里面读取。
 */

void testIfGetcharStopInLoopWhenBufferIsEmpty(){
    char msg[SIZE];
    int i;
    for(i=0;i<SIZE;i++){
        msg[i] = getchar();
    }
    printf("-----\n");
    for(i-=1;i>=0;i--){
        putchar(msg[i]);
    }
    putchar('\n');
}
/* 
 *  测试结果，这里SIZE定义为10，当我一开始输入几个字符的时候，当循环把这些字符读完后，然后还没有
 * 到达循环结束条件的时候，它会再等待用户输入，这里需要注意Enter键也算一个字符。
 */

 void testGT(){
     // 写给大家看的c语言书 p152
     printf("what are your two initials\n");
     char firstInit = getchar();
     char lastInit = getchar();
     putchar(firstInit);
     putchar(lastInit);
 }
 /* 
  * 书上的意思应该是连续按GT后再Enter建，和G Enter T Enter的区别。
  * 后者第二个lastInit是读到了Enter而不是T
  */

 void testfflush(){
     // 写给大家看的c语言书 p152
     printf("what are your two initials\n");
    //  char firstInit = getchar();
     char firstInit;
     scanf("%c",&firstInit);
     fflush(stdin);
     char lastInit = getchar();
     putchar(firstInit);
     putchar(lastInit);
 }
 /* 
  * 效果是没什么变化，还是一样，fflush没有起到作用，这是为什么？
  * 没有清理缓冲？？？？
  * fflush 不是c／c++标准定义的，有些编译器会执行清空缓存的操作，但是有些不会
  * 所以这是一个移植性很差的函数
  * 
  * int fflush(FILE *stream);
  * If stream points to an output stream or an update stream in which
  * the most recent operation was not input, the fflush function causes
  * any unwritten data for that stream to be delivered to the host environment
  * to be written to the file; otherwise, the behavior is undefined.
  *
  */

int main(){
    //testIfGetcharStopInLoopWhenBufferIsEmpty();
    //testGT();
    testfflush();
    return 0;
}