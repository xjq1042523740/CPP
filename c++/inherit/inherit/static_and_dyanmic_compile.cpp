#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Animal1
{
public:
	virtual void speak()	//有virtual就是动态编译，晚绑定
	{
		cout<< "Animal Speak" <<endl; 
	}
};
class Dog:public Animal1
{
public:
	void speak()
	{
		cout<< "Dog Speak" <<endl;
	}
	virtual void say()
	{
		cout<< "Dog1 say" <<endl;
	}
};

class Dog1:public Animal1
{
public:
	void speak()
	{
		cout<< "Dog1 Speak" <<endl;
	}
};

void fun(Animal1* an)
{
	an->speak();
}

void test7()
{
	Dog dog;
	fun(&dog);

	Dog1 dog1;
	fun(&dog1);

	Dog1* dg1 = new Dog1;
	fun(dg1);

	Animal1 am;
	cout<< sizeof(Animal1) <<endl;
}

int main()
{
	test7();
	system("pause");
	return 0;
}