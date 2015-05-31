/*************************************************************************
	> File Name: zuoye.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 26 18:57:29 2015
 ************************************************************************/

#include<iostream>
using namespace std;

#define ISLEAPYEAR(year) (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )

class Date{
	public:
		Date(int y , int m, int d):year(y),month(m),day(d){}
		void setdate(int y = 1970,int m = 1, int d = 1){
			year = y;
			month = m;
			day = d;
		}
		void add_date();
		void show_date();
		// friend void do(Date&);
		Date& operator++();
		Date& operator++(int);
		~Date(){
			cout << "destructor" <<endl;
		}
	private:
		int year;
		int month;
		int day;
};

void prin(){
	cout << "test " <<endl;
}
Date& Date::operator++(){
	this->add_date();
	return *this;
}

Date& Date::operator++(int){
	Date *pd = new Date(year,month,day);
	this->add_date();
	return *pd;
}

void Date::add_date(){
	switch(month){
		case 1:case 3: case 5: case 7:case 8: case 10: case 12:
			year = year + ((day + 1) / 32 + month) /13;
			month = ((day + 1) / 32 + month) % 13 + ((day + 1) / 32 + month) /13;
			day = (day + 1) / 32 + (day + 1) % 32;	
			break;
		case 4:case 6:case 9:case 11:
			year = year + ((day + 1) / 31 + month) / 13;
			month = ((day + 1) / 31 + month) % 13 + ((day + 1) / 31 + month) / 13;
			day = (day + 1) /31 + (day + 1) % 31;
			break;
		case 2:
			if(ISLEAPYEAR(year)){
				year = year + ((day + 1) / 30 + month ) /13;
				month = ((day + 1) / 30 + month ) % 13 + ((day + 1) / 30 + month) /13;
				day = (day + 1) /30 + (day + 1) % 30;	
			}else{
				year = year + ((day + 1) / 29 + month ) /29;
				month = ((day + 1) / 29 + month) % 13 + ((day + 1) / 29 + month) /13;
				day = (day + 1) /29 + (day + 1) % 29;
			}
	}
	prin();
}

void Date::show_date(){
	cout << year << " 年"  << month << " 月"  << day << " 日" << endl;
}

void dosth(Date& d){
	d.show_date();
	d.add_date();
	d.show_date();
}

int main(){
	Date date(2015,3,25);
	dosth(date);
	date.setdate(2015,12,30);
	dosth(date);
	// date.show_date();
	date.setdate(2015,12,31);
	dosth(date);
	cout << "=======" <<endl;	
	((++date)++).show_date();
	
	date.show_date();	
	return 0;
}
