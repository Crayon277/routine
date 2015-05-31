/*************************************************************************
	> File Name: static.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 26 18:18:35 2015
 ************************************************************************/
/*
 * static变量独立于类外。只有一个空间 
 * 任何类的对象都共享这个变量。
 *
 */



#include<iostream>
using namespace std;

class CA{
	private:
		static CA* pA;
		int x;
		int y;
		CA(int x = 0, int y = 0){
			this->x = x;
			this->y = y;
			cout << "Constructor"<<endl;
		}
	public:
		static CA* GetInstance(int x = 0, int y = 0){
			if( pA == NULL){
				pA = new CA(x, y);
			}
			return tatA;
		}
		void disp() const{
			cout << "(" << this->x << "," <<this->y << ")" <<endl;
		}
};
CA* CA::pA = NULL;

int main(){
	CA* p1 = CA::GetInstance(2,1);
	CA* p2 = CA::GetInstance(3,2);
	CA* p3 = CA::GetInstance(4,3);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	p1->disp();
	p2->disp();
	p3->disp();

	return 0;
}
