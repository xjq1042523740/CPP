#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

inline int Add(int a, int b)
{
	return a+b;
}

void test6()
{
	int a= Add(1,8);
	cout<< a <<endl;
}

int main3()
{
	test6();
	system("pause");
	return 0;
}