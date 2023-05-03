#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Maker
{
public:
	//构造函数(无参)
	Maker()
	{
		cout<< "无参构造" <<endl;
		a = 20;	
	}

	//有参构造
	Maker(int a)
	{
		cout<< "有参构造" <<endl;
		this->a = a;
	}

	//拷贝构造
	Maker(const Maker &m)
	{
		cout<< "拷贝构造" <<endl;
		a = m.a;
	}
	//析构函数
	~Maker()
	{
		cout<< "析构函数" <<endl;
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
	Maker(10);//匿名对象
	cout<< "***********" <<endl;
	Maker m = Maker();//有名字接->不是匿名对象
	cout<< "***********" <<endl;
}
Maker fun()
{
	Maker m1;
	cout<< "局部变量的地址 m1："<<&m1 <<endl;
	return m1;
}

void test2()
{
	Maker m2 = fun();//debug模式会调用拷贝构造，Qt、release模式下不会调用拷贝构造
	cout<< "m2的地址："<<&m2<<endl;
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