#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

inline int Add2(int a=3, int b=5)
{
	return a+b;
}

void test7()
{
	int a= Add2(1,8);
	cout<< a <<endl;
	int b= Add2(1);
	cout<< b <<endl;
	int c= Add2();
	cout<< c <<endl;
}

int main4()
{
	test7();
	system("pause");
	return 0;
}