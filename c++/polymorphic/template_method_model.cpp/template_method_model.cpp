#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//��衢����
class Drink
{
public:
	//��ˮ
	virtual void Boil() = 0;	//�ӿ�����
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourIncup() = 0;
	//�ӵ�����
	virtual void addSonm() = 0;
	//ģ�巽�����ѵ��ú�����˳��ȷ������.
	void func()
	{
		Boil();
		Brew();
		PourIncup();
		addSonm();
	}
};
class Coffee:public Drink
{
public:
	//��ˮ
	virtual void Boil()		//�ӿ�ʵ��
	{
		cout<<"��ˮ"<<endl;
	}
	//����
	virtual void Brew()
	{
		cout<<"���ݿ���"<<endl;
	}
	//���뱭��
	virtual void PourIncup()
	{
		cout<<"���뱭��"<<endl;
	}
	//�ӵ�����
	virtual void addSonm()
	{
		cout<<"�ӵ�ţ��"<<endl;
	}
};
class Tea:public Drink
{
public:
	//��ˮ
	virtual void Boil()
	{
		cout<<"��ˮ"<<endl;
	}
	//����
	virtual void Brew()
	{
		cout<<"���ݲ�"<<endl;
	}
	//���뱭��
	virtual void PourIncup()
	{
		cout<<"���뱭��"<<endl;
	}
	//�ӵ�����
	virtual void addSonm()
	{
		cout<<"�ӵ���"<<endl;
	}
};


void test1()
{
	Coffee cf;
	Tea t;
	cf.func();
	t.func();
}
int main()
{
	test1();
	system("pause");
	return 0;
}