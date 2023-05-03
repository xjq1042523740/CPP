#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Building
{
	//����ȫ�ֺ���Ϊ��Ԫ
	friend void Change(Building &bud, int c, int d);
public:
	void Print()
	{
		cout<<"a="<<a<<"\tb="<<b<<endl;
	}
	Building()
	{
		cout<<"�޲ι���"<<endl;
		a = 10;
		b = 20;

	}
	~Building()
	{
		cout<<"��������"<<endl;
	}
private:
	int a;
	int b;
	string bedroom;
	string livingroom;
};


void Change(Building &bud, int c, int d)
{
	bud.a = c;
	bud.b = d;
}

void test0()
{
	Building bud;
	bud.Print();
	Change(bud, 100, 200);
	bud.Print();
}


class Building2
{
	//����GoodF��Ϊ��Ԫ
	friend class GoodF;
public:
	void Print()
	{
		cout<<"bedroom="<<bedroom<<"\tlivingroom="<<livingroom<<endl;
	}
	Building2()
	{
		cout<<"�޲ι���"<<endl;
		bedroom = "����";
		livingroom = "����";
	}
	~Building2()
	{
		cout<<"��������"<<endl;
	}
private:
	string bedroom;
	string livingroom;
};

class GoodF
{
public:
	//1��ͨ������������˽�г�Ա
	void visitB(Building2 &bud)
	{
		cout<<"bedroom="<<bud.bedroom<<"\tlivingroom="<<bud.livingroom<<endl;
	}
	//2��ͨ��ָ��������˽�г�Ա
	void visitBud(Building2 *pbud)
	{
		cout<<"bedroom="<<pbud->bedroom<<"\tlivingroom="<<pbud->livingroom<<endl;
	}
};

void test1()
{
	Building2 bud;
	GoodF goodf;
	goodf.visitB(bud);
	goodf.visitBud(&bud);
}

class Building3;
class GoodF1
{//������Ľṹ
public:
	void visitB3(Building3 &bud3);
};

class Building3
{
	//���������ķ�������Ԫ
	friend void GoodF1::visitB3(Building3 &bud3);
public:
	void Print()
	{
		cout<<"bedroom="<<bedroom<<"\tlivingroom="<<livingroom<<endl;
	}
	Building3()
	{
		cout<<"�޲ι���"<<endl;
		bedroom = "����";
		livingroom = "����";
	}
	~Building3()
	{
		cout<<"��������"<<endl;
	}
private:
	string bedroom;
	string livingroom;
};

void GoodF1::visitB3(Building3 &bud3)
{
	cout<<"bedroom="<<bud3.bedroom<<"\tlivingroom="<<bud3.livingroom<<endl;
}

void test2()
{
	Building3 bud3;
	GoodF1 goodf1;
	goodf1.visitB3(bud3);
}

int main()
{
	test2();
	system("pause");
	return 0;
}