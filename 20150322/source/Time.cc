/*************************************************************************
	> File Name: Time.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 16:15:01 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Time{
	public:
		Time(){
			minute = 0; 
			sec = 0;
		}
		Time(int m = 0, int s = 0):minute(m),sec(s){}

		Time operator++(int);

		void display(){
			cout << minute << ":" <<sec <<endl;
		}

	private:
		int minute;
		int sec;
};

Time Time::operator++(int i){
	Time temp(*this);
	if(++sec == 60){
		minute ++;
		sec = 0;
	}
	return temp;
}

int main(){
	Time t1(34);
	int i = 0;
	while(i != 61){
		(t1++).display();
		i++;
	}
	return 0;
}
