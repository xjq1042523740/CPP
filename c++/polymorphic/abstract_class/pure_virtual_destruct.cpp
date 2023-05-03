#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father3
{
public:
	Father3()
	{
		cout<<"Father的构造函数"<<endl;
	}
	virtual ~Father3() = 0;		//纯虚析构函数
};
Father3::~Father3()
{//纯虚析构函数要在类外实现
	cout<<"Father的纯虚析构函数"<<endl;
}

class Son3:public Father3
{
public:
	Son3()
	{
		cout<<"Son的构造函数"<<endl;
		p = new int[10];
	}
	~Son3()
	{//如果父类不使用虚析构函数，那么就不会调用子类的析构函数，则会造成内存泄露。
		cout<<"Son的析构函数"<<endl;
		delete[] p;
	}
	int* p;
};
void test3()
{
	Father3* fp = new Son3;
	delete fp;
}
int main()
{
	test3();
	system("pause");
	return 0;
}