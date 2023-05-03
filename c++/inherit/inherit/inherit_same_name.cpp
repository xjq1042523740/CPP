#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father1
{
public:
	Father1()
	{
		a = 2;
		b = 3;
	}
	void fun()
	{
		cout<< "Father1 fun()" <<endl;
	}
	void fun(int a)
	{
		cout<< "Father1 fun(int a)" <<endl;
	}
	void fun(int a, int b)
	{
		cout<< "Father1 fun(int a, int b)" <<endl;
	}
	//����һ����̬����
	static void func()
	{
		cout<< "Father1 func()" <<endl;
	}
	static void func(int a)
	{
		cout<< "Father1 func(int a)" <<endl;
	}
public:
	int a;
	int b;
	static int c;
	static int d;
};
int Father1::c = 100;
int Father1::d = 200;


class Son1:public Father1
{
public:
	Son1()
	{
		a = 20;
	}
	void fun()
	{
		cout<< "Son1 fun()" <<endl;
	}
	static int func()
	{
		cout<< "Son1 func()" <<endl;
		return 0;
	}
public:
	int a;
	static int d;
};
int Son1::d = 500;


void test4()
{
	Son1 s1;	//�����Ա�����븸���Ա����ͬ��ʱ��������ĳ�Ա������ĳ�Ա�����ᱻ���أ����ڣ���
	cout<< s1.a <<endl;
	//���ø���ĳ�Ա�������ڳ�Ա��ǰ���� ��������������
	cout<< s1.Father1::a <<endl;
	s1.fun();	//�����Ա�����븸���Ա����ͬ��ʱ��������ĳ�Ա����
	//s1.fun(10,20);	//�����Ա�����븸���Ա����ͬ��ʱ,������������س�Ա�������ᱻ���أ����ڣ���
	//���ø���ĳ�Ա�������ڳ�Ա��ǰ���� ��������������
	s1.Father1::fun();
	s1.Father1::fun(10);
	s1.Father1::fun(10,20);

}

void test5()
{
	Son1 s1;
	cout<< s1.c<<endl;	//��̬��Ա����Ҳ���Ա��̳С�
	cout<< s1.d <<endl;	//������ľ�̬��Ա�����븸��ľ�̬��Ա��������ʱ������Ļᱻ���ء�
	s1.func();			//��̬��Ա����Ҳ���Ա��̳С�
	//s1.func(10);		//����ľ�̬��Ա�����븸��ľ�̬��Ա����ͬ��ʱ����������е����غ������ᱻ���ء�
	s1.Father1::func();
	cout<<s1.Father1::d<<endl;
}
int main3()
{
	test5();
	system("pause");
	return 0;
}