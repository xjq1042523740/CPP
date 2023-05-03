#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

struct Maker
{
	Maker()
	{
		a = 100;
	}
	int a;
};

const int a = 10;
void test1()
{
	//int* p = (int*)malloc(64);
	//int *p = (int*)&a;
	//*p = 20;
	//cout<< a <<endl;
	//cout<< *p <<endl;
	//发生了常量折叠
	//cout << "a=" << a << endl;//在编译阶段，编译器：cout<<"a="<<10<<endl;
	//int* p1 = (int*)&a;
	//cout<< a << endl;
	//cout<< *p1 << endl;
	//volatile禁止优化
	//volatile const int b = 20;//栈区
	//const int b = 20;//栈区
	//int* p = (int*)&b;
	//*p = 30;
	//cout<< b <<endl;  //在编译过程中优化直接就将b变为了20
	//cout<< *p <<endl;
	//cout << "b的地址=" << (int)&b << endl;
	//cout << "p指向的地址" << (int)p << endl;
	//extern const int d;
	//cout<< d <<endl;
	//int a = 10;
	//const int b = a;
	//int* p = (int*)&b;
	//*p = 30;
	//cout<< b <<endl;

	const Maker ma;
	cout<< ma.a <<endl;
	Maker* p = (Maker*)&ma;
	p->a = 30;
	cout<< ma.a<<endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}