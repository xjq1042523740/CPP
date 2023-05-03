#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//沏茶、咖啡
class Drink
{
public:
	//煮水
	virtual void Boil() = 0;	//接口声明
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourIncup() = 0;
	//加点佐料
	virtual void addSonm() = 0;
	//模板方法，把调用函数的顺序确定下来.
	void func()
	{
		Boil();
		Brew();
		PourIncup();
		addSonm();
	}
};
class Coffee:public Drink
{
public:
	//煮水
	virtual void Boil()		//接口实现
	{
		cout<<"煮水"<<endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout<<"冲泡咖啡"<<endl;
	}
	//倒入杯中
	virtual void PourIncup()
	{
		cout<<"倒入杯中"<<endl;
	}
	//加点佐料
	virtual void addSonm()
	{
		cout<<"加点牛奶"<<endl;
	}
};
class Tea:public Drink
{
public:
	//煮水
	virtual void Boil()
	{
		cout<<"煮水"<<endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout<<"冲泡茶"<<endl;
	}
	//倒入杯中
	virtual void PourIncup()
	{
		cout<<"倒入杯中"<<endl;
	}
	//加点佐料
	virtual void addSonm()
	{
		cout<<"加点糖"<<endl;
	}
};


void test1()
{
	Coffee cf;
	Tea t;
	cf.func();
	t.func();
}
int main()
{
	test1();
	system("pause");
	return 0;
}