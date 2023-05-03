#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

void swap1(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void test4()
{
	int a = 10;
	int b = 20;
	swap1(a, b);
	cout<< "a,b=" << a << "," << b <<endl;
}

int &Func1()
{
	static int num = 10;
	cout<< num <<endl;
	return num;
}

void test5()
{
	Func1() = 200;
	Func1();

}

int main2()
{
	//test4();
	test5();
	system("pause");
	return 0;
}