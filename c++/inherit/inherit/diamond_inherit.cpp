#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


class Animal
{//祖类
public:
	Animal()
	{
		a=10;
	}
	int a;
	int b;
};
class Sheep:virtual public Animal
{//父类	
};

class Camel:virtual public Animal
{//父类
};

class SheepCamel:public Sheep,public Camel
{//子类
};
void test6()
{
	SheepCamel sc;
	cout<<sc.a<<endl;		
	cout<<sizeof(sc)<<endl;
	cout<<sizeof(Sheep)<<endl;
}


int main5()
{
	test6();
	system("pause");
	return 0;
}