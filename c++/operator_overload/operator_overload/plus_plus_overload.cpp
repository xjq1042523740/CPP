#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Maker4
{
public:
	Maker4(int a)
	{
		this->a = a;
	}
	//�涨ǰ��++����ռλ����
	Maker4 &operator++()
	{//����Maker4���ͣ�����++(++a)�ǿ��Դ��ڵġ�
		//ǰ��++����++�ٷ��ء�
		++this->a;
		return *this;
	}

	//�涨����++ʹ��int��Ϊռλ����
	Maker4 operator++(int)
	{//���ﲻ������������Ϊtemp�Ǿֲ�������
		//����++���ȷ�����++
		Maker4 temp(*this);		//��������
		this->a++;				
		return temp;
	}
public:
	int a;
};
ostream &operator<<(ostream &out,const Maker4 &m1)
{
	out<<m1.a<<endl;
	return out;
}

void test8()
{
	Maker4 m1(1);
	cout<<m1++<<endl;	//1	 ���ﷵ�صĿ�����tmp����
	cout<<++m1<<endl;	//3	 ���ﷵ�ص���++this->a�Ķ���
}

int main()
{
	test8();
	system("pause");
	return 0;
}