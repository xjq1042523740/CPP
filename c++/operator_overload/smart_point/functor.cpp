#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker1
{
public:
	Maker1()
	{
		name = "С��";
	}
	void MakerPrint()
	{
		cout<<name + "���Ư��"<<endl;
	}
	void operator()()
	{
		cout<<"�º���"<<endl;
	}
	void operator()(int a,int b)
	{
		cout<<"�º���2"<<endl;
	}
public: 
	string name;
};

void test2()
{
	Maker1 fun;
	fun();			//������fun��������һ������������ʵ����һ������.
	fun(10,20);	
	fun.MakerPrint();
}


//����������
class Maker2
{
public:
	Maker2(int a)
	{
		this->a=a;
	}
	operator bool()
	{//��������ʱû�з���ֵ��Ҳû��void
		if(a!=0)
			return true;
		else
			return false;
	}
	bool operator!()
	{
		if(a!=0)
			return false;
		else
			return true;
	}
private:
	int a;
};
void test3() 
{
	Maker2 m(1);
	if(m)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	if(!m)
	{
		cout<<"false"<<endl;
	}
	else
	{
		cout<<"true"<<endl;
	}
}
int main()
{
	test3();
	system("pause");
	return 0;
}