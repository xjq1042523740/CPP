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
	Maker(int a, int b)
	{
		cout<<"有参构造"<<endl;
		this->a = a;
		this->b = b;
	}
	void MPrint()
	{
		cout<<"a="<<a<<"\tb="<<b<<endl;
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	////2、类的成员函数形式
	Maker operator+(Maker &m)	//默认第一个参数为this指向+右边的变量。只需要传第二个参数就可以。
	{
		Maker temp(this->a + m.a, this->b + m.b);
		return temp;
	}
private:
	int a;
	int b;
};
//1、全局形式
//Maker operator+(Maker &m1, Maker &m2)
//{
//	Maker temp(m1.geta()+m2.geta(), m1.getb()+m2.getb());
//	return temp;
//}

//int operator+(int a,int b)	//err 不能改变基础类型运算符的意义，至少需要一个类类型的形参
//{
//	return a-b;
//}
void test1()
{
	Maker m1(1,10);
	Maker m2(2,20);
	Maker m3 = m1+m2;
	m3.MPrint();
	Maker m4 = m1+m2+m3;
	m4.MPrint();
}


class Maker1
{
public:
	Maker1(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};
class Student
{
public:
	Student(int id)
	{
		this->mid = id;
	}
public:
	int mid;
};

Student operator+(Maker1 &m, Student &s)
{
	Student temp(m.id+s.mid);
	return temp;
}
Student operator+(Student &s, Maker1 &m)
{
	Student temp(m.id+s.mid);
	return temp;
}

void test2()
{
	Maker1 m1(1,20);	//有参构造：m1.id=1,m1.age=20
	Student s1(2);		//有参构造：s1.mid = 2
	Student s2 = s1+m1;
	cout<<"mid:"<<s2.mid<<endl;
}
int main1()
{
	test2();
	system("pause");
	return 0;
}