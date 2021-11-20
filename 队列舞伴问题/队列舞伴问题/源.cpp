#include<stdio.h>
#define MAXQSIZE 100
#define QueueSize 20
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#include<cstdlib>
#include<iostream>
using namespace std;

typedef char QElemType;
typedef int Status;		//typedef char SElemType

typedef struct
{
	char name[QueueSize];
	char sex;
}person;

typedef struct      //what mean of it
{
	person* dancer;
	person* base;	//存储空间的基地址
	int front;		//头指针
	int rear;		//尾指针
}SqQueue;

Status InitQueue(SqQueue& Q)
{//构造一个空队列
	Q.base = new person[MAXQSIZE];		//为队列分配一个最大容量为MAXQSIZE的数组空间
	if (!Q.base)exit(OVERFLOW);			//what it is 存储分配失败
	Q.front = Q.rear = 0;				//头指针和尾指针为零，队列为空。
	return OK;
}

Status EnQueue(SqQueue& Q, person e)
{//插入元素e为Q的新的队尾元素
	if ((Q.rear + 1) % MAXQSIZE == Q.front)	//尾指针在循环意义上加1后等于头指针，表明对列满
		return ERROR;
	Q.base[Q.rear] = e;						//新元素插入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE;		//队尾指针加1
	return OK;
}

int QueueEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)		return OK;
	else return ERROR;
}

Status DeQueue(SqQueue& Q, person& e)
{//删除Q的队列元素，不修改队头指针
	if (Q.front == Q.rear)	return ERROR;	//队空
	e = Q.base[Q.front];					//保留队头元素
	Q.front = (Q.front + 1) % MAXQSIZE;		//队头指针加1
	return OK;
}

person GetHead(SqQueue Q)
{//返回Q的队列元素，不修改队头指针
	if (Q.front != Q.rear)					//队列非空
		return Q.base[Q.front];				//返回队头元素的值，对头指针不变
}

void DancePartner(person dancer[], int num)
{//结构数组dancer中存放跳舞的男女，num 是跳舞的人数
	person p;
	int i;
	SqQueue Mdancera, Fdancera;
	InitQueue(Mdancera);					//男士队列初始化
	InitQueue(Fdancera);					//女生对列初始化
	
	for (i = 0; i < num; i++)				//根据性别依次将跳舞的人插入相应的队列
	{
		p = dancer[i];
		if (p.sex == 'F') EnQueue(Fdancera, p);
		else EnQueue(Mdancera,p);
	}
	cout << "the dancing partner are:\n";
	
	while (!QueueEmpty(Fdancera) && !QueueEmpty(Mdancera))
	{//依次输出男女舞伴的姓名
		DeQueue(Fdancera, p);				//女生出队
		cout << p.name << "";				//输出出队女生的姓名
		DeQueue(Mdancera, p);				//男士出队
		cout << p.name << endl;				//输出出队男士的姓名
		
	}
	
	if (!QueueEmpty(Fdancera))				//女士队列非空，输出队头女士姓名
	{
		p = GetHead(Fdancera);				//取女队的头
		cout << p.name << "is waiting for a partner ." << endl;
	}

	else if(!QueueEmpty(Mdancera))			//男士队列非空，输出男士队头的姓名
	{
		p = GetHead(Mdancera);				//取男队的头
		cout << p.name << "is waiting for a partner." << endl;
	}
}

int main()
{
	int i, j;
	person dancer[QueueSize];
	cout << "请输入跳舞的人数：";
	cin >> j;								//question
	while (j <= 0)
	{
		cout << "输入错误，请重新输入跳舞的人数：";
		cin >> j;
	}

	for (i = 1; i <= j; i++)
	{
		cout << "请输入第" << i << "舞者的名字：" << endl;
		cin >> dancer[i - 1].name;
		cout << "请输入第" << i << "个人的性别（F/M):" << endl;
		cin >> dancer[i - 1].sex;
		
		while (dancer[i - 1].sex != 'F' && dancer[i - 1].sex!='M')
		{
			cout << "********输入错误，请重新输入：\n";
			cout << dancer[i - 1].sex;
			cout << "请输入第" << i << "个人的性别(F/M):" << endl;
			cin >> dancer[i - 1].sex;
			break;
		}
	}
	DancePartner(dancer, j);
}
