#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//�Զ�������
class Circle
{
//����Ȩ��
public://��Ա����
	//���ð뾶
	void setR(double r)
	{
		mR = r;
	}
	//�����ܳ�
	double getL()
	{
		return 2*mR*3.14;
	}
public://��Ա��������Ա����
	double mR;

};

class Student
{
public:
	/*void setName(char str[])*/
	void setName(string str)
	{
		//strcpy(name, str);
		name = str;
	}
	void setNum(int num)
	{
		number = num;
	}
	void show()
	{
		cout<< "name=" << name << "\tnumber=" << number <<endl;
	}
private:
	 //char name[20];
	string name;
	 int number;
};

int main()
{
	Circle c;//ʵ��������
	c.setR(2);
	//c.mR = 3;
	cout<< "Բ���ܳ���"<< c.getL() <<endl;

	Student s;
	s.setName("xx");
	s.setNum(221224);
	//s.name = "wew";//˽�����Բ��ɷ���
	s.show();
	system("pause");
	return 0;
}