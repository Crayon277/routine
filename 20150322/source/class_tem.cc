/*************************************************************************
	> File Name: class_tem.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 11:10:00 2015
 ************************************************************************/

#include<iostream>
using namespace std;

template<class Type> class myQueue{
	public:
		myQueue();
		Type& front();
		const Type& front() const;
		void push(const Type&);
	   	Type& pop();
		bool empty() const;
	private:
		Type data;
		myQueue* link;
};


template<class Type>

