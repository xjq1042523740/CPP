#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


void test0()
{
	int a = 10;
	//������aȡһ������b
	int &b = a;
	int d = 50;
	cout<<"a= "<< a <<endl;
	cout<<"b= "<< b <<endl;

	cout<<"a�ĵ�ַ��"<<&a<<endl;
	cout<<"b�ĵ�ַ��"<<&b<<endl;
	//һ������������n������
	int &c = b;
	cout<<"c= "<<c<<endl;
	cout<<"c�ĵ�ַ��"<<&c<<endl;	//a,b,c�ĵ�ַ������ͬ��

	c = 22;
	cout<<"���ĺ�"<<endl;
	cout<<"a= "<< a <<endl;
	cout<<"b= "<< b <<endl;
	cout<<"c= "<<c<<endl;
	//int &e;	err->�ڶ������ñ���ʱ�����ʼ����

	c = d;//����һ����ʼ���Ͳ��ܸı䣬��������Ǹ�ֵ���������Ǹı����á�
	cout<<"c= "<<c<<endl;
}

void test1()
{//��������ã�
	//��һ������������
	typedef int ArrRef[10];	//ArrRef������������� int [10]����
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	ArrRef &arr1 = arr;

	//������ֱ�����ã�
	int (&arr2)[10] = arr;

	//�����������������������
	typedef int (&ArrRef2)[10];
	ArrRef2 arr3 = arr;

	int i = 0;
	for(i=0; i<10; i++)
	{
		cout<< "arr[i]=" << arr[i] <<"\tarr1[i]=" << arr1[i] <<"\tarr2[i]=" << arr2[i] <<"\tarr3[i]=" << arr3[i] <<endl;
	}
	cout<< "arr=" << arr << "\tarr1=" << arr1 <<"\tarr2=" << arr2 <<"\tarr3=" << arr3 <<endl;
}

void test2()
{//ָ�������
	const int a = 30;
	int *p = (int*)&a;
	int* &ref = p;
	//�ı�const���εľֲ�������ֵ
	*ref = 20;
	cout<< a <<endl;	//���������۵�
	cout<< *ref <<endl;
	cout<< *p <<endl;
	//�ı�ָ���ָ��
	cout<< "ԭָ�룺p = " << p << "  ref = " << ref <<endl;
	ref = ref+1;
	cout<< "�ı��p = " << p << "  ref = " << ref <<endl;
}

void test3()
{//����������
	//int &a = 10;//err
	const int &a = 10;//ok
	//ԭ����:int tmp=10;const int &ref=tmp;
}
int main1()
{
	//test0();
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}