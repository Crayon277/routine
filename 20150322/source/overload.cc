/*************************************************************************
	> File Name: overload.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 09:00:01 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Complex{
	public:
		Complex(){
			real = 0;
			imag = 0;
		}
		Complex(int r, int i):real(r),imag(i){}
		Complex add(Complex &);
		void display(){
			cout << "(" <<real << "," << imag <<")" <<endl;
		}
	private:
		int real;
		int imag;
};

Complex Complex::add(Complex& c){
	real += c.real;
	imag += c.imag;
	return *this;
}

int main(){
	Complex c1(5,3);
	Complex c2(2,6);
	//Complex<cout> c3;
	cout << "c1 :" ;
	c1.display() ;
	cout << "c2 :" ;
	c2.display() ;

	c1 = c1.add(c2);
	cout << "c1 + c2 = ";
	c1.display() ;
	return 0;
}
