#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker1
{
public:
	Maker1()
	{
		name = "小花";
	}
	void MakerPrint()
	{
		cout<<name + "你好漂亮"<<endl;
	}
	void operator()()
	{
		cout<<"仿函数"<<endl;
	}
	void operator()(int a,int b)
	{
		cout<<"仿函数2"<<endl;
	}
public: 
	string name;
};

void test2()
{
	Maker1 fun;
	fun();			//这两个fun看起来是一个函数名，其实它是一个对象.
	fun(10,20);	
	fun.MakerPrint();
}


//其他的重载
class Maker2
{
public:
	Maker2(int a)
	{
		this->a=a;
	}
	operator bool()
	{//重载类型时没有返回值，也没有void
		if(a!=0)
			return true;
		else
			return false;
	}
	bool operator!()
	{
		if(a!=0)
			return false;
		else
			return true;
	}
private:
	int a;
};
void test3() 
{
	Maker2 m(1);
	if(m)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	if(!m)
	{
		cout<<"false"<<endl;
	}
	else
	{
		cout<<"true"<<endl;
	}
}
int main()
{
	test3();
	system("pause");
	return 0;
}