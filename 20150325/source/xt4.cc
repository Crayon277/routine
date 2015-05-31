/*************************************************************************
	> File Name: xt4.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 30 23:40:01 2015
 ************************************************************************/

#include<iostream>
using namespace std;

const double pi = 3.1415926;

class Shape{
	public:
		Shape(){}
		~Shape(){ cout << "Shape" << endl;}
		virtual void printArea() const = 0;

};

class Circle:public Shape{
	public:
		Circle(float rad):radius(rad){

		}
		~Circle(){
			cout << "Circle" <<endl;
		}
		void printArea() const {
			cout << "Circle area is : " << pi * radius * radius << endl;
		}
	private:
		float radius;
};

class Rectangle: public Shape{
	public:
		Rectangle(float x, float y):length(x),width(y){

		}
		~Rectangle(){
			cout << "Rectangle" <<endl;
		}
		void printArea() const {
			cout << "Rectangle area is : "<< length * width << endl;
		}
	private:
		float length;
		float width;
};

class Triangle: public Shape{
	public:
		Triangle(float f, float h):floor(f),height(h){

		}
		~Triangle(){
			cout << "Triangle" <<endl;
		}
		void printArea()const{
			cout << "Triangle area is : " << floor * height / 2 << endl;
		}
	private:
		float floor;
		float height;
};

int main(){
	Circle c(2.5);
	Rectangle r(3,4);
	Triangle t(6.7,8);

	Shape* pt ;
	pt = &c;
	pt->printArea();

	pt = &r;
	pt->printArea();

	pt = &t;
	pt->printArea();


	cout << "-----" <<endl;
	pt = new Circle(2.6);
	pt->printArea();
	delete pt;
	cout << "=====" <<endl;

	return 0;
}
