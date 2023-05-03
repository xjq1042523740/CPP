#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Maker
{
public:
	static Maker* getpoint()
	{
		return pMaker;
	}
	void Print()
	{
		cout<<"打印"<<endl;
	}
private:
	Maker()
	{
		cout<<"无参构造"<<endl;
	}
	Maker(const Maker &m)
	{
		cout<<"拷贝构造"<<endl;
	}
private:
	static Maker* pMaker;

};

Maker* Maker::pMaker = new Maker;	//此时由于有作用域的作用编译器会认为这是在类内，所以可以调用构造函数。

void test()
{
	Maker* p = Maker::getpoint();
	Maker* p1 = Maker::getpoint();
	p->Print();
	cout<< "p1="<<p1<<"\tp="<<p<<endl;
}


//打印机实例
class Print
{
public:
	//4、获取指针的静态函数
	static Print* getpoint()
	{
		return pPrint;
	}
	void toPrint(string department)
	{
		cout<<department<<":打印"<<endl;
		count++;
	}
	int PrintNum()
	{
		return count;
	}
private:
	//1.把无参构造和拷贝构造私有化
	Print()
	{
		count = 0;
	}
	Print(Print &print)
	{
	}
private:
	//2.定义静态成员指针
	static Print* pPrint;
	int count;
};
//3.类外进行初始化，new对象
Print* Print::pPrint = new Print;

void test1()
{
	//销售部p1
	Print* p1 = Print::getpoint();
	//技术部p2
	Print* p2 = Print::getpoint();
	//采购部p3
	Print* p3 = Print::getpoint();

	p1->toPrint("销售部");
	p2->toPrint("技术部");
	p3->toPrint("采购部");
	cout<<"打印次数:"<<p1->PrintNum()<<endl;
}
int main()
{	
	test1();
	system("pause");
	return 0;
}