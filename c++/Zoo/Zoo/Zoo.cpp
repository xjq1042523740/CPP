#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
//1����������
class Animal
{//���࣬������
public:
	virtual void speak() = 0;	//������
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout<<"Animal����"<<endl;
}

//2��������������
class Dog:public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{//��д������麯��
		cout<< "С��"<< name<<"������" <<endl;
	}
	~Dog()
	{
		cout<<"Dog����"<<endl;
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
		cout<<type<<"Ʒ�Ƶ�Ѽ��"<< name << "�¸¸�" <<endl;
	}
	~Duck()
	{
		cout<<"Duck����"<<endl;
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
		cout<<age<<"����ϻ�"<<name<<"���"<<endl;
	}
	~Tiger()
	{
		cout<<"Tiger����"<<endl;
	}
private:
	string name;
	int age;
};

//3����������԰
class Zoo
{
public:
	Zoo()
	{
		mSize = 0;
		mCapacity = 1024;
		this->p = new Animal*[1024];	//����һ������Ϊ1024������Ŀռ�
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
		{//�ͷŶ�������Ŀռ�
			if(p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}
		}
		delete[] p;		//�ͷŶ���԰����Ŀռ�
		p = NULL;
		cout<<"Zoo����"<<endl;
	}
private:
	Animal* *p;
	int mCapacity;	//����
	int mSize;
};
void test1()
{
	Zoo* z = new Zoo;
	z->AddAnimal(new Dog("���"));
	z->AddAnimal(new Duck("����","�ܺ�Ѽ"));
	z->AddAnimal(new Tiger("̩��", 5));
	z->AnimalSpeak();
	delete z;
}
int main()
{
	test1();
	system("pause");
	return 0;
}