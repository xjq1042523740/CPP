#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
#include"cpp_call_c.h"

int main()
{
	fun();//C++找func函数时，是去找__Z4funv这个去了别名的函数
	system("pause");
	return 0;
}