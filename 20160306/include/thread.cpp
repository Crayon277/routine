/*************************************************************************
	> File Name: thread.cpp
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Sep  2 22:32:27 2016
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;

void foo(){
	std::cout << "Hello world"<<std::endl;
}

int main(){
	std::thread t(foo);
	t.join();
	return 0;
}


