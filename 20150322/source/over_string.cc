/*************************************************************************
	> File Name: over_string.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 14:37:12 2015
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

class String{
	public:
		String(){
			p = NULL;
		}
		String(char *str);
		void display();
		friend String operator +(String &s1, String &s2);
		//friend String operator -(String &s1, String &s2);
		friend bool operator >(String& s1, String &s2);
		friend bool operator <(String& s1, String &s2);
		friend bool operator ==(String& s1, String &s2);
	private:
		char *p;
};

String::String(char * str){
	p = str;
}

String operator +(String &s1 ,String &s2){
	String s;
	char *sp = new char[strlen(s1.p)+strlen(s2.p)+3];
	
	strcat(sp,s1.p);
	strcat(sp,"   ");
	strcat(sp,s2.p);
	return sp;
}

bool operator >(String& s1, String &s2){
	int i = 0;
	if(strlen(s1.p) > strlen(s2.p)){
		return 1;
	}else if(strlen(s1.p) < strlen(s2.p)){
		return 0;
	}
	while(s1.p[i] != 0 && s2.p[i] != 0){
		if(s1.p[i] - s2.p[i] > 0){
			return 1;
		}else if(s1.p[i] - s2.p[i] < 0){
			return 0;
		}else{
			i++;
		}
	}
	return 0;
}

bool operator <(String &s1, String& s2){
	int i = 0;
	if(strlen(s1.p) < strlen(s2.p)){
		return 1;
	}else if(strlen(s1.p) > strlen(s2.p)){
		return 0;
	}

	while(s1.p[i] != 0 && s2.p[i] != 0){
		if(s1.p[i] - s2.p[i] < 0){
			return 1;
		}else if(s1.p[i] - s2.p[i] > 0){
			return 0;
		}else{
			i ++;
		}
	}
	return 0;
}

bool operator ==(String& s1, String& s2){
	if(!(s1>s2) && !(s1<s2)){
		return 1;
	}else{
		return 0;
	}
}

void String::display(){
	cout << p <<endl;
}

int main(){
	String string1("Hello");
	String string2("Helloa");

	string1.display();
	
	string2.display();
	
	cout << "string1 + string2 :" ;
	(string1 + string2).display();

	/*
	if(string1 > string2){
		cout << "string1 > string2" <<endl;
	}else{
		cout << "string1 not bigger than string2" <<endl;
	}
	if(string1 < string2){
		cout << "string1 < string2" <<endl;
	}else{
		cout << "string1 not smaller than string2" <<endl;
	}

	if(string1 == string2){
		cout << "string1 = string2" <<endl;
	}else {
		cout << "string1 not equal to string2" <<endl;
	}
	*/
	cout << (string1 > string2)? (return "string1 > string2"):(return "string1 < or = string2") <<endl;



	return 0;
}
