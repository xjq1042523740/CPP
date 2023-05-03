#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father1
{
public:
	Father1()
	{
		a = 2;
		b = 3;
	}
	void fun()
	{
		cout<< "Father1 fun()" <<endl;
	}
	void fun(int a)
	{
		cout<< "Father1 fun(int a)" <<endl;
	}
	void fun(int a, int b)
	{
		cout<< "Father1 fun(int a, int b)" <<endl;
	}
	//定义一个静态函数
	static void func()
	{
		cout<< "Father1 func()" <<endl;
	}
	static void func(int a)
	{
		cout<< "Father1 func(int a)" <<endl;
	}
public:
	int a;
	int b;
	static int c;
	static int d;
};
int Father1::c = 100;
int Father1::d = 200;


class Son1:public Father1
{
public:
	Son1()
	{
		a = 20;
	}
	void fun()
	{
		cout<< "Son1 fun()" <<endl;
	}
	static int func()
	{
		cout<< "Son1 func()" <<endl;
		return 0;
	}
public:
	int a;
	static int d;
};
int Son1::d = 500;


void test4()
{
	Son1 s1;	//子类成员变量与父类成员变量同名时调用子类的成员，父类的成员变量会被隐藏（存在）。
	cout<< s1.a <<endl;
	//调用父类的成员方法：在成员名前加上 父类名和作用域
	cout<< s1.Father1::a <<endl;
	s1.fun();	//子类成员函数与父类成员函数同名时调用子类的成员函数
	//s1.fun(10,20);	//子类成员函数与父类成员函数同名时,父类的所有重载成员函数都会被隐藏（存在）。
	//调用父类的成员方法：在成员名前加上 父类名和作用域
	s1.Father1::fun();
	s1.Father1::fun(10);
	s1.Father1::fun(10,20);

}

void test5()
{
	Son1 s1;
	cout<< s1.c<<endl;	//静态成员变量也可以被继承。
	cout<< s1.d <<endl;	//当子类的静态成员变量与父类的静态成员变量重名时，父类的会被隐藏。
	s1.func();			//静态成员函数也可以被继承。
	//s1.func(10);		//子类的静态成员函数与父类的静态成员函数同名时，父类的所有的重载函数都会被隐藏。
	s1.Father1::func();
	cout<<s1.Father1::d<<endl;
}
int main3()
{
	test5();
	system("pause");
	return 0;
}