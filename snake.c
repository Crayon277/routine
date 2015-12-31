// libin.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<stdio.h>
/* #include<windows.h> */
#include<time.h>
#include<stdlib.h>

struct Body//定义蛇身结构体
{
	short x,y;//蛇身结点的坐标
	struct Body *next;//指向下一个结点的指针
};

////////////////////全局变量/////////////////////////////////////
int len=sizeof(struct Body);//Body结构体所占字节数

int score;//玩家得分

int Food=0;//1-有食物,0-没食物
short food_x,food_y;//食物坐标

struct Body *body001;//蛇头指针



int dir=4;//蛇头方向1-up,2-down,3-left,4-right

int sleeptime=220;//每次移动之后的停顿时间

////////////////////////函数声明/////////////////////////////////////
void Pos(short x,short y);
void CreatMap();
void PrintSnake();
void CreatFood();
void SnakeMove();
//int TouchWall();//不可穿墙
void CrossWall();//可以穿墙
int TouchSelf();
void Init();
void GameCircle();
void Pause();
void StartImage();
void EndImage();

////////////////////////函数定义/////////////////////////////////////
void Pos(short x,short y)//设置光标位置函数
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,pos);
	return;
}//Pos

void CreatMap()//打印地图
{
	int i;
	for(i=0;i<57;i+=2)//打印上下边框
	{
		Pos(i,0);
		printf("■");
		Pos(i,24);
		printf("■");
	}
	for(i=1;i<24;i++)//打印左右边框
	{
		Pos(0,i);
		printf("■");			
		Pos(56,i);
		printf("■");	
	}
	return;
}//CreatMap

void PrintSnake()//打印蛇
{
	struct Body *p=body001;
	while(p!=NULL)//判断是否指向蛇尾
	{
		Pos(p->x,p->y);
		printf("■");
		p=p->next;
	}//从蛇头打印到蛇尾
	return ;
}

void CreatFood()//创建新食物
{
	if(Food==0)
	{		
		srand((int)time(0));
		food_x=2+rand()%53;//x的取值范围[2,54]
		if(food_x%2==1)
			food_x--;
		food_y=1+rand()%23;//y的取值范围[1,23]
		Food=1;//1表明有食物，0表明没食物
	}
	return;
}//CreatFood

void SnakeMove()//蛇身移动、刷新蛇身和食物及其坐标
{
	struct Body *p_food;//下一格有食物
	struct Body *p_forward;//下一格没食物
	struct Body *q;//蛇身移动一格时的临时指针
	p_forward=(struct Body *)malloc(len);	
	if(1==dir)//向上移动
	{
		if(body001->x==food_x && body001->y-1==food_y)//下一格有食物
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("分数:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("食物坐标:        ");
			Pos(62,7);printf("食物坐标:%u,%u",food_x,food_y);
		}
		else//下一格没有食物
		{
			p_forward->x=body001->x;//横坐标不变
			p_forward->y=body001->y-1;//纵坐标-1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//使q指向倒数第二个结点
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//移动光标到蛇尾
			printf(" ");//删除蛇尾
			free(q->next); //释放蛇尾
			q->next=NULL;//使倒数第二个结点成为新的蛇尾
		}//else
	}

	if(2==dir)//向下移动
	{
		
		if(body001->x==food_x && body001->y+1==food_y)//下一格有食物
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("分数:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("食物坐标:        ");
			Pos(62,7);printf("食物坐标:%u,%u",food_x,food_y);
		}
		else//下一格没有食物
		{
			p_forward->x=body001->x;//横坐标不变
			p_forward->y=body001->y+1;//纵坐标+1
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//使q指向倒数第二个结点
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//移动光标到蛇尾
			printf(" ");//删除蛇尾
			free(q->next); //释放蛇尾
			q->next=NULL;//使倒数第二个结点成为新的蛇尾
		}//else
	}

	if(3==dir)//向左移动
	{
		if(body001->x-2==food_x && body001->y==food_y)//下一格有食物
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Pos(62,3);printf("分数:%d",score);
			Food=0;
			CreatFood();
			Pos(62,7);printf("食物坐标:        ");
			Pos(62,7);printf("食物坐标:%u,%u",food_x,food_y);
		}
		else//下一格没有食物
		{
			p_forward->x=body001->x-2;//横坐标-2
			p_forward->y=body001->y;//纵坐标不变
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//使q指向倒数第二个结点
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//移动光标到蛇尾
			printf(" ");//删除蛇尾
			free(q->next); //释放蛇尾
			q->next=NULL;//使倒数第二个结点成为新的蛇尾
		}//else
	}

	if(4==dir)//向右移动
	{
		if(body001->x+2==food_x && body001->y==food_y)//下一格有食物
		{
			p_food=(struct Body *)malloc(len);
			p_food->x=food_x;
			p_food->y=food_y;
			p_food->next=body001;
			body001=p_food;
			score+=5;
			Food=0;
			Pos(62,3);printf("分数:%d",score);
			CreatFood();
			Pos(62,7);printf("食物坐标:        ");
			Pos(62,7);printf("食物坐标:%u,%u",food_x,food_y);
		}
		else//下一格没有食物
		{
			p_forward->x=body001->x+2;//横坐标=2
			p_forward->y=body001->y;//纵坐标不变
			p_forward->next=body001;
			body001=p_forward;
			q=body001;
			while((q->next)->next!=NULL)//使q指向倒数第二个结点
				q=q->next;
			Pos((q->next)->x,(q->next)->y);//移动光标到蛇尾
			printf(" ");//删除蛇尾
			free(q->next); //释放蛇尾
			q->next=NULL;//使倒数第二个结点成为新的蛇尾
		}//else
	}
	Pos(62,9);printf("蛇头坐标:        ");
	Pos(62,9);printf("蛇头坐标:%u,%u",body001->x,body001->y);//打印蛇头坐标
	Pos(food_x,food_y);printf("■");//打印食物
	PrintSnake();//打印蛇
} 


/*int TouchWall()//不可穿墙
{
	if(body001->x==0 || body001->x==56 || body001->y==0 || body001->y==24)
		return 1;
	else 
		return 0;
}//TouchWall*/

void CrossWall()//可以穿墙
{
	if(0==body001->x)//左进右出
	{
		body001->x=54;
		if(food_x==body001->x && food_y==body001->y)
			food_x-=2;
	}
	if(56==body001->x)//右进左出
	{
		body001->x=2;
		if(food_x==body001->x && food_y==body001->y)
			food_x+=2;
	}
	if(0==body001->y)//上进下出
	{
		body001->y=23;
		if(food_x==body001->x && food_y==body001->y)
			food_y--;
	}
	if(24==body001->y)//下进上出
	{
		body001->y=1;
		if(food_x==body001->x && food_y==body001->y)
			food_y++;
	}
	return;
}

int TouchSelf()//判断是否咬到自己
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

void Init()//游戏初始化
{
	CreatMap();//打印地图
    Pos(62,1);printf("作者：李斌");
	Pos(62,3);printf("分数:%d",score);
	Pos(62,5);printf("速度:      ");
	Pos(62,5);printf("速度:%d",20+300-sleeptime);
	Pos(62,13);printf("F1 加速");
	Pos(62,15);printf("F2 减速");
	Pos(62,17);printf("↑ ↓ ← →方向");
	Pos(62,19);printf("SPACE 暂停/开始");
	Pos(62,21);printf("ESC 退出");
	Pos(62,23);printf("QQ：1010305129");
	struct Body *body002,*body003,*body004;//定义四个指向蛇身的指针

	body001=(struct Body *)malloc(len);//创建4个蛇身结构体
	body002=(struct Body *)malloc(len);
	body003=(struct Body *)malloc(len);
	body004=(struct Body *)malloc(len);

	body001->next=body002;//把蛇身连接起来，形成链表
	body002->next=body003;
	body003->next=body004;
	body004->next=NULL;

	Pos(body001->x=12,body001->y=8);printf("■");//设定并打印蛇身的初始位置
	Pos(body002->x=10,body002->y=8);printf("■");
	Pos(body003->x=8,body003->y=8);printf("■");
	Pos(body004->x=6,body004->y=8);printf("■");

    CreatFood();//打印食物
	Pos(62,7);printf("食物坐标:        ");
	Pos(62,7);printf("食物坐标:%u,%u",food_x,food_y);
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

void GameCircle()//游戏循环
{
	while(1)
	{
//		if (1== TouchWall() )//不可穿墙
//			break;//撞墙Game Over

		CrossWall();//可以穿墙

		if(1== TouchSelf() )//判断蛇是否咬到自己
			break;//咬到自己Game Over

		//判断用户的按键输入
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
		else if(GetAsyncKeyState(VK_F1))//加速
		{
			if(sleeptime>=110)
				sleeptime-=10;
			Pos(62,5);printf("速度:      ");
			Pos(62,5);printf("速度:%d",20+300-sleeptime);
		}
		else if(GetAsyncKeyState(VK_F2))//减速
		{
			if(sleeptime<=290)
				sleeptime+=10;
			Pos(62,5);printf("速度:      ");
			Pos(62,5);printf("速度:%d",20+300-sleeptime);
		}

		SnakeMove();//蛇移动一格
		
		Sleep(sleeptime);//设定两次移动之间的时间间隔
	} 
} 

void StartImage()
{
	Pos(28,6);
	printf("李斌，邀请你玩贪吃蛇");
	Pos(28,11);
	printf("贪吃蛇    作者：李斌");
	Pos(21,23);
	printf("2013.12.27晚于西安文理学院二号公寓");
	Pos(28,13);
	system("pause");
	system("cls");

	Pos(25,9);
	printf("-->终于编译成功啦<--");
	Pos(21,23);
	printf("2013.12.27晚于西安文理学院二号公寓");
	Pos(26,13);
	system("pause");
	system("cls");
} 

void EndImage()
{
	system("cls");
	Pos(30,9);printf("游戏结束，欢迎再来！");
	Pos(30,11);printf("你的得分：%d",score);
	Pos(30,16);printf("娃，你还得继续努力啊！");
	Pos(20,23);printf("2013.12.27晚于西安文理学院二号公寓");
	Pos(28,13);
	system("pause");
}

/////////////////////////main函数////////////////////////////////////////
int main(void)
{
	StartImage();//开始画面

	Init();//界面初始化

	GameCircle();//游戏循环

	EndImage();//结束画面

	return 0;
} 
