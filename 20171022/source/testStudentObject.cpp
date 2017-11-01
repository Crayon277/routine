/*************************************************************************
	> File Name: testStudentObject.cpp
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Oct 22 11:10:47 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class Student{
	public:
		void get_valu(){
			cin >> num >> name >> sex;
		}
		void display(){
			cout << "Num :" << num << endl; 
			cout << "Name :" << name << endl; 
			cout << "Sex :" << sex << endl; 
		}
	private:
		int num;
		string name;
		char sex;
};


class Student1: public Student{
	public:
		void get_value_1(){
			cin >> age >> addr;
		}
		void dispaly_1(){
			// cout << "Num :" << num << endl; 
			// cout << "Name :" << name << endl; 
			// cout << "Sex :" << sex << endl; 
			this->display();
			// cout <<"test base private num" << this->num <<endl;
			cout << "Age :" << age <<endl;
			cout << "Addr:" <<addr << endl;

		}
	private:
		int age;
		string addr;
};

class Student2: private Student{
	public:
		void get_value_2(){
			this->get_valu();
			cin >> incoming;
		}
		// void get_incoming(){
			// cin >> incoming;
		// }
		void display_2(){
			this->display();
		}
		bool setIfAssist(){
			if(incoming < 1000){
				return true;
			}else{
				return false;
			}
		}
	private:
		int incoming;
};

int main(){
	Student1 stu;
	stu.get_valu();
	stu.get_value_1();

	// stu.display();
	stu.dispaly_1();

	return 0;
}

