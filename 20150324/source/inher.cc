/*************************************************************************
	> File Name: inher.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Mar 24 14:20:58 2015
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class staff{
	public:
		staff(int n, string na, char s, string a):num(n),name(na),sex(s),addr(a){}
		void show_info();
		friend void get_info(staff &);	
	protected:
		int num;
		string name;
		char sex;
		string addr;
};

void get_info(staff& sta){

    cout << "staff friend fun show: ";
    cout <<  sta.num;

}

void staff::show_info(){
	cout << "staff num :" <<num <<endl;
	cout << "staff name:" <<name<<endl;
	cout << "staff sex :" <<sex <<endl;
	cout << "staff addr:" <<addr<<endl;
}

class high_lever:protected staff{
	public:
		high_lever();	
		high_lever(int n, string na, char s, string a, string po = "CEO"):staff(n,na,s,a),position(po){
		}
		void modi(){
			cin >> num >> name >> sex >> addr >> position;
			
		}
		void show_info_hl(){
			show_info();
			cout << "position:" <<position <<endl;
		}
        friend void get_info(high_lever&);
	private:
		string position;
};

void get_info(high_lever& hl){
    cout << "hl friend fun show :" << endl;
    cout << hl.num << " " << hl.position <<endl;
}


int main(){
	staff saler(1010,"chenye",'f',"nowhere");
	saler.show_info();
    get_info(saler);
	// staff::show_info(saler);	
	high_lever manager(0,"Jobs",'m',"Apple");
	//manager.get_position();
	manager.show_info_hl();
    /* manager.show_info(); */
	manager.modi();
	manager.show_info_hl();
    get_info(manager);

	return 0;
}
