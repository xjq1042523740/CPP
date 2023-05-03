#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Student
{
public:
	Student(const char* name,int Age)
	{
		cout<<"构造函数"<<endl;
		pName = (char*)malloc(strlen(name)+1);
		strcpy(pName, name);
		age = Age;
	}
	//Student(const Student &st)//浅拷贝
	//{
	//	cout<<"浅拷贝"<<endl;
	//	pName = st.pName;
	//	age = st.age;
	//}
	Student(const Student &st)//深拷贝
	{
		cout<<"深拷贝"<<endl;
		pName = (char*)malloc(strlen(st.pName)+1);
		strcpy(pName, st.pName);
		age = st.age;
	}

	~Student()
	{
		cout<<"析构函数"<<endl;
		if(pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
public:
	char* pName;
	int age;
};

void test1()
{
	Student st1("wang", 20);
	Student st2(st1);
	cout<< "st1.pName:" <<st1.pName<<" st1.age:"<<st1.age<<endl;
	cout<< "st2.pName:" <<st2.pName<<" st2.age:"<<st2.age<<endl;
}

//explicit
class Maker
{
public:
	explicit Maker(int b)
	{
		cout<<"有参构造"<<endl;
		a = b;
		cout<<"a= "<<a<<endl;
	}
	Maker()
	{
		cout<<"无参构造"<<endl;
	}
private:
	int a;
};

void test2()
{
	//Maker m = 20;//不加explicit优化为->Maker m = Maker(20),加explicit不优化->报错

}
int main1()
{
	test2();
	system("pause");
	return 0;
}