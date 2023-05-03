#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


void test0()
{
	int a = 10;
	//给变量a取一个别名b
	int &b = a;
	int d = 50;
	cout<<"a= "<< a <<endl;
	cout<<"b= "<< b <<endl;

	cout<<"a的地址："<<&a<<endl;
	cout<<"b的地址："<<&b<<endl;
	//一个变量可以有n个别名
	int &c = b;
	cout<<"c= "<<c<<endl;
	cout<<"c的地址："<<&c<<endl;	//a,b,c的地址都是相同的

	c = 22;
	cout<<"更改后："<<endl;
	cout<<"a= "<< a <<endl;
	cout<<"b= "<< b <<endl;
	cout<<"c= "<<c<<endl;
	//int &e;	err->在定义引用变量时必须初始化；

	c = d;//引用一经初始化就不能改变，这个操作是赋值操作而不是改变引用。
	cout<<"c= "<<c<<endl;
}

void test1()
{//数组的引用：
	//法一：数组重命名
	typedef int ArrRef[10];	//ArrRef就是重命名后的 int [10]类型
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ArrRef &arr1 = arr;

	//法二：直接引用；
	int (&arr2)[10] = arr;

	//法三：建立数组的引用类型
	typedef int (&ArrRef2)[10];
	ArrRef2 arr3 = arr;

	int i = 0;
	for(i=0; i<10; i++)
	{
		cout<< "arr[i]=" << arr[i] <<"\tarr1[i]=" << arr1[i] <<"\tarr2[i]=" << arr2[i] <<"\tarr3[i]=" << arr3[i] <<endl;
	}
	cout<< "arr=" << arr << "\tarr1=" << arr1 <<"\tarr2=" << arr2 <<"\tarr3=" << arr3 <<endl;
}

void test2()
{//指针的引用
	const int a = 30;
	int *p = (int*)&a;
	int* &ref = p;
	//改变const修饰的局部变量的值
	*ref = 20;
	cout<< a <<endl;	//发生常量折叠
	cout<< *ref <<endl;
	cout<< *p <<endl;
	//改变指针的指向
	cout<< "原指针：p = " << p << "  ref = " << ref <<endl;
	ref = ref+1;
	cout<< "改变后：p = " << p << "  ref = " << ref <<endl;
}

void test3()
{//常量的引用
	//int &a = 10;//err
	const int &a = 10;//ok
	//原理是:int tmp=10;const int &ref=tmp;
}
int main1()
{
	//test0();
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}