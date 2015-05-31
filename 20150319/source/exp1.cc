/*************************************************************************
	> File Name: exp1.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 19 13:45:51 2015
 ************************************************************************/
//test p384

#include<iostream>
using namespace std;

class Screen{
	public:
	typedef std::string::size_type index;
	public:
		void setHeight(index);
	private:
		index height;
		int ii = 0;
};

Screen::index verify(Screen::index hi){
	return hi > 2 ? hi -1 : hi ;
}

void Screen::setHeight(index heigh){
	height = verify(heigh);
}



int main(){
	Screen test;
	test.setHeight(2);

	return 0;
}
