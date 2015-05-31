/*************************************************************************
	> File Name: matrix.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 21:51:32 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class matrix{
	public:
		matrix();
		friend istream& operator>>(istream& i,matrix& ma);
//		friend ostream& operator<<(ostream& o,matrix& ma);
		friend ostream& operator<<(ostream& o,matrix ma);
		matrix operator+(matrix& ma);
		matrix operator-(matrix& ma);
	//	matrix operator*(matrix& ma);
	private:
		int mval[2][3];
};

matrix::matrix(){
	int i = 0,j =0;
	for(i = 0; i < 2 ;i++){
		for(j = 0; j < 3 ; j++){
			mval[i][j] = 0;
		}
	}
}

//ostream& operator<<(ostream& output, matrix& ma){
//	int i=0,j=0;
//	for(i = 0 ;i < 2; i++){
//		for(j = 0; j< 3; j++){
//			output<<ma.mval[i][j]<<" ";
//		}
//		output<<endl;
//	}
//	return output;
//}
//
ostream& operator<<(ostream& output,matrix ma){
	int i=0,j=0;
	for(i = 0 ;i < 2; i++){
		for(j = 0; j< 3; j++){
			output<<ma.mval[i][j]<<" ";
		}
		output<<endl;
	}
	return output;

}

istream& operator>>(istream& input,matrix& ma){
	int i = 0, j =0;
	int ival;
	for(i = 0 ;i < 2; i++){
		for(j = 0 ;j < 3; j++){
			input >> ival;
			ma.mval[i][j] = ival;
		}
	}
	return input;
}

matrix matrix::operator+(matrix& ma){
	matrix m(ma);
	int i = 0, j = 0;
	for(i = 0 ; i < 2 ;i++){
		for(j = 0; j < 3; j++){
			m.mval[i][j]+=this->mval[i][j];
		}
	}
	return m;
}

matrix matrix::operator-(matrix& ma){
	matrix m((*this));
	int i = 0, j = 0;
	for(i = 0 ; i < 2 ;i++){
		for(j = 0; j < 3; j++){
			m.mval[i][j]-=ma.mval[i][j];
		}
	}
	return m;
}

int main(){
	matrix ma1,ma2;
	cin >> ma1 >> ma2;
	cout << ma1 << endl << ma2;

	cout << ma1+ma2 <<endl;
	cout << ma1-ma2 <<endl;
	
		

	
	return 0;

}
