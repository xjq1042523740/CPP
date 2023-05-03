#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//一、定义模板函数
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错,T代表泛型的数据类型，不是只能写T，
void Swap(T &a,T &b)
{
	T temp;
	temp = a;
	a=b;
	b=temp;
}
void test1()
{
	int a=10;
	int b=20;
	//使用函数模板
	//1、编译器自动推导数据类型
	Swap(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
	//2、显示的指定类型
	//用<int>表示告诉编译器传输的数据类型指定为int型，且实际传输的类型必须要与指定的类型一致。
	Swap<int>(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
	//double c=1.5,d=2.5;
	//Swap<int>(c,d);err
	Swap<>(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
}

template<class T>
T Add(T a,T b)
{
	return a+b;
}

void test2()
{	//二、隐式类型转换
	//如果使用参数列表指定数据类型，那么实参中可以隐式转换，
	//如果转换成功，就调用，转换不成功就报错
	int a=10;
	double b=15.5;
	cout<<"a+b="<<Add<int>(a,b)<<endl;
	char c='a';
	cout<<Add<double>(a,c)<<endl;
}

//三、普通函数与函数模板的区别
int Add2(int a,int b)
{
	return a+b;
}
void test3()
{
	int a=10;
	double b=12.5;
	cout<<Add2(a,b)<<endl;//普通函数可以进行隐式转换
	//cout<<Add(a,b)<<endl;//err 函数模版不能直接的进行隐式转换
	cout<<Add<int>(a,b);//如果要进行隐性转换，必须加上参数列表
}

//四、普通函数与函数模板的调用规则
//1、函数模版和普通函数可以重载
void myAdd(int a,int b)
{
	cout<<"普通函数"<<endl;
}
template<class T>
void myAdd(T a,T b)
{
	cout<<"函数模板1"<<endl;
}
//2、函数模板之间也可以重载
template<class T>
void myAdd(T a, T b,T c)
{
	cout<<"函数模板2"<<endl;
}
void test4()
{
	int a=10;
	int b=15;
	//3、如果普通函数和函数模版都可以实现的功能，普通函数优先调用
	myAdd(a,b);
	//4、可以使用<>空参数列表强制调用函数模版
	myAdd<>(a,b);
	//5、如果函数模版可以产生更好的匹配，那么优先使用函数模版
	char c1='c';
	char c2='d';
	myAdd(c1,c2);
}

//五、模版的局限性及解决方法（函数模板具体化）
//不建议具体化函数模版，因为没有通用性
class Maker
{
public:
	Maker(string name,int age)
	{
		this->age=age;
		this->name=name;
	}
public:
	string name;
	int age;
};
template<class T>
void myfunc(T &a,T &b)
{//比较大小函数模板
	if(a>=b)
	{
		cout<<"a>=b"<<endl;
	}
	else
	{
		cout<<"a<b"<<endl;
	}
}
template<>void myfunc<Maker>(Maker &a,Maker &b)
{//具体化函数模版，注意上面的函数模版要有，才能具体化
	if(a.age>=b.age)
	{
		cout<<"a>=b"<<endl;
	}
	else
	{
		cout<<"a<b"<<endl;
	}
}
void test5()
{
	Maker a("悟空",18);
	Maker b("贝吉塔",19);
	myfunc(a,b);
}

//六、类模板
template<class NameType,class AgeType>
class Maker2
{
public:
	Maker2(NameType name, AgeType age)
	{
		this->name=name;
		this->age=age;
	}
	void PrintMaker2()
	{
		cout<<name<<"\t"<<age<<endl;
	}
public:
	NameType name;
	AgeType age;
};
void test6()
{//1.类模版不会自动推导数据类型，要显示的告诉编译器是什么类型
	Maker2<string,int> m1("悟空",18);
	//2.注意传入的参数,传入参数类型要程序员自己把握
	Maker2<int,int> m2(20,19);
	m1.PrintMaker2();
	m2.PrintMaker2();
	//Maker2<> m3("aaa",12);err 必须通过参数列表告诉编译器是什么类型
}

//默认参数
template<class NameType,class AgeType=int>
class Maker3
{
public:
	Maker3(NameType name, AgeType age)
	{
		this->name=name;
		this->age=age;
	}
	void PrintMaker3()
	{
		cout<<name<<"\t"<<age<<endl;
	}
public:
	NameType name;
	AgeType age;
};
void test7()
{
	Maker3<string> m1("贝吉塔",19);
	m1.PrintMaker3();
}

//七、复数的模板类
template<class T>
class Maker4 
{
public:
	Maker4()
	{
		a=0;
		b=0;
	}
	Maker4(T a,T b)
	{
		this->a=a;
		this->b=b;
	}
	void Print()
	{
		cout<<"("<<a<<","<<b<<")"<<endl;
	}
	Maker4 Maker_add(Maker4 &p)
	{
		Maker4 temp;
		temp.a=this->a+p.a;
		temp.b=this->b+p.b;
		return temp;
	}
	Maker4 operator+(Maker4 &p)
	{//操作符重载实现
		Maker4 temp;
		temp.a=this->a+p.a;
		temp.b=this->b+p.b;
		return temp;
	}
private:
	T a;
	T b;
};
void test8()
{
	Maker4<int> m1(5,6);
	Maker4<int> m2(10,-6);
	Maker4<int> m3=m1.Maker_add(m2);
	m3.Print();
	m3 = m1+m3;
	m3.Print();
}

//八、类模版做函数参数
//1、指定传入的数据类型
void func1(Maker2<string,int> &m1)
{
	m1.PrintMaker2();
}
//2、参数模版化(函数模板化)（常用）
template<class NameType,class AgeType>
void func2(Maker2<NameType,AgeType> &m1)
{
	m1.PrintMaker2();
}
//3、整个类模板化
template<class T>
void func3(T &m1)
{
	m1.PrintMaker2();
}
void test9()
{
	Maker2<string,int> m("小林",20);
	func1(m);
	func2(m);
	func3(m);
}

//九、类模版的继承
//1、普通类继承类模版
template<class T>
class Father
{
public:
	Father()
	{
		a=20;
	}
public:
	T a;
};
//普通类
class Son:public Father<int>//要告诉编译器父类的泛型数据类型具体是什么类型
{
public:
};
//类模板继承类模板
template<class T1,class T2>
class Son2:public Father<T2>//要告诉编译器父类的泛型数据类型具体是什么类型
{
public:
	Son2()
	{
		b=20.1;
	}
public:
	T1 b;
};
void test10()
{
	Son s1;
	Son2<double,int> s2;
	cout<<s1.a<<"\n"<<s2.a<<"\t"<<s2.b<<endl;
}

//十、类模版的成员函数类内类外实现
//类内实现
template<class NameType,class AgeType>
class Maker5
{
public:
	Maker5(NameType name,AgeType age);
	//{
	//	this->name=name;
	//	this->age=age;
	//}
	void MakerPrint5();
	//{
	//	cout<<"name:"<<name<<endl;
	//	cout<<"age:"<<age<<endl;
	//}
public:
	NameType name;
	AgeType age;
};
//类外实现,要写成函数模版,并且写上参数列表
template<class NameType,class AgeType>
Maker5<NameType,AgeType>::Maker5(NameType name,AgeType age)
{
	this->name=name;
	this->age=age;
}
template<class NameType,class AgeType>
void Maker5<NameType,AgeType>::MakerPrint5()
{
	cout<<"name:"<<name<<endl;
	cout<<"age:"<<age<<endl;
}
void test11()
{
	Maker5<string,int> m5("卡卡",18);
	m5.MakerPrint5();
}

//十一、类模版碰到友元
//声类模版(类外)
template<class NameType,class AgeType>
class Maker6;
//声明函数模版，告诉编译器下面有printMaker2的实现
template<class NameType,class AgeType>
void PrintMaker7(Maker6<NameType,AgeType> &m7);
//友元类内实现
template<class NameType,class AgeType>
class Maker6
{
	friend void PrintMaker7<>(Maker6<NameType,AgeType> &m7);//在函数名和()之间加上<>。（类外）
	//编译器不知道printMaker7下面有没有实现，需要知道函数的结构
	friend void PrintMaker6(Maker6<NameType,AgeType> &m6)
	{
		cout<<"类内实现"<<endl;
		cout<<"Name:"<<m6.name<<endl;
		cout<<"Age:"<<m6.age<<endl;
	}
public:
	Maker6(NameType name,AgeType age)
	{
		this->name=name;
		this->age=age;
	}
private:
	NameType name;
	AgeType age;
};
//友元类外实现，友元在类外实现要写成函数模版
template<class NameType,class AgeType>
void PrintMaker7(Maker6<NameType,AgeType> &m7)
{
	cout<<"类外实现"<<endl;
	cout<<"Name:"<<m7.name<<endl;
	cout<<"Age:"<<m7.age<<endl;
}
void test12()
{
	Maker6<string,int> m6("悟空",18);
	PrintMaker6(m6);
	PrintMaker7(m6);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test12();
	system("pause");
	return 0;
}