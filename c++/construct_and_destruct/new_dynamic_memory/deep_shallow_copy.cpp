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
		cout<<"���캯��"<<endl;
		pName = (char*)malloc(strlen(name)+1);
		strcpy(pName, name);
		age = Age;
	}
	//Student(const Student &st)//ǳ����
	//{
	//	cout<<"ǳ����"<<endl;
	//	pName = st.pName;
	//	age = st.age;
	//}
	Student(const Student &st)//���
	{
		cout<<"���"<<endl;
		pName = (char*)malloc(strlen(st.pName)+1);
		strcpy(pName, st.pName);
		age = st.age;
	}

	~Student()
	{
		cout<<"��������"<<endl;
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
		cout<<"�вι���"<<endl;
		a = b;
		cout<<"a= "<<a<<endl;
	}
	Maker()
	{
		cout<<"�޲ι���"<<endl;
	}
private:
	int a;
};

void test2()
{
	//Maker m = 20;//����explicit�Ż�Ϊ->Maker m = Maker(20),��explicit���Ż�->����

}
int main1()
{
	test2();
	system("pause");
	return 0;
}