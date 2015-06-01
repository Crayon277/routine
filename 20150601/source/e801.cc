/*************************************************************************
	> File Name: e801.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 21:04:38 2015
 ************************************************************************/

#include"e801.h"

int main(){
	computer mac;
	computer hp("Hewlett-Packard",5000);
	computer *p;


	mac.setBrand("Apple");
	mac.setPrice(22000);
	mac.print();
	
	
	p = &hp;
	p->print();
	
	point pt1(3);
	pt1.print();	
	
	
	return 0;
}
