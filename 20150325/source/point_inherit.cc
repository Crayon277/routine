/*************************************************************************
	> File Name: point_inherit.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 26 09:22:10 2015
 ************************************************************************/

#include<iostream>
using namespace std;

const float PI = 3.14159;

class Point{
	public:
		Point(){

		}
		Point(int x, int y):rad_x(x),rad_y(y){}
		friend ostream& operator<<(ostream& output,Point& p);
		friend istream& operator>>(istream& input, Point& p);
		virtual 
	protected:
		float rad_x;
		float rad_y;
};

ostream& operator<<(ostream& output, Point& p){
	output << "Point is located : ("<< p.rad_x << "," << p.rad_y << ")" <<endl;
	return output;
}

istream& operator>>(istream& input, Point& p){
	cout << "Enter coordinate ?" <<endl; //test  if this sentence appears twice in >> >> ;
	input >> p.rad_x >> p.rad_y ;
	return input;
}


class Circle:public Point{
	public:
		Circle(int x, int y, int r):Point(x,y),radius(r){area = 0.0;}
		friend ostream& operator<<(ostream& output, Circle & p);
		friend istream& operator>>(istream& input, Circle & p);
	protected:
		int radius;
		float area;
};

ostream& operator<<(ostream& output, Circle & p){
	p.area = PI*p.radius*p.radius;
	output << "The area of circle which located (" << p.rad_x << "," << p.rad_y << ")" << "is " << p.area <<endl;
	return output;
}
istream& operator>>(istream& input, Circle & p){
	cout << "Enter the radius of circle : " <<endl;
	input >> p.radius;
	return input;
}


int main(){
	Point origin(0,0);
	Point test;
	Circle round(2,7,7);
	Point* pRef = &origin;
	cout << *pRef <<endl;
	pRef = &round;
	cout << *pRef <<endl;
	cout << origin;
	cout << round;
	cin >> origin >> test;

	cout << origin << endl;
	cout << test << endl;
	return 0;
}


