#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



class Maker
{
public:
	Maker()
	{
		cout<<"�޲ι���"<<endl;
	}
	Maker(int a, int b)
	{
		cout<<"�вι���"<<endl;
		this->a = a;
		this->b = b;
	}
	void MPrint()
	{
		cout<<"a="<<a<<"\tb="<<b<<endl;
	}
	int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	////2����ĳ�Ա������ʽ
	Maker operator+(Maker &m)	//Ĭ�ϵ�һ������Ϊthisָ��+�ұߵı�����ֻ��Ҫ���ڶ��������Ϳ��ԡ�
	{
		Maker temp(this->a + m.a, this->b + m.b);
		return temp;
	}
private:
	int a;
	int b;
};
//1��ȫ����ʽ
//Maker operator+(Maker &m1, Maker &m2)
//{
//	Maker temp(m1.geta()+m2.geta(), m1.getb()+m2.getb());
//	return temp;
//}

//int operator+(int a,int b)	//err ���ܸı������������������壬������Ҫһ�������͵��β�
//{
//	return a-b;
//}
void test1()
{
	Maker m1(1,10);
	Maker m2(2,20);
	Maker m3 = m1+m2;
	m3.MPrint();
	Maker m4 = m1+m2+m3;
	m4.MPrint();
}


class Maker1
{
public:
	Maker1(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};
class Student
{
public:
	Student(int id)
	{
		this->mid = id;
	}
public:
	int mid;
};

Student operator+(Maker1 &m, Student &s)
{
	Student temp(m.id+s.mid);
	return temp;
}
Student operator+(Student &s, Maker1 &m)
{
	Student temp(m.id+s.mid);
	return temp;
}

void test2()
{
	Maker1 m1(1,20);	//�вι��죺m1.id=1,m1.age=20
	Student s1(2);		//�вι��죺s1.mid = 2
	Student s2 = s1+m1;
	cout<<"mid:"<<s2.mid<<endl;
}
int main1()
{
	test2();
	system("pause");
	return 0;
}