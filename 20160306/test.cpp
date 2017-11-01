/*-----------------------------------------------------------------
**���Ի��� VS2010
**˵����û������㷨�ó�Y,Q,V����������λ��Ŀ��ֻ�Ǽ򵥵Ľ�������
**-----------------------------------------------------------------
*/
//���չ�˾EMRS�����λ����
#include <iostream>
#include <stdio.h>
#include <vector>  
#include <algorithm>  
#include<cmath>
#include<string>
using namespace std;  
#define pi 3.1415926  //Բ����

//�����λ����˵��
int shuxing[4][4]={'Y',1000,3,1,
	               'Q',700,8,4,
	               'V',500,10,5,};

//�洢������������� ����36��				   
struct paiming{
    double wight;
    char changwei;
	double fale;
};

//��������  	
int print_result(paiming a , paiming b)
{
	return a.fale > b.fale;
}

int main()
{	

	paiming Result;//�м����
	vector<paiming>v;//�洢��Ҫ�����е�SMSRֵ
	int zz=0;
	
	//��ÿһ�����λ���м���
	for(int k=0;k<=2;k++)
	{
		int uu = shuxing[k][2]; //��ȡ��ǰ��λ������ľ�ֵ 
		int xx = shuxing[k][3]; //��ȡ��ǰ��λ������ı�׼�� 
		for(int j=1;j<=36;j++)
		{		
	        //�������ֵ
			double q=0.0;
			double i=0.0;
			
			//�������㣬��Ӧ���� excle�е�  NORMDIST(A2,6,2,1)
			while(i <= j)
			{
				q = q + 1/sqrt(2*pi)/xx*exp(-(i-uu)*(i-uu)/(2*xx*xx))*0.01;//��׼��̬�ֲ�
				i = i + 0.01;
			}
			
			Result.wight = 1-q;//��ӦExcle��     1-NORMDIST(A2,6,2,1)
			Result.changwei = shuxing[k][0];   //��¼��λ
			Result.fale = Result.wight*shuxing[k][1];//����EMSRֵ
			
			v.push_back(Result);//���ó���ÿһ���������vector�У�ѭ����Ϻ���36��
		}
	}
	
	
	sort(v.begin(),v.end(),print_result);  //��36��������
	
	int H[4]={-1,-1,-1};
	int M[3] = {1,1}; //�洢Y,Q�ı�����������V�ģ�ֱ�ӽ���1-Y-Q�ļ���
	
	
	//����������
	for (int i =0;i < 12;i++)  
	{  
		if(v[i].changwei=='Y')//����Y�յı�����
		{
			if(H[0]==-1)
			{
				H[0]=i;
				while(v[i+M[0]].changwei=='Y')
				{
					M[0] = M[0]+1;
				}
			}
			else continue;
		}
		
		if(v[i].changwei=='Q')//����Q�յı�����
		{
			if(H[1]==-1)
			{   
				H[1]=i;
				while(v[i+M[1]].changwei=='Q')
				{
					M[1] = M[1]+1;
				}
			}
			else continue;
		}
		
		
		if(v[i].changwei=='V'){  
			if(H[2]==-1)
			{
				H[2]=i;
			}
			else continue;
		}
	}
	
	
	//��ӡ����Ľ��
	
	//��ӡ˵������������������ԣ�ֻ��Ϊ����������Ŀ���Խ��д�ӡ��
	
	
	printf("--------------------------------------------------\n");
	printf("Y��λ������Ϊ��%d\n",M[0]);
	printf("Q��λ������Ϊ��%d\n",M[1]);
	printf("V��λ������Ϊ��%d\n",12-M[0]-M[1]);
	//��ӡ���
	printf("--------------------------------------------------\n");
	printf("%s\t%s\t%s\t%s\n","��λ��","��������","�����۸�","��λ");
	for (i=0;i < 12;i++)  
	{   
		printf("%3d\t",i+1);
		if(i<H[1])
			printf(" %.5lf\t%5.lf\t\t%2c\n",v[i].wight,v[i].fale,v[i].changwei);
		else if(i<H[2])
		{
			if(v[i].changwei!='Q')
				printf(" %.5lf\t%5.lf\t\t Y Q\n",v[i].wight,v[i].fale);
			else
				printf(" %.5lf\t%5.lf\t\t Y%2c\n",v[i].wight,v[i].fale,v[i].changwei);
		}
		else
		{
			if(v[i].changwei!='V')
				printf(" %.5lf\t%5.lf\t\t Y Q V\n",v[i].wight,v[i].fale);
			else
				printf(" %.5lf\t%5.lf\t\t Y Q %2c\n",v[i].wight,v[i].fale,v[i].changwei);
		}
		//printf("%.5lf\t\t%5.lf\t\t%2c\n",v[i].wight,v[i].fale,v[i].changwei);
	}  
	return 0;
} 

