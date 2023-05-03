#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//1、创建基类
class Animal
{//基类，抽象类
public:
	virtual void speak() = 0;	//纯虚类
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout<<"Animal析构"<<endl;
}

//2、创建动物子类
class Dog:public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{//重写父类的虚函数
		cout<< "小狗"<< name<<"汪汪汪" <<endl;
	}
	~Dog()
	{
		cout<<"Dog析构"<<endl;
	}
private:
	string name;
};
class Duck:public Animal
{
public:
	Duck(string name, string type)
	{
		this->name = name;
		this->type = type;
	}
	virtual void speak()
	{
		cout<<type<<"品牌的鸭子"<< name << "嘎嘎嘎" <<endl;
	}
	~Duck()
	{
		cout<<"Duck析构"<<endl;
	}
private:
	string name;
	string type;
};
class Tiger:public Animal
{
public:
	Tiger(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	virtual void speak()
	{
		cout<<age<<"岁的老虎"<<name<<"嗷嗷嗷"<<endl;
	}
	~Tiger()
	{
		cout<<"Tiger析构"<<endl;
	}
private:
	string name;
	int age;
};

//3、创建动物园
class Zoo
{
public:
	Zoo()
	{
		mSize = 0;
		mCapacity = 1024;
		this->p = new Animal*[1024];	//申请一个容量为1024个动物的空间
	}
	int AddAnimal(Animal* am)
	{
		assert(am);
		if(mSize<mCapacity)
		{
			(this->p)[mSize] = am;
			this->mSize++;
			return 0;
		}
		else
		{
			return -1;
		}
	}
	void AnimalSpeak()
	{
		int i = 0;
		for(i = 0; i<mSize; i++)
		{
			(this->p)[i]->speak();
		}
	}
	~Zoo()
	{
		int i = 0;
		for(i=0; i<mSize; i++)
		{//释放动物申请的空间
			if(p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}
		}
		delete[] p;		//释放动物园申请的空间
		p = NULL;
		cout<<"Zoo析构"<<endl;
	}
private:
	Animal* *p;
	int mCapacity;	//容量
	int mSize;
};
void test1()
{
	Zoo* z = new Zoo;
	z->AddAnimal(new Dog("大黄"));
	z->AddAnimal(new Duck("黑子","周黑鸭"));
	z->AddAnimal(new Tiger("泰哥", 5));
	z->AnimalSpeak();
	delete z;
}
int main()
{
	test1();
	system("pause");
	return 0;
}