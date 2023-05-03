#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Building
{
	//声明全局函数为友元
	friend void Change(Building &bud, int c, int d);
public:
	void Print()
	{
		cout<<"a="<<a<<"\tb="<<b<<endl;
	}
	Building()
	{
		cout<<"无参构造"<<endl;
		a = 10;
		b = 20;

	}
	~Building()
	{
		cout<<"析构函数"<<endl;
	}
private:
	int a;
	int b;
	string bedroom;
	string livingroom;
};


void Change(Building &bud, int c, int d)
{
	bud.a = c;
	bud.b = d;
}

void test0()
{
	Building bud;
	bud.Print();
	Change(bud, 100, 200);
	bud.Print();
}


class Building2
{
	//声明GoodF类为友元
	friend class GoodF;
public:
	void Print()
	{
		cout<<"bedroom="<<bedroom<<"\tlivingroom="<<livingroom<<endl;
	}
	Building2()
	{
		cout<<"无参构造"<<endl;
		bedroom = "卧室";
		livingroom = "客厅";
	}
	~Building2()
	{
		cout<<"析构函数"<<endl;
	}
private:
	string bedroom;
	string livingroom;
};

class GoodF
{
public:
	//1、通过传参来访问私有成员
	void visitB(Building2 &bud)
	{
		cout<<"bedroom="<<bud.bedroom<<"\tlivingroom="<<bud.livingroom<<endl;
	}
	//2、通过指针来访问私有成员
	void visitBud(Building2 *pbud)
	{
		cout<<"bedroom="<<pbud->bedroom<<"\tlivingroom="<<pbud->livingroom<<endl;
	}
};

void test1()
{
	Building2 bud;
	GoodF goodf;
	goodf.visitB(bud);
	goodf.visitBud(&bud);
}

class Building3;
class GoodF1
{//声明类的结构
public:
	void visitB3(Building3 &bud3);
};

class Building3
{
	//声明别的类的方法是友元
	friend void GoodF1::visitB3(Building3 &bud3);
public:
	void Print()
	{
		cout<<"bedroom="<<bedroom<<"\tlivingroom="<<livingroom<<endl;
	}
	Building3()
	{
		cout<<"无参构造"<<endl;
		bedroom = "卧室";
		livingroom = "客厅";
	}
	~Building3()
	{
		cout<<"析构函数"<<endl;
	}
private:
	string bedroom;
	string livingroom;
};

void GoodF1::visitB3(Building3 &bud3)
{
	cout<<"bedroom="<<bud3.bedroom<<"\tlivingroom="<<bud3.livingroom<<endl;
}

void test2()
{
	Building3 bud3;
	GoodF1 goodf1;
	goodf1.visitB3(bud3);
}

int main()
{
	test2();
	system("pause");
	return 0;
}