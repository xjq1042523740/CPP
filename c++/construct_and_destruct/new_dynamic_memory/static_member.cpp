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
		cout<<"无参构造"<<endl;
	}
	~Maker2()
	{
		cout<<"析构函数"<<endl;
	}

	static void setA(int a)
	{//静态成员函数不能调用非静态成员。
		a1 = a;	
	}

	void fun()
	{
		int c=a1;
		cout<<a1<<a2<<endl;
	}
public:
	
	//static成员变量生命周期为整个程序，作用域在类内。
	static int a1;
	int a2;
	const static int b1 = 55;
	const static int b2;
};
//static成员变量在类内声明在类外初始化
int Maker2::a1 = 100;
const int Maker2::b2 = 66;
void test7()
{
	Maker2 m;
	//静态成员变量可以用类访问，也可以用对象访问
	cout<<m.a1<<endl;
	//静态成员变量属于类，不属于对象，是所有对象共享
	cout<<Maker2::a1<<endl;
	m.setA(11);
	cout<<Maker2::a1<<endl;

}


//this指针
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


//常函数
class Maker5
{
public:
	Maker5()
	{
		a=10;
		b=20;
		d=5;
	}
	void Print()const	//常函数：相当于传const Maker*const this——>this和this指向的内容都不能变。
	{
		//a=1;err
		cout<<"a="<<a<<endl;
		d=100;				//mutable修饰的成员变量在常函数中可以修改
		cout<<"d="<<d<<endl;
	}
private:
	mutable int d;//mutable修饰的成员变量
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