#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout<<"无参构造"<<endl;
	}
	~Maker()
	{
		cout<<"析构"<<endl;
	}
private:
	int a;
	int b;
};

void test3()
{
	Maker* pMaker = new Maker;
	delete pMaker;
	pMaker = NULL;
}

void test4()
{
	int *p = new int[10];
	int i = 0;
	for(i=0;i<10;i++)
	{
		*(p+i)=i+1;
	}
	for(i=0;i<10;i++)
	{
		cout<< *(p+i)<<" ";
	}
	cout<<endl;
	delete[] p;
	p=NULL;
}

void test5()
{	//申请2个Maker类的空间->调用两次构造函数
	Maker* pMaker = new Maker[2];
	//释放2个Maker类的空间->调用两次析构函数
	delete[] pMaker;
}

void test6()
{
	void* p = new Maker;
	delete p;
	p=NULL;
}

int main2()
{
	test6();
	system("pause");
	return 0;
}