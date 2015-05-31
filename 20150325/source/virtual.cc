/*************************************************************************
	> File Name: virtual.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 28 21:27:03 2015
 ************************************************************************/

#include<iostream>

using namespace std;
#include<string>

class Student{
	public:
		Student(int ,string,float);
		virtual void display();
	protected:
		int num;
		string name;
		float score;

};

Student::Student(int n, string nam, float s){
	num = n;
	name = nam;
	score = s;
}

void Student::display(){
	cout << "num: " << num << "\nname : " <<name << "\nscore : " <<score<<endl; 
}

class Graduate : public Student{
	public:
		Graduate(int n ,string nam, float s, float p):Student(n,nam,s),pay(p){

		}
		void display();
	protected:
		float pay;
};



void Graduate::display(){
	Student::display();
	cout << "pay :" <<pay <<endl;
}

int main(){
	Student s(1001,"ssss",87.5);
	Graduate g(100,"chenye",387,5277);
	Student *pt = &s;
	pt->display();
	pt = &g;
	pt->display();
	
	return 0;

}
