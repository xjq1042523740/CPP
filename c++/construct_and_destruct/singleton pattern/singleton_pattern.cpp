#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Maker
{
public:
	static Maker* getpoint()
	{
		return pMaker;
	}
	void Print()
	{
		cout<<"��ӡ"<<endl;
	}
private:
	Maker()
	{
		cout<<"�޲ι���"<<endl;
	}
	Maker(const Maker &m)
	{
		cout<<"��������"<<endl;
	}
private:
	static Maker* pMaker;

};

Maker* Maker::pMaker = new Maker;	//��ʱ����������������ñ���������Ϊ���������ڣ����Կ��Ե��ù��캯����

void test()
{
	Maker* p = Maker::getpoint();
	Maker* p1 = Maker::getpoint();
	p->Print();
	cout<< "p1="<<p1<<"\tp="<<p<<endl;
}


//��ӡ��ʵ��
class Print
{
public:
	//4����ȡָ��ľ�̬����
	static Print* getpoint()
	{
		return pPrint;
	}
	void toPrint(string department)
	{
		cout<<department<<":��ӡ"<<endl;
		count++;
	}
	int PrintNum()
	{
		return count;
	}
private:
	//1.���޲ι���Ϳ�������˽�л�
	Print()
	{
		count = 0;
	}
	Print(Print &print)
	{
	}
private:
	//2.���徲̬��Աָ��
	static Print* pPrint;
	int count;
};
//3.������г�ʼ����new����
Print* Print::pPrint = new Print;

void test1()
{
	//���۲�p1
	Print* p1 = Print::getpoint();
	//������p2
	Print* p2 = Print::getpoint();
	//�ɹ���p3
	Print* p3 = Print::getpoint();

	p1->toPrint("���۲�");
	p2->toPrint("������");
	p3->toPrint("�ɹ���");
	cout<<"��ӡ����:"<<p1->PrintNum()<<endl;
}
int main()
{	
	test1();
	system("pause");
	return 0;
}