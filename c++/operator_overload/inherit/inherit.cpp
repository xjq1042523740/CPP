#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Father
{
public:
	Father()
	{
		a=10;
		b=20;
		c=30;
	}
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son:private Father
{
	void func()
	{
		a;
		b;

	}
};

void test()
{
	Son s;
	s.a;

}
int main()
{
	test();
	system("pause");
	return 0;
}