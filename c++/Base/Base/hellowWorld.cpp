#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"test2.h"
using namespace std;//标准命名空间

//namespace A
//{
//	int a = 23;
//	int b = 10;
//	namespace AA
//	{
//		int c = 200;
//	}
//}
//
//namespace B
//{
//	int a = 0;
//	int b = 20;
//	int f = 10;
//}
//
//namespace A
//{
//	int d = 100;
//}
//
//namespace 
//{
//	char ch = 'a';
//}
//void test1()
//{//			 新名字  旧名字
//	namespace Aname = A;
//	cout<<  Aname::a <<endl;
//}
//
//void test()
//{
//	cout<< A::d <<endl;
//	cout<< ch <<endl;
//}
//
//void test3()
//{
//	myMaker1::fun();
//}
//
//int main1()
//{
//	test3();
//	//cout是标准的输出流对象，打印字符串，
//	//endl是刷新缓冲区，并换行
//	//cout<<"hellow word"<<endl;
//	//cout<< A::a <<endl;
//	//cout<< B::a <<endl;
//	//cout<< A::AA::c <<endl;
//	//cout<< A::d <<endl;
//
//	system("pause");
//	return 0;
//}


namespace A
{
	int a = 10;
	int b = 20;
	int c = 30;
}

void test4()
{//using编译指令，让某个命名空间中的标识符都可以直接使用
	using namespace A;
	cout<< a <<endl;
	cout<< b <<endl;
	cout<< c <<endl;
	int a = 1;//为什么不会冲突
	cout<< a <<endl;//类似于 命名空中的a是全局变量，这里的a的局部变量

}
int main()
{
	//using A::a;		//相当于在该处重新写了一下 int a = 10;
	//cout<< a <<endl;
	test4();
	system("pause");
	return 0;
}