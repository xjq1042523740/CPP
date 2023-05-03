#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//自定义类型
class Circle
{
//公有权限
public://成员函数
	//设置半径
	void setR(double r)
	{
		mR = r;
	}
	//计算周长
	double getL()
	{
		return 2*mR*3.14;
	}
public://成员变量、成员属性
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
	Circle c;//实例化对象
	c.setR(2);
	//c.mR = 3;
	cout<< "圆的周长："<< c.getL() <<endl;

	Student s;
	s.setName("xx");
	s.setNum(221224);
	//s.name = "wew";//私有属性不可访问
	s.show();
	system("pause");
	return 0;
}