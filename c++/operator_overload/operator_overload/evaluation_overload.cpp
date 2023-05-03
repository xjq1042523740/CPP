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
	Maker2(const Maker2 &m)		//��ֹǳ��������
	{
		pName = new char[strlen(m.pName)+1];
		strcpy(pName,m.pName);
	}
	~Maker2()
	{
		delete[] pName;
		pName = NULL;
	}
	//���������Maker2���ڽ�������"m1=m2=m3"��ʱ��ͻ����
	//�����������������и�ֵ������m2=m3��ʱ���صĶ���Ͳ���ԭ����m2�ˣ����ǿ���m2��һ���µĶ�����͸ı���ԭ����Ԣ�⡣
	Maker2 &operator=(Maker2 &m)
	{//����ȷ��pName��Ŀռ��Ƿ���m.pName��Ŀռ������Ҫ���ͷ����������롣
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
	Maker2 m1("���");
	Maker2 m2("С��");
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


//��ϵ���������
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
		cout<<"��"<<endl;
	}
	if(m1!=m2)
	{
		cout<<"��"<<endl;
	}
}

int main3()
{
	test7();
	system("pause");
	return 0;
}