// libin.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include<stdio.h>
/* #include<windows.h> */
#include<time.h>
#include<stdlib.h>

struct Body//��������ṹ��
{
	short x,y;//�����������
	struct Body *next;//ָ����һ������ָ��
};

////////////////////ȫ�ֱ���/////////////////////////////////////
int len=sizeof(struct Body);//Body�ṹ����ռ�ֽ���

int score;//��ҵ÷�

int Food=0;//1-��ʳ��,0-ûʳ��
short food_x,food_y;//ʳ������

struct Body *body001;//��ͷָ��



int dir=4;//��ͷ����1-up,2-down,3-left,4-right

int sleeptime=220;//ÿ���ƶ�֮���ͣ��ʱ��

////////////////////////��������/////////////////////////////////////
void Pos(short x,short y);
void CreatMap();
void PrintSnake();
void CreatFood();
void SnakeMove();
//int TouchWall();//���ɴ�ǽ
void CrossWall();//���Դ�ǽ
int TouchSelf();
void Init();
void GameCircle();
void Pause();
void StartImage();
void EndImage();

////////////////////////��������/////////////////////////////////////
void Pos(short x,short y)//���ù��λ�ú���
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos);
	return;
}//Pos

void CreatMap()//��ӡ��ͼ
{
	int i;
	for(i=0;i<57;i+=2)//��ӡ���±߿�
	{
		Pos(i,0);
		printf("��");
		Pos(i,24);
		printf("��");
	}
	for(i=1;i<24;i++)//��ӡ���ұ߿�
	{
		Pos(0,i);
		printf("��");			
		Pos(56,i);
		printf("��");	
	}
	return;
}//CreatMap

void PrintSnake()//��ӡ��
{
	struct Body *p=body001;
	while(p!=NULL)//�ж��Ƿ�ָ����β
	{
		Pos(p->x,p->y);
		printf("��");
		p=p->next;
	}//����ͷ��ӡ����β
	return ;
}

void CreatFood()//������ʳ��
{
	if(Food==0)
	{		
		srand((int)time(0));
		food_x=2+rand()%53;//x��ȡֵ��Χ[2,54]
		if(food_x%2==1)
			food_x--;
		food_y=1+rand()%23;//y��ȡֵ��Χ[1,23]
		Food=1;//1������ʳ�0����ûʳ��
	}
	return;
}//CreatFood

void SnakeMove()//�����ƶ���ˢ�������ʳ�Ｐ������
{
	struct Body *p_food;//��һ����ʳ��
	struct Body *p_forward;//��һ��ûʳ��
	struct Body *q;//�����ƶ�һ��ʱ����ʱָ��
	p_forward=(struct Body *)malloc(len);	
	if(1==dir)//�����ƶ�
	{
		if(body001->x==food_x && body001->y-1==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y-1;//������-1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}

	if(2==dir)//�����ƶ�
	{
		
		if(body001->x==food_x && body001->y+1==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x;//�����겻��
			p_forward->y=body001->y+1;//������+1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}

	if(3==dir)//�����ƶ�
	{
		if(body001->x-2==food_x && body001->y==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("����:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x-2;//������-2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}

	if(4==dir)//�����ƶ�
	{
		if(body001->x+2==food_x && body001->y==food_y)//��һ����ʳ��
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Food=0;
			Pos(62,3);printf("����:%d",score);
			CreatFood();
			Pos(62,7);printf("ʳ������:        ");
			Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
		}
		else//��һ��û��ʳ��
		{
			p_forward->x=body001->x+2;//������=2
			p_forward->y=body001->y;//�����겻��
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//ʹqָ�����ڶ������
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//�ƶ���굽��β
			printf(" ");//ɾ����β
			free(q->next); //�ͷ���β
			q->next=NULL;//ʹ�����ڶ�������Ϊ�µ���β
		}//else
	}
	Pos(62,9);printf("��ͷ����:        ");
	Pos(62,9);printf("��ͷ����:%u,%u",body001->x,body001->y);//��ӡ��ͷ����
	Pos(food_x,food_y);printf("��");//��ӡʳ��
	PrintSnake();//��ӡ��
} 


/*int TouchWall()//���ɴ�ǽ
{
	if(body001->x==0 || body001->x==56 || body001->y==0 || body001->y==24)
		return 1;
	else 
		return 0;
}//TouchWall*/

void CrossWall()//���Դ�ǽ
{
	if(0==body001->x)//����ҳ�
	{
		body001->x=54;
		if(food_x==body001->x && food_y==body001->y)
			food_x-=2;
	}
	if(56==body001->x)//�ҽ����
	{
		body001->x=2;
		if(food_x==body001->x && food_y==body001->y)
			food_x+=2;
	}
	if(0==body001->y)//�Ͻ��³�
	{
		body001->y=23;
		if(food_x==body001->x && food_y==body001->y)
			food_y--;
	}
	if(24==body001->y)//�½��ϳ�
	{
		body001->y=1;
		if(food_x==body001->x && food_y==body001->y)
			food_y++;
	}
	return;
}

int TouchSelf()//�ж��Ƿ�ҧ���Լ�
{
	struct Body *p_tself;
	p_tself=body001;
	while(!p_tself->next==NULL)
	{
		p_tself=p_tself->next;
		if(p_tself->x==body001->x && p_tself->y==body001->y)
			return 1;
	}
	return 0;
} 

void Init()//��Ϸ��ʼ��
{
	CreatMap();//��ӡ��ͼ
    Pos(62,1);printf("���ߣ����");
	Pos(62,3);printf("����:%d",score);
	Pos(62,5);printf("�ٶ�:      ");
	Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
	Pos(62,13);printf("F1 ����");
	Pos(62,15);printf("F2 ����");
	Pos(62,17);printf("�� �� �� ������");
	Pos(62,19);printf("SPACE ��ͣ/��ʼ");
	Pos(62,21);printf("ESC �˳�");
	Pos(62,23);printf("QQ��1010305129");
	struct Body *body002,*body003,*body004;//�����ĸ�ָ�������ָ��

	body001=(struct Body *)malloc(len);//����4������ṹ��
	body002=(struct Body *)malloc(len);
	body003=(struct Body *)malloc(len);
	body004=(struct Body *)malloc(len);

	body001->next=body002;//�����������������γ�����
	body002->next=body003;
	body003->next=body004;
	body004->next=NULL;

	Pos(body001->x=12,body001->y=8);printf("��");//�趨����ӡ����ĳ�ʼλ��
	Pos(body002->x=10,body002->y=8);printf("��");
	Pos(body003->x=8,body003->y=8);printf("��");
	Pos(body004->x=6,body004->y=8);printf("��");

    CreatFood();//��ӡʳ��
	Pos(62,7);printf("ʳ������:        ");
	Pos(62,7);printf("ʳ������:%u,%u",food_x,food_y);
} 

void Pause()
{
	while(1)
	{
		Sleep(600);
		if(GetAsyncKeyState(VK_SPACE))
			break;
	}
	return;
} 

void GameCircle()//��Ϸѭ��
{
	while(1)
	{
//		if (1== TouchWall() )//���ɴ�ǽ
//			break;//ײǽGame Over

		CrossWall();//���Դ�ǽ

		if(1== TouchSelf() )//�ж����Ƿ�ҧ���Լ�
			break;//ҧ���Լ�Game Over

		//�ж��û��İ�������
//		int dir=4;
		if(GetAsyncKeyState(VK_UP) && dir!=2)
			dir=1;
		else if(GetAsyncKeyState(VK_DOWN) && dir!=1)
			dir=2;
		else if(GetAsyncKeyState(VK_LEFT) && dir!=4)
			dir=3;
		else if(GetAsyncKeyState(VK_RIGHT) && dir!=3)
			dir=4;
		else if(GetAsyncKeyState(VK_ESCAPE))
			break;
		else if(GetAsyncKeyState(VK_SPACE))
			Pause();
		else if(GetAsyncKeyState(VK_F1))//����
		{
			if(sleeptime>=110)
				sleeptime-=10;
			Pos(62,5);printf("�ٶ�:      ");
			Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
		}
		else if(GetAsyncKeyState(VK_F2))//����
		{
			if(sleeptime<=290)
				sleeptime+=10;
			Pos(62,5);printf("�ٶ�:      ");
			Pos(62,5);printf("�ٶ�:%d",20+300-sleeptime);
		}

		SnakeMove();//���ƶ�һ��
		
		Sleep(sleeptime);//�趨�����ƶ�֮���ʱ����
	} 
} 

void StartImage()
{
	Pos(28,6);
	printf("�����������̰����");
	Pos(28,11);
	printf("̰����    ���ߣ����");
	Pos(21,23);
	printf("2013.12.27������������ѧԺ���Ź�Ԣ");
	Pos(28,13);
	system("pause");
	system("cls");

	Pos(25,9);
	printf("-->���ڱ���ɹ���<--");
	Pos(21,23);
	printf("2013.12.27������������ѧԺ���Ź�Ԣ");
	Pos(26,13);
	system("pause");
	system("cls");
} 

void EndImage()
{
	system("cls");
	Pos(30,9);printf("��Ϸ��������ӭ������");
	Pos(30,11);printf("��ĵ÷֣�%d",score);
	Pos(30,16);printf("�ޣ��㻹�ü���Ŭ������");
	Pos(20,23);printf("2013.12.27������������ѧԺ���Ź�Ԣ");
	Pos(28,13);
	system("pause");
}

/////////////////////////main����////////////////////////////////////////
int main(void)
{
	StartImage();//��ʼ����

	Init();//�����ʼ��

	GameCircle();//��Ϸѭ��

	EndImage();//��������

	return 0;
} 
