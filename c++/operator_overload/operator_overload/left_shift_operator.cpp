#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
	friend istream &operator>>(istream &in, Maker &m);
public:
	Maker()
	{
		cout<<"无参构造"<<endl;
	}
	Maker(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
private:
	int age;
	string name;
};

//	(cout)形参和实参是一个对象(ostream类型)，∵ostream把拷贝构造私有化了。
ostream &operator<<(ostream &out, Maker &m)
{
	out<<m.age<<" "<<m.name<<endl;
	//	endl是一个函数
	//	<<运算符内部重载了基础数据类型
	return out;
}

istream &operator>>(istream &in, Maker &m)
{
	in>>m.age;
	in>>m.name;
	return in;	
}

void test3()
{
	Maker m1(20,"小花");
	cout<<m1<<endl;
	
}
void test4()
{
	Maker m1;
	Maker m2(18,"悟空");
	cout<<"输入：";
	cin>>m1>>m2;
	cout<<"输入结束。\n"<<m1<<m2<<endl;
}
int main2()
{
	test4();
	system("pause");
	return 0;
}