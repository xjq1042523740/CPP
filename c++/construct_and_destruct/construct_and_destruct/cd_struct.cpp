#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Maker
{
public:
	//���캯��(�޲�)
	Maker()
	{
		cout<< "�޲ι���" <<endl;
		a = 20;	
	}

	//�вι���
	Maker(int a)
	{
		cout<< "�вι���" <<endl;
		this->a = a;
	}

	//��������
	Maker(const Maker &m)
	{
		cout<< "��������" <<endl;
		a = m.a;
	}
	//��������
	~Maker()
	{
		cout<< "��������" <<endl;
	}

	void PrintMaker()
	{
		cout<<"a="<<a<<endl;
	}

	
private:
	int a;
};

void test0()
{
	Maker m;
	Maker m1(10);
	Maker m2(m);
	m1.PrintMaker();
	m2.PrintMaker();
}

void test1()
{
	Maker(10);//��������
	cout<< "***********" <<endl;
	Maker m = Maker();//�����ֽ�->������������
	cout<< "***********" <<endl;
}
Maker fun()
{
	Maker m1;
	cout<< "�ֲ������ĵ�ַ m1��"<<&m1 <<endl;
	return m1;
}

void test2()
{
	Maker m2 = fun();//debugģʽ����ÿ������죬Qt��releaseģʽ�²�����ÿ�������
	cout<< "m2�ĵ�ַ��"<<&m2<<endl;
}

void test3()
{
	Maker m;
}
int main1()
{
	test2();
	system("pause");
	return 0;
}