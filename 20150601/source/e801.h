/*************************************************************************
	> File Name: e801.h
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 20:59:27 2015
 ************************************************************************/
#include<cstring>
#include<iostream>
using namespace std;


class computer{
	public:
		computer(const char* brand = "", float price = 0){
			this->brand = new char[50];
			strcpy(this->brand,brand);
			this->price = price;
		}
		void print(){
			cout <<"Brand: " <<brand << endl;
			cout <<"Price: " <<price <<endl;
		}

		void setBrand(const char * newbrand){
			strcpy(brand,newbrand);
		}
		void setPrice(float newprice){
			price = newprice;
		}
		~computer(){
			delete[] brand;
			brand = NULL;
			cout << "Clear" <<endl;
		}
	private:
		// char brand[20];
		char *brand;
		float price;
};

class point{
	private:
		int yPos;
		int xPos;
	public:
		point(int x):xPos(x--),yPos(x--){
		}
		void print(){
			cout << "xPos" << xPos << ",yPos:" << yPos <<endl;
		}
	
};
