#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father
{
public:
	int a;
	/*void fun1()
	{
		cout<< "fun1" <<endl;
	}
	void fun2()
	{
		cout<< "fun2" <<endl;
	}*/
private:
	int b;
protected:
	int c;
};

//���м̳�
class Son1:public Father
{
public:
	void fun()
	{
		a;
		//b;
		c;
	}
};

//˽�м̳�
class Son2:private Father
{
public:
	void fun()
	{
		a;
		//b;
		c;
	}
};
//�����̳�
class Son3: protected Father
{
public:
	void fun()
	{
		a;
		//b;
		c;
	}
};
class Son33: public Son2
{
public:
	void fun()
	{
	//	a;
	//	b;
	//	c;
	}
};

void test1()
{
	Son1 s1;
	s1.a;
	//s1.b;
	//s1.c;
	Son2 s2;
	//s2.a;
	//s2.b;
	//s2.c;
	Son3 s3;
	//s3.a;
	//s3.b;
	//s3.c;
}

int main1()
{
	test1();
	system("pause");
	return 0;
}