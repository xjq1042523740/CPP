#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class People
{
public:
	virtual void callname()
	{
		cout<< "��" <<endl;
	}
};
class Xishi:public People
{
public:
	virtual void callname()
	{//��д�����麯��
		cout<< "��ʩ" <<endl;
	}
};
class Diaochan:public People
{
public:
	virtual void callname()
	{//��д�����麯��
		cout<< "����" <<endl;
	}
};
class Wangzhaojun:public People
{
public:
	virtual void callname()
	{//��д�����麯��
		cout<< "���Ѿ�" <<endl;
	}
};

void call(People* p)
{//ͬһ����,��ͬ������á�
	p->callname();
}

void test1()
{
	People* p = new People;
	p->callname();
	call(p);	//ͬһ����,��ͬ������á�Ч����ͬ
	delete p;
	
	p = new Xishi;
	p->callname();
	call(p);	//ͬһ����,��ͬ������á�Ч����ͬ
	delete p;

	p = new Diaochan;
	p->callname();
	call(p);	//ͬһ����,��ͬ������á�Ч����ͬ
	delete p;

	p = new Wangzhaojun;
	p->callname();
	call(p);	//ͬһ����,��ͬ������á�Ч����ͬ
	delete p;
	p = NULL;
}

int main()
{
	test1();
	system("pause");
	return 0;
}