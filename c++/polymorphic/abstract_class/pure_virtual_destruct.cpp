#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Father3
{
public:
	Father3()
	{
		cout<<"Father�Ĺ��캯��"<<endl;
	}
	virtual ~Father3() = 0;		//������������
};
Father3::~Father3()
{//������������Ҫ������ʵ��
	cout<<"Father�Ĵ�����������"<<endl;
}

class Son3:public Father3
{
public:
	Son3()
	{
		cout<<"Son�Ĺ��캯��"<<endl;
		p = new int[10];
	}
	~Son3()
	{//������಻ʹ����������������ô�Ͳ����������������������������ڴ�й¶��
		cout<<"Son����������"<<endl;
		delete[] p;
	}
	int* p;
};
void test3()
{
	Father3* fp = new Son3;
	delete fp;
}
int main()
{
	test3();
	system("pause");
	return 0;
}