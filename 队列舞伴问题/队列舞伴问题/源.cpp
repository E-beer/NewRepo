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
	person* base;	//�洢�ռ�Ļ���ַ
	int front;		//ͷָ��
	int rear;		//βָ��
}SqQueue;

Status InitQueue(SqQueue& Q)
{//����һ���ն���
	Q.base = new person[MAXQSIZE];		//Ϊ���з���һ���������ΪMAXQSIZE������ռ�
	if (!Q.base)exit(OVERFLOW);			//what it is �洢����ʧ��
	Q.front = Q.rear = 0;				//ͷָ���βָ��Ϊ�㣬����Ϊ�ա�
	return OK;
}

Status EnQueue(SqQueue& Q, person e)
{//����Ԫ��eΪQ���µĶ�βԪ��
	if ((Q.rear + 1) % MAXQSIZE == Q.front)	//βָ����ѭ�������ϼ�1�����ͷָ�룬����������
		return ERROR;
	Q.base[Q.rear] = e;						//��Ԫ�ز����β
	Q.rear = (Q.rear + 1) % MAXQSIZE;		//��βָ���1
	return OK;
}

int QueueEmpty(SqQueue& Q)
{
	if (Q.front == Q.rear)		return OK;
	else return ERROR;
}

Status DeQueue(SqQueue& Q, person& e)
{//ɾ��Q�Ķ���Ԫ�أ����޸Ķ�ͷָ��
	if (Q.front == Q.rear)	return ERROR;	//�ӿ�
	e = Q.base[Q.front];					//������ͷԪ��
	Q.front = (Q.front + 1) % MAXQSIZE;		//��ͷָ���1
	return OK;
}

person GetHead(SqQueue Q)
{//����Q�Ķ���Ԫ�أ����޸Ķ�ͷָ��
	if (Q.front != Q.rear)					//���зǿ�
		return Q.base[Q.front];				//���ض�ͷԪ�ص�ֵ����ͷָ�벻��
}

void DancePartner(person dancer[], int num)
{//�ṹ����dancer�д���������Ů��num �����������
	person p;
	int i;
	SqQueue Mdancera, Fdancera;
	InitQueue(Mdancera);					//��ʿ���г�ʼ��
	InitQueue(Fdancera);					//Ů�����г�ʼ��
	
	for (i = 0; i < num; i++)				//�����Ա����ν�������˲�����Ӧ�Ķ���
	{
		p = dancer[i];
		if (p.sex == 'F') EnQueue(Fdancera, p);
		else EnQueue(Mdancera,p);
	}
	cout << "the dancing partner are:\n";
	
	while (!QueueEmpty(Fdancera) && !QueueEmpty(Mdancera))
	{//���������Ů��������
		DeQueue(Fdancera, p);				//Ů������
		cout << p.name << "";				//�������Ů��������
		DeQueue(Mdancera, p);				//��ʿ����
		cout << p.name << endl;				//���������ʿ������
		
	}
	
	if (!QueueEmpty(Fdancera))				//Ůʿ���зǿգ������ͷŮʿ����
	{
		p = GetHead(Fdancera);				//ȡŮ�ӵ�ͷ
		cout << p.name << "is waiting for a partner ." << endl;
	}

	else if(!QueueEmpty(Mdancera))			//��ʿ���зǿգ������ʿ��ͷ������
	{
		p = GetHead(Mdancera);				//ȡ�жӵ�ͷ
		cout << p.name << "is waiting for a partner." << endl;
	}
}

int main()
{
	int i, j;
	person dancer[QueueSize];
	cout << "�����������������";
	cin >> j;								//question
	while (j <= 0)
	{
		cout << "����������������������������";
		cin >> j;
	}

	for (i = 1; i <= j; i++)
	{
		cout << "�������" << i << "���ߵ����֣�" << endl;
		cin >> dancer[i - 1].name;
		cout << "�������" << i << "���˵��Ա�F/M):" << endl;
		cin >> dancer[i - 1].sex;
		
		while (dancer[i - 1].sex != 'F' && dancer[i - 1].sex!='M')
		{
			cout << "********����������������룺\n";
			cout << dancer[i - 1].sex;
			cout << "�������" << i << "���˵��Ա�(F/M):" << endl;
			cin >> dancer[i - 1].sex;
			break;
		}
	}
	DancePartner(dancer, j);
}
