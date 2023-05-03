#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker4
{
public:
	Maker4(int a)
	{
		this->a = a;
	}
	//规定前置++不用占位参数
	Maker4 &operator++()
	{//返回Maker4类型，由于++(++a)是可以存在的。
		//前置++，先++再返回。
		++this->a;
		return *this;
	}

	//规定后置++使用int作为占位参数
	Maker4 operator++(int)
	{//这里不返回引用是因为temp是局部变量。
		//后置++，先返回再++
		Maker4 temp(*this);		//拷贝构造
		this->a++;				
		return temp;
	}
public:
	int a;
};
ostream &operator<<(ostream &out,const Maker4 &m1)
{
	out<<m1.a<<endl;
	return out;
}

void test8()
{
	Maker4 m1(1);
	cout<<m1++<<endl;	//1	 这里返回的拷贝的tmp对象
	cout<<++m1<<endl;	//3	 这里返回的是++this->a的对象
}

int main()
{
	test8();
	system("pause");
	return 0;
}