#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker2
{
public:
	Maker2(const char* name)
	{
		pName = new char[strlen(name)+1];
		strcpy(pName,name);
	}
	Maker2(const Maker2 &m)		//防止浅拷贝构造
	{
		pName = new char[strlen(m.pName)+1];
		strcpy(pName,m.pName);
	}
	~Maker2()
	{
		delete[] pName;
		pName = NULL;
	}
	//如果不返回Maker2则在进行运算"m1=m2=m3"的时候就会出错。
	//如果不返回引用则进行赋值操作“m2=m3”时返回的对象就不是原来的m2了，而是拷贝m2的一个新的对象，这就改变了原来的寓意。
	Maker2 &operator=(Maker2 &m)
	{//不能确定pName里的空间是否有m.pName里的空间大。所以要先释放再重新申请。
		if(this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}
		pName = new char[strlen(m.pName)+1];
		strcpy(this->pName,m.pName);
		return *this;
	}

public:
	char* pName;
};

void test5()
{
	Maker2 m1("悟空");
	Maker2 m2("小林");
	m1 = m2;
	cout<<m1.pName<<endl;
}

void test6()
{
	Maker2 m1("a");
	Maker2 m2("b");
	Maker2 m3("c");
	m1=m2=m3;
	cout<<&m1<<endl;
	cout<<&(m1=m2)<<endl;
}


//关系运算符重载
class Maker3
{
public:
	Maker3(int a,int b)
	{
		this->a=a;
		this->b=b;
	}
public:
	int a;
	int b;
};

bool operator==(const Maker3 &m1,const Maker3 &m2)
{
	if((m1.a==m2.a)&&(m1.b==m2.b))
	{
		return true;
	}
	else
		return false;
}
bool operator!=(const Maker3 &m1,const Maker3 &m2)
{
	if((m1.a==m2.a)&&(m1.b==m2.b))
	{
		return false;
	}
	else
		return true;
}
void test7()
{
	Maker3 m1(10,20);
	Maker3 m2(10,21);
	if(m1==m2)
	{
		cout<<"真"<<endl;
	}
	if(m1!=m2)
	{
		cout<<"假"<<endl;
	}
}

int main3()
{
	test7();
	system("pause");
	return 0;
}