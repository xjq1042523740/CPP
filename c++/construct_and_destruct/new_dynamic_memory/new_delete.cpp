#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout<<"�޲ι���"<<endl;
	}
	~Maker()
	{
		cout<<"����"<<endl;
	}
private:
	int a;
	int b;
};

void test3()
{
	Maker* pMaker = new Maker;
	delete pMaker;
	pMaker = NULL;
}

void test4()
{
	int *p = new int[10];
	int i = 0;
	for(i=0;i<10;i++)
	{
		*(p+i)=i+1;
	}
	for(i=0;i<10;i++)
	{
		cout<< *(p+i)<<" ";
	}
	cout<<endl;
	delete[] p;
	p=NULL;
}

void test5()
{	//����2��Maker��Ŀռ�->�������ι��캯��
	Maker* pMaker = new Maker[2];
	//�ͷ�2��Maker��Ŀռ�->����������������
	delete[] pMaker;
}

void test6()
{
	void* p = new Maker;
	delete p;
	p=NULL;
}

int main2()
{
	test6();
	system("pause");
	return 0;
}