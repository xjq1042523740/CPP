#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout<<"无参构造"<<endl;
	}
	void MakerPrint()
	{
		cout<<"hellow Maker"<<endl;
	}
	~Maker()
	{
		cout<<"析构函数"<<endl;
	}
private:

};
class SmartPoint
{
public:
	SmartPoint(Maker* p)
	{
		this->pMaker = p;
	}
	Maker* operator->()
	{//重载指针运算符
		return this->pMaker;
	}
	Maker &operator*()
	{//重载星花
		return *pMaker;
	}
	~SmartPoint()
	{
		if(this->pMaker != NULL)
		{
			cout<<"SmartPoint析构函数"<<endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};

void test1()
{
	Maker* p = new Maker;	//堆区
	SmartPoint sm(p);		//栈区
	(*sm).MakerPrint();
	sm->MakerPrint();		//重载后的sm->相当于是pMaker->,而不仅仅是返回值的pMaker
	//当test01()函数结束时，会调用SmartPoint的析构函数，
	//在SmartPoint的析构函数中delete了Maker的对象，会调用Maker的析构函数

}

int main1()
{
	test1();
	system("pause");
	return 0;
}