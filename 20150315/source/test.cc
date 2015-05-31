/*************************************************************************
	> File Name: test.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Mar 18 09:04:30 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Test
{

	public:
		Test() : num(0)
	{
	}
		~Test(){
		}

		int Get(Test& t) const
		{

			t.foo(5);
			return num;
		}

		int Get(Test* p) const
		{

			p->foo(10);
			return num;
		}

		void foo(int n)
		{

			num = n;
		}
	private:
		int num;
};


int main()
{

	Test t;
	cout<<t.Get(t)<<t.Get(&t)<<endl;
}

