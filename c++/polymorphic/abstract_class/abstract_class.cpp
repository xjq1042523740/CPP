#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//抽象层/抽象类
class rule
{//抽象层的类是不能被实例化的。
public:
	//纯虚函数：
	virtual int getnum(int a, int b) = 0;
};

//实现层
class plus_rule:public rule
{
public:
	virtual int getnum(int a, int b)
	{//重写父类的虚函数，依赖抽象层
		return a+b;
	}
};
class minus_rule:public rule
{
public:
	virtual int getnum(int a, int b)
	{//重写父类的虚函数，依赖抽象层
		return a-b;
	}
};

//业务层
int doLogin(rule* p)
{
	int a=10;
	int b=20;  
	int ret = p->getnum(a, b);
	return ret;
}

void test1()
{
	rule* p = new plus_rule;
	cout<<doLogin(p)<<endl;
	delete p;

	p = new minus_rule;
	cout<<doLogin(p)<<endl;
	delete p;
}

class Father
{
public:
	virtual int func1() = 0;
	virtual int func2() = 0;
};

class Son1:public Father
{
public:
	virtual int func1()
	{//实现纯虚类func1
		return 0;
	}
	//未实现纯虚类func2,所以该类还是一个抽象类。
};
class Son2:public Father
{
public:
	virtual int func1()
	{//实现纯虚类func1
		return 0;
	}
	virtual int func2()
	{//实现纯虚类func2
		return 0;
	}
};
void test2()
{
	Son2 s2;
}
int main1()
{
	test2();
	system("pause");
	return 0;
}