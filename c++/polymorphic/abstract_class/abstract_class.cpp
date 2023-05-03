#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//�����/������
class rule
{//���������ǲ��ܱ�ʵ�����ġ�
public:
	//���麯����
	virtual int getnum(int a, int b) = 0;
};

//ʵ�ֲ�
class plus_rule:public rule
{
public:
	virtual int getnum(int a, int b)
	{//��д������麯�������������
		return a+b;
	}
};
class minus_rule:public rule
{
public:
	virtual int getnum(int a, int b)
	{//��д������麯�������������
		return a-b;
	}
};

//ҵ���
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
	{//ʵ�ִ�����func1
		return 0;
	}
	//δʵ�ִ�����func2,���Ը��໹��һ�������ࡣ
};
class Son2:public Father
{
public:
	virtual int func1()
	{//ʵ�ִ�����func1
		return 0;
	}
	virtual int func2()
	{//ʵ�ִ�����func2
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