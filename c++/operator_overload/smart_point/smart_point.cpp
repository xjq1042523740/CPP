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
	void MakerPrint()
	{
		cout<<"hellow Maker"<<endl;
	}
	~Maker()
	{
		cout<<"��������"<<endl;
	}
private:

};
class SmartPoint
{
public:
	SmartPoint(Maker* p)
	{
		this->pMaker = p;
	}
	Maker* operator->()
	{//����ָ�������
		return this->pMaker;
	}
	Maker &operator*()
	{//�����ǻ�
		return *pMaker;
	}
	~SmartPoint()
	{
		if(this->pMaker != NULL)
		{
			cout<<"SmartPoint��������"<<endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};

void test1()
{
	Maker* p = new Maker;	//����
	SmartPoint sm(p);		//ջ��
	(*sm).MakerPrint();
	sm->MakerPrint();		//���غ��sm->�൱����pMaker->,���������Ƿ���ֵ��pMaker
	//��test01()��������ʱ�������SmartPoint������������
	//��SmartPoint������������delete��Maker�Ķ��󣬻����Maker����������

}

int main1()
{
	test1();
	system("pause");
	return 0;
}