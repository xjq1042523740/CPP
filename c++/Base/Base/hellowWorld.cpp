#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"test2.h"
using namespace std;//��׼�����ռ�

//namespace A
//{
//	int a = 23;
//	int b = 10;
//	namespace AA
//	{
//		int c = 200;
//	}
//}
//
//namespace B
//{
//	int a = 0;
//	int b = 20;
//	int f = 10;
//}
//
//namespace A
//{
//	int d = 100;
//}
//
//namespace 
//{
//	char ch = 'a';
//}
//void test1()
//{//			 ������  ������
//	namespace Aname = A;
//	cout<<  Aname::a <<endl;
//}
//
//void test()
//{
//	cout<< A::d <<endl;
//	cout<< ch <<endl;
//}
//
//void test3()
//{
//	myMaker1::fun();
//}
//
//int main1()
//{
//	test3();
//	//cout�Ǳ�׼����������󣬴�ӡ�ַ�����
//	//endl��ˢ�»�������������
//	//cout<<"hellow word"<<endl;
//	//cout<< A::a <<endl;
//	//cout<< B::a <<endl;
//	//cout<< A::AA::c <<endl;
//	//cout<< A::d <<endl;
//
//	system("pause");
//	return 0;
//}


namespace A
{
	int a = 10;
	int b = 20;
	int c = 30;
}

void test4()
{//using����ָ���ĳ�������ռ��еı�ʶ��������ֱ��ʹ��
	using namespace A;
	cout<< a <<endl;
	cout<< b <<endl;
	cout<< c <<endl;
	int a = 1;//Ϊʲô�����ͻ
	cout<< a <<endl;//������ �������е�a��ȫ�ֱ����������a�ľֲ�����

}
int main()
{
	//using A::a;		//�൱���ڸô�����д��һ�� int a = 10;
	//cout<< a <<endl;
	test4();
	system("pause");
	return 0;
}