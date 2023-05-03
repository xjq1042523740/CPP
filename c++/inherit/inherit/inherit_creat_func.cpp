#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father
{
public:
	Father()
	{
		cout<< "Father构造" <<endl;
	}
	~Father()
	{
		cout<< "Father析构" <<endl;
	}
};
class Son:public Father
{
public:
	Son()
	{
		cout<< "Son构造" <<endl;
	}
	~Son()
	{
		cout<< "Son析构" <<endl;
	}
};

class A
{
public:
	A()
	{
		cout<< "A构造" <<endl;
	}
	~A()
	{
		cout<< "A析构" <<endl;
	}
private:

};

class B:public A
{
public:
	B()
	{
		cout<< "B构造" <<endl;
	}
	~B()
	{
		cout<< "B析构" <<endl;
	}
private:
	Father f;
};

void test2()
{//判断先父类还是先子类
	Son s;	//先父类后子类
}
void test3()	
{//判断成员对象存在时的调用顺序
	B b;	//先父类，再成员对象，再子类。
}

int main2()
{
	test3();
	system("pause");
	return 0;
}