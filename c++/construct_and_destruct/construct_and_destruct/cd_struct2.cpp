#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class BWM
{
public:
	BWM()
	{
		cout<< "BWM无参构造" <<endl;
	}

	BWM(int a)
	{
		cout<< "BWM有参构造" <<endl;
	}

	~BWM()
	{
		cout << "BWM析构函数" <<endl;
	}

private:
	string BWMColor;
	int BWMSize;
};

class BUIK
{
public:
	BUIK()
	{
		cout<< "BUIK无参构造" <<endl;
	}
	BUIK(int a)
	{
		cout<< "BUIK有参构造" <<endl;
	}

	~BUIK()
	{
		cout << "BUIK析构函数" <<endl;
	}
private:
	string BUIKColor;
	int BUIKSize;
};

class Maker1
{
public:
	Maker1():bwm(10), buik(20)//初始化列表，若有多个对象成员需要指定构造函数类型，用逗号隔开。
	{
		cout<< "Maker1无参构造" <<endl;
	}
	Maker1(int a,int b):bwm(a),buik(b) //只要某一个构造函数使用了初始化列表，那么所有的构造函数都要写初始化列表
	{
		cout<< "Maker1有参构造" <<endl;
	}
	~Maker1()
	{
		cout << "Maker1析构函数" <<endl;
	}
private:
	BWM bwm;	//创建BWM类的对象
	BUIK buik;	//创建BUIK类的对象
};

void test4()
{
	Maker1 m(5,10);
}
int main()
{
	test4();
	system("pause");
	return 0;
}