/*************************************************************************
	> File Name: destructor.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 11:06:17 2015
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Student{
	public:
		Student(int n , string nam, char s){
			num = n;
			name = nam;
			sex = s;
			cout << name<< "Constructor called." <<endl;
		}
		~Student(){
			cout << name <<"Destructor Called." <<endl;
		}
		void display(){
			cout << "num:" <<num <<endl;
			cout <<"name :"<<name <<endl;
			cout <<"sex: " <<sex <<endl;
		}
	private:
		int num;
		string name;
		char sex;
};

static Student std0(10000, "global static",'m');

void fun(){
	Student std1(10001,"fun noraml",'f');
	static Student std2(10002,"fun static",'m');
}

int main(){
	Student studl(10010,"main 1",'f');
	//studl.display();
	
	Student stud2(10011,"main 2",'m');
	//stud2.display();
	
	fun();
	return 0;
}


