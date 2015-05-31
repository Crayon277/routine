/*************************************************************************
	> File Name: static_fun.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 15:30:30 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Student{
	public:
		Student(int n, int a, float s, float ss):num(n),age(a),score_en(s),score_mt(ss){}
		void total();
		float ave_per();
		void show_score();
		static float average_mt();
		static float average_en();
	private:
		int num;
		int age;
		float score_en;
		float score_mt;
		float sum_per;
		static float sum_en;
		static float sum_mt;
		static int count;
};

void Student::show_score(){
		cout << "en: " <<score_en << endl;
		cout << "mt: " <<score_mt << endl;
		cout << "sum: "<<sum_per  <<endl;
}

void Student::total(){
	sum_per = score_en + score_mt;
	sum_en += score_en;
	sum_mt += score_mt;
	count++;
}
float Student::average_en(){
	return(sum_en/count);
}

float Student::average_mt(){
	return (sum_mt/count);
}

float Student::ave_per(){
	return (sum_per/2);
}

float Student::sum_en = 0;
float Student::sum_mt = 0;
int Student::count = 0;

int main(){
	Student stu[3] = {
		Student(1001,17,89,90),
		Student(1002,17,90,98),
		Student(1003,17,92,96),
	};

	//int n;
	//cin >> n;
	for(int i = 0; i < 3; i++){
		stu[i].total();
		cout << i << ":" <<endl;
		stu[i].show_score();
	}
	cout << "average_en: " << Student::average_en() <<endl;
	cout << "average_mt: " << Student::average_mt() <<endl;

	


}
