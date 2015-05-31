/*************************************************************************
	> File Name: 2_3.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 09:32:15 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Time{
	public:
		void set_time();
		void show_time();
	private:
		int hour;
		int minute;
		int second;
};

int main(){
	Time t1;
	t1.set_time();
	t1.show_time();

	Time t2;
	t2.set_time();
	t2.show_time();

	return 0;
}

void Time::set_time(){
	cin >> hour ;
	cin >> minute;
	cin >> second;
}

void Time::show_time(){
	cout << hour << ":" <<minute << ":" << second <<endl;
}
