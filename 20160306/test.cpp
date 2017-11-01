/*-----------------------------------------------------------------
**测试环境 VS2010
**说明：没有设计算法得出Y,Q,V虚拟分配的座位数目，只是简单的进行排名
**-----------------------------------------------------------------
*/
//航空公司EMRS计算舱位分配
#include <iostream>
#include <stdio.h>
#include <vector>  
#include <algorithm>  
#include<cmath>
#include<string>
using namespace std;  
#define pi 3.1415926  //圆周率

//各类舱位属性说明
int shuxing[4][4]={'Y',1000,3,1,
	               'Q',700,8,4,
	               'V',500,10,5,};

//存储计算的所有排名 即有36个				   
struct paiming{
    double wight;
    char changwei;
	double fale;
};

//降序排列  	
int print_result(paiming a , paiming b)
{
	return a.fale > b.fale;
}

int main()
{	

	paiming Result;//中间变量
	vector<paiming>v;//存储需要的所有的SMSR值
	int zz=0;
	
	//对每一个类舱位进行计算
	for(int k=0;k<=2;k++)
	{
		int uu = shuxing[k][2]; //获取当前舱位的需求的均值 
		int xx = shuxing[k][3]; //获取当前舱位的需求的标准差 
		for(int j=1;j<=36;j++)
		{		
	        //计算概率值
			double q=0.0;
			double i=0.0;
			
			//迭代计算，对应计算 excle中的  NORMDIST(A2,6,2,1)
			while(i <= j)
			{
				q = q + 1/sqrt(2*pi)/xx*exp(-(i-uu)*(i-uu)/(2*xx*xx))*0.01;//标准正态分布
				i = i + 0.01;
			}
			
			Result.wight = 1-q;//对应Excle中     1-NORMDIST(A2,6,2,1)
			Result.changwei = shuxing[k][0];   //记录舱位
			Result.fale = Result.wight*shuxing[k][1];//计算EMSR值
			
			v.push_back(Result);//进得出的每一个结果放入vector中，循环完毕后共有36个
		}
	}
	
	
	sort(v.begin(),v.end(),print_result);  //对36组结果排名
	
	int H[4]={-1,-1,-1};
	int M[3] = {1,1}; //存储Y,Q的保护数，对于V的，直接进行1-Y-Q的即可
	
	
	//保护数计算
	for (int i =0;i < 12;i++)  
	{  
		if(v[i].changwei=='Y')//计算Y舱的保护数
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
		
		if(v[i].changwei=='Q')//计算Q舱的保护数
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
	
	
	//打印计算的结果
	
	//打印说明：结果不具有普适性，只是为了针对这道题目而言进行打印的
	
	
	printf("--------------------------------------------------\n");
	printf("Y舱位保护数为：%d\n",M[0]);
	printf("Q舱位保护数为：%d\n",M[1]);
	printf("V舱位保护数为：%d\n",12-M[0]-M[1]);
	//打印输出
	printf("--------------------------------------------------\n");
	printf("%s\t%s\t%s\t%s\n","座位号","期望概率","期望价格","舱位");
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

