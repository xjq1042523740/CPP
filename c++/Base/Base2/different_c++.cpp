#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

struct Maker
{
	Maker()
	{
		a = 100;
	}
	int a;
};

const int a = 10;
void test1()
{
	//int* p = (int*)malloc(64);
	//int *p = (int*)&a;
	//*p = 20;
	//cout<< a <<endl;
	//cout<< *p <<endl;
	//�����˳����۵�
	//cout << "a=" << a << endl;//�ڱ���׶Σ���������cout<<"a="<<10<<endl;
	//int* p1 = (int*)&a;
	//cout<< a << endl;
	//cout<< *p1 << endl;
	//volatile��ֹ�Ż�
	//volatile const int b = 20;//ջ��
	//const int b = 20;//ջ��
	//int* p = (int*)&b;
	//*p = 30;
	//cout<< b <<endl;  //�ڱ���������Ż�ֱ�Ӿͽ�b��Ϊ��20
	//cout<< *p <<endl;
	//cout << "b�ĵ�ַ=" << (int)&b << endl;
	//cout << "pָ��ĵ�ַ" << (int)p << endl;
	//extern const int d;
	//cout<< d <<endl;
	//int a = 10;
	//const int b = a;
	//int* p = (int*)&b;
	//*p = 30;
	//cout<< b <<endl;

	const Maker ma;
	cout<< ma.a <<endl;
	Maker* p = (Maker*)&ma;
	p->a = 30;
	cout<< ma.a<<endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}