#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class People
{
public:
	virtual void callname()
	{
		cout<< "人" <<endl;
	}
};
class Xishi:public People
{
public:
	virtual void callname()
	{//重写父类虚函数
		cout<< "西施" <<endl;
	}
};
class Diaochan:public People
{
public:
	virtual void callname()
	{//重写父类虚函数
		cout<< "貂蝉" <<endl;
	}
};
class Wangzhaojun:public People
{
public:
	virtual void callname()
	{//重写父类虚函数
		cout<< "王昭君" <<endl;
	}
};

void call(People* p)
{//同一操作,不同对象调用。
	p->callname();
}

void test1()
{
	People* p = new People;
	p->callname();
	call(p);	//同一操作,不同对象调用。效果不同
	delete p;
	
	p = new Xishi;
	p->callname();
	call(p);	//同一操作,不同对象调用。效果不同
	delete p;

	p = new Diaochan;
	p->callname();
	call(p);	//同一操作,不同对象调用。效果不同
	delete p;

	p = new Wangzhaojun;
	p->callname();
	call(p);	//同一操作,不同对象调用。效果不同
	delete p;
	p = NULL;
}

int main()
{
	test1();
	system("pause");
	return 0;
}