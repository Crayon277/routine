/*************************************************************************
	> File Name: ob_po.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 11:50:06 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Time{
	public:
		Time(int , int, int);
		static int year;
		int hour;
		int minute;
		int sec;
		void get_time();
};

int Time::year = 2015;

Time::Time(int h, int m, int s){
	hour = h ;
	minute = m;
	sec = s;
}

void Time::get_time(){
	cout << hour << ":" << minute << ":" << sec << endl;
}


int main(){
	cout << Time::year  <<endl;
	
	Time t1(12,00,01);
	Time t2(t1);
	
	cout << t1.year << endl;
	cout << t2.year <<endl;

	t1.year = 2016;

	cout <<t1.year <<endl;
	cout <<t2.year <<endl;
	cout << Time::year <<endl;
	
	//Time::get_time(&t1);	
	//void (Time:: * p1)(Time * this) = &t1.get_time;

	//(*p1)(&t1);	

	return 0;
}
