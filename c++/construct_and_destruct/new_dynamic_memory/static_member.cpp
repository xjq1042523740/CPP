#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stdlib.h>
#include<assert.h>
using namespace std;

class Maker2
{
public:
	Maker2()
	{
		cout<<"�޲ι���"<<endl;
	}
	~Maker2()
	{
		cout<<"��������"<<endl;
	}

	static void setA(int a)
	{//��̬��Ա�������ܵ��÷Ǿ�̬��Ա��
		a1 = a;	
	}

	void fun()
	{
		int c=a1;
		cout<<a1<<a2<<endl;
	}
public:
	
	//static��Ա������������Ϊ�������������������ڡ�
	static int a1;
	int a2;
	const static int b1 = 55;
	const static int b2;
};
//static��Ա���������������������ʼ��
int Maker2::a1 = 100;
const int Maker2::b2 = 66;
void test7()
{
	Maker2 m;
	//��̬��Ա��������������ʣ�Ҳ�����ö������
	cout<<m.a1<<endl;
	//��̬��Ա���������࣬�����ڶ��������ж�����
	cout<<Maker2::a1<<endl;
	m.setA(11);
	cout<<Maker2::a1<<endl;

}


//thisָ��
class Maker3
{
public:
	int fun()
	{
		int w = 11;
		return w;
	}
	void fun1()
	{
		assert(this!=NULL);
		cout<<this->fun()<<endl;
	}
	Maker3* address()
	{
		return this;
	}
public:
	int a;
	char b[3];
	int c;
	
};
void test8()
{
	cout<<Maker2::b1<<endl;
	cout<<Maker2::b2<<endl;
	Maker2 m;
	m.a2 = 21;
	m.fun();
}

void test9()
{
	cout<<sizeof(Maker3)<<endl;
	Maker3 c;
	c.fun1();
}

void test10()
{
	Maker3 m;
	Maker3* p = m.address();
	cout<<"&m:"<<&m<<"\t&(m.a):"<<&(m.a)<<"\t this:"<<p<<endl;
}


//������
class Maker5
{
public:
	Maker5()
	{
		a=10;
		b=20;
		d=5;
	}
	void Print()const	//���������൱�ڴ�const Maker*const this����>this��thisָ������ݶ����ܱ䡣
	{
		//a=1;err
		cout<<"a="<<a<<endl;
		d=100;				//mutable���εĳ�Ա�����ڳ������п����޸�
		cout<<"d="<<d<<endl;
	}
private:
	mutable int d;//mutable���εĳ�Ա����
	int a;
	int b;
};

void test11()
{
	Maker5 m;
	m.Print();
}
int main()
{
	test11();
	system("pause");
	return 0;
}