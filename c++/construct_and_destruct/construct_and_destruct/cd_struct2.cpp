#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class BWM
{
public:
	BWM()
	{
		cout<< "BWM�޲ι���" <<endl;
	}

	BWM(int a)
	{
		cout<< "BWM�вι���" <<endl;
	}

	~BWM()
	{
		cout << "BWM��������" <<endl;
	}

private:
	string BWMColor;
	int BWMSize;
};

class BUIK
{
public:
	BUIK()
	{
		cout<< "BUIK�޲ι���" <<endl;
	}
	BUIK(int a)
	{
		cout<< "BUIK�вι���" <<endl;
	}

	~BUIK()
	{
		cout << "BUIK��������" <<endl;
	}
private:
	string BUIKColor;
	int BUIKSize;
};

class Maker1
{
public:
	Maker1():bwm(10), buik(20)//��ʼ���б����ж�������Ա��Ҫָ�����캯�����ͣ��ö��Ÿ�����
	{
		cout<< "Maker1�޲ι���" <<endl;
	}
	Maker1(int a,int b):bwm(a),buik(b) //ֻҪĳһ�����캯��ʹ���˳�ʼ���б���ô���еĹ��캯����Ҫд��ʼ���б�
	{
		cout<< "Maker1�вι���" <<endl;
	}
	~Maker1()
	{
		cout << "Maker1��������" <<endl;
	}
private:
	BWM bwm;	//����BWM��Ķ���
	BUIK buik;	//����BUIK��Ķ���
};

void test4()
{
	Maker1 m(5,10);
}
int main()
{
	test4();
	system("pause");
	return 0;
}