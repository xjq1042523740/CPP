#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
	friend istream &operator>>(istream &in, Maker &m);
public:
	Maker()
	{
		cout<<"�޲ι���"<<endl;
	}
	Maker(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
private:
	int age;
	string name;
};

//	(cout)�βκ�ʵ����һ������(ostream����)����ostream�ѿ�������˽�л��ˡ�
ostream &operator<<(ostream &out, Maker &m)
{
	out<<m.age<<" "<<m.name<<endl;
	//	endl��һ������
	//	<<������ڲ������˻�����������
	return out;
}

istream &operator>>(istream &in, Maker &m)
{
	in>>m.age;
	in>>m.name;
	return in;	
}

void test3()
{
	Maker m1(20,"С��");
	cout<<m1<<endl;
	
}
void test4()
{
	Maker m1;
	Maker m2(18,"���");
	cout<<"���룺";
	cin>>m1>>m2;
	cout<<"���������\n"<<m1<<m2<<endl;
}
int main2()
{
	test4();
	system("pause");
	return 0;
}