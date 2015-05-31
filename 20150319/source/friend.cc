/*************************************************************************
	> File Name: friend.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 19:47:07 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Date;
class Time{
	public:
		Time(int h = 01,int m = 01, int s = 0):hour(h),minute(m),sec(s){}
		friend void display(Time &);
		void display(Date &); 
	private:
		int hour;
		int minute;
		int sec;
};

class Date{
	public:
		Date(int, int, int);
		friend void Time::display(Date &);
	private:
		int month;
		int day;
		int year;
};

void Time::display(Date &d){
	cout << d.month << "/" << d.day << "/" <<d.year <<endl;
}

Date::Date(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}

void display(Time &t){
	cout << t.hour << ":" <<t.minute << ":" <<t.sec <<endl;
}


int main(){
	Time t;
	Date d(3,21,2015);
	display(t);
	t.display(d);

	return 0;
}
