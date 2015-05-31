/*************************************************************************
	> File Name: inher_cons.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Mar 25 10:30:05 2015
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Student{
	public:
		Student(int n, string nam, char s):num(n),name(nam),sex(s){}
		~Student(){
		cout << name << endl << num << endl << sex << endl << "destroy" <<endl;
		}
	protected:
		int num;
		string name;
		char sex;
};

class Junior:public Student{
	public:
		Junior(int n, string nam, char s, int g):Student(n,nam,s),grade(g){}
		~Junior(){
			cout << name << endl << num << endl << sex << endl << grade << endl << "destroy" <<endl;
		}
	private:
		int grade;
};

int main(){
	Student s(1001,"chenye",'m');
	Junior j(1002,"xu",'f',4);

	return 0;
}
