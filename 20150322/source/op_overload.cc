/*************************************************************************
	> File Name: op_overload.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 09:50:10 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Complex{
	public:
		Complex(){
			real = 0;
			imag = 0;
		}
		Complex(double r, double i){
			real = r;
			imag = i;
		}
		
		void display();
		Complex operator+(Complex& c2);
		//Complex operator-(Complex&c1, Complex &c2);
		friend Complex operator-(Complex c1, Complex&c2);
		friend ostream& operator<<(ostream&, Complex &s);
		friend ostringstream& operator << (ostringstream & s,Complex &c);
		friend istream& operator>>(istream&, Complex&);
		
	private:
		double real;
		double imag;
};

ostream& operator<<(ostream& output, Complex& c){
	output<< "(" << c.real << "," << c.imag <<")" <<endl;
	return output;
}

istream& operator>>(istream& input, Complex& c){
	cout << "input real and imag :" ;
	input >> c.real >> c.imag;
	return input;
}


ostringstream& operator<<(ostringstream& s,Complex & c){
	
	s<< "(" <<c.real << "," << c.imag <<")" <<endl;
	return s;
}

void Complex::display(){
	cout << "(" <<real << "," <<imag <<")" <<endl;
}

Complex Complex::operator+(Complex& c2){
	return Complex(real+c2.real, imag+c2.imag);
}

Complex operator-(Complex c1, Complex&c2){
	c1.real -= c2.real;
	c1.imag -= c2.imag;
	return c1;
}

int main(){
	Complex c1(3.2 , 12);
	Complex c2(3.1 , 13);
	Complex c3;
	cin >> c3 >> c2;
	cout << c3;
	ostringstream oss;
	
	c3 = c1 + c2;
	oss << c3;
	cout << oss.str();

	/*
	cout << "c1 :" ;
	c1.display();
	cout << "c2 :" ;
	c2.display();
	c3 = c1+c2;
	cout << "c1 + c2 :" ;
	c3.display();
	
	cout << "c1 - c2 :" ;
	c3 = c1-c2;
	c3.display();	
	c1.display();	
*/

	return 0;
}


