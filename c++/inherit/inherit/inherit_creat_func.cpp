#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father
{
public:
	Father()
	{
		cout<< "Father����" <<endl;
	}
	~Father()
	{
		cout<< "Father����" <<endl;
	}
};
class Son:public Father
{
public:
	Son()
	{
		cout<< "Son����" <<endl;
	}
	~Son()
	{
		cout<< "Son����" <<endl;
	}
};

class A
{
public:
	A()
	{
		cout<< "A����" <<endl;
	}
	~A()
	{
		cout<< "A����" <<endl;
	}
private:

};

class B:public A
{
public:
	B()
	{
		cout<< "B����" <<endl;
	}
	~B()
	{
		cout<< "B����" <<endl;
	}
private:
	Father f;
};

void test2()
{//�ж��ȸ��໹��������
	Son s;	//�ȸ��������
}
void test3()	
{//�жϳ�Ա�������ʱ�ĵ���˳��
	B b;	//�ȸ��࣬�ٳ�Ա���������ࡣ
}

int main2()
{
	test3();
	system("pause");
	return 0;
}