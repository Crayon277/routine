/*************************************************************************
	> File Name: exp2.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 08:50:32 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class test{
	public:
		int a;
		int b;
		int c;
		void get_n();
	private:
		int d;
		void gety_n(){
			cout << d <<endl;
		}

};

inline void test::get_n(){
	cout << a << b << c <<endl;
	gety_n();
}

int main(){
	cout << sizeof(test) <<endl;


	return 0;
}

