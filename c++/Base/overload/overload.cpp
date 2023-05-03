#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void MyFun()
{
	cout<< "无参数" <<endl;
}
//参数个数不同
void MyFun(int a, string b)
{
	cout<< "int a, string b" <<endl;
}
//参数类型不同
void MyFun(int a, int b)
{
	cout<< "int a, int b" <<endl;
}
//参数（类型）顺序不同
void MyFun(string a, int b)
{
	cout<< "string a, int b" <<endl;
}

void test0()
{
	int a=1;
	int b=2;
	string c="字符串";
	MyFun();
	MyFun(a, b);
	MyFun(a, c);
	MyFun(c, a);

}

//默认参数 二义性问题
void Fun1(string a, int b = 1)
{
	cout<< "string a, int b = 1" <<endl;
}
void Fun1(string a)
{
	cout<< "string a" <<endl;
}
void test1()
{
	Fun1("二参数", 1);
}


//int main()
//{
//	//test1();
//	//test0();
//	system("pause");
//	return 0;
//}