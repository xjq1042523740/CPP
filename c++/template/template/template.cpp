#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//һ������ģ�庯��
template<class T>//�ñ�����������仰��������ŵĺ�������T��Ҫ����,T�����͵��������ͣ�����ֻ��дT��
void Swap(T &a,T &b)
{
	T temp;
	temp = a;
	a=b;
	b=temp;
}
void test1()
{
	int a=10;
	int b=20;
	//ʹ�ú���ģ��
	//1���������Զ��Ƶ���������
	Swap(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
	//2����ʾ��ָ������
	//��<int>��ʾ���߱������������������ָ��Ϊint�ͣ���ʵ�ʴ�������ͱ���Ҫ��ָ��������һ�¡�
	Swap<int>(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
	//double c=1.5,d=2.5;
	//Swap<int>(c,d);err
	Swap<>(a,b);
	cout<<"a="<<a<<"\n"<<"b="<<b<<endl;
}

template<class T>
T Add(T a,T b)
{
	return a+b;
}

void test2()
{	//������ʽ����ת��
	//���ʹ�ò����б�ָ���������ͣ���ôʵ���п�����ʽת����
	//���ת���ɹ����͵��ã�ת�����ɹ��ͱ���
	int a=10;
	double b=15.5;
	cout<<"a+b="<<Add<int>(a,b)<<endl;
	char c='a';
	cout<<Add<double>(a,c)<<endl;
}

//������ͨ�����뺯��ģ�������
int Add2(int a,int b)
{
	return a+b;
}
void test3()
{
	int a=10;
	double b=12.5;
	cout<<Add2(a,b)<<endl;//��ͨ�������Խ�����ʽת��
	//cout<<Add(a,b)<<endl;//err ����ģ�治��ֱ�ӵĽ�����ʽת��
	cout<<Add<int>(a,b);//���Ҫ��������ת����������ϲ����б�
}

//�ġ���ͨ�����뺯��ģ��ĵ��ù���
//1������ģ�����ͨ������������
void myAdd(int a,int b)
{
	cout<<"��ͨ����"<<endl;
}
template<class T>
void myAdd(T a,T b)
{
	cout<<"����ģ��1"<<endl;
}
//2������ģ��֮��Ҳ��������
template<class T>
void myAdd(T a, T b,T c)
{
	cout<<"����ģ��2"<<endl;
}
void test4()
{
	int a=10;
	int b=15;
	//3�������ͨ�����ͺ���ģ�涼����ʵ�ֵĹ��ܣ���ͨ�������ȵ���
	myAdd(a,b);
	//4������ʹ��<>�ղ����б�ǿ�Ƶ��ú���ģ��
	myAdd<>(a,b);
	//5���������ģ����Բ������õ�ƥ�䣬��ô����ʹ�ú���ģ��
	char c1='c';
	char c2='d';
	myAdd(c1,c2);
}

//�塢ģ��ľ����Լ��������������ģ����廯��
//��������廯����ģ�棬��Ϊû��ͨ����
class Maker
{
public:
	Maker(string name,int age)
	{
		this->age=age;
		this->name=name;
	}
public:
	string name;
	int age;
};
template<class T>
void myfunc(T &a,T &b)
{//�Ƚϴ�С����ģ��
	if(a>=b)
	{
		cout<<"a>=b"<<endl;
	}
	else
	{
		cout<<"a<b"<<endl;
	}
}
template<>void myfunc<Maker>(Maker &a,Maker &b)
{//���廯����ģ�棬ע������ĺ���ģ��Ҫ�У����ܾ��廯
	if(a.age>=b.age)
	{
		cout<<"a>=b"<<endl;
	}
	else
	{
		cout<<"a<b"<<endl;
	}
}
void test5()
{
	Maker a("���",18);
	Maker b("������",19);
	myfunc(a,b);
}

//������ģ��
template<class NameType,class AgeType>
class Maker2
{
public:
	Maker2(NameType name, AgeType age)
	{
		this->name=name;
		this->age=age;
	}
	void PrintMaker2()
	{
		cout<<name<<"\t"<<age<<endl;
	}
public:
	NameType name;
	AgeType age;
};
void test6()
{//1.��ģ�治���Զ��Ƶ��������ͣ�Ҫ��ʾ�ĸ��߱�������ʲô����
	Maker2<string,int> m1("���",18);
	//2.ע�⴫��Ĳ���,�����������Ҫ����Ա�Լ�����
	Maker2<int,int> m2(20,19);
	m1.PrintMaker2();
	m2.PrintMaker2();
	//Maker2<> m3("aaa",12);err ����ͨ�������б���߱�������ʲô����
}

//Ĭ�ϲ���
template<class NameType,class AgeType=int>
class Maker3
{
public:
	Maker3(NameType name, AgeType age)
	{
		this->name=name;
		this->age=age;
	}
	void PrintMaker3()
	{
		cout<<name<<"\t"<<age<<endl;
	}
public:
	NameType name;
	AgeType age;
};
void test7()
{
	Maker3<string> m1("������",19);
	m1.PrintMaker3();
}

//�ߡ�������ģ����
template<class T>
class Maker4 
{
public:
	Maker4()
	{
		a=0;
		b=0;
	}
	Maker4(T a,T b)
	{
		this->a=a;
		this->b=b;
	}
	void Print()
	{
		cout<<"("<<a<<","<<b<<")"<<endl;
	}
	Maker4 Maker_add(Maker4 &p)
	{
		Maker4 temp;
		temp.a=this->a+p.a;
		temp.b=this->b+p.b;
		return temp;
	}
	Maker4 operator+(Maker4 &p)
	{//����������ʵ��
		Maker4 temp;
		temp.a=this->a+p.a;
		temp.b=this->b+p.b;
		return temp;
	}
private:
	T a;
	T b;
};
void test8()
{
	Maker4<int> m1(5,6);
	Maker4<int> m2(10,-6);
	Maker4<int> m3=m1.Maker_add(m2);
	m3.Print();
	m3 = m1+m3;
	m3.Print();
}

//�ˡ���ģ������������
//1��ָ���������������
void func1(Maker2<string,int> &m1)
{
	m1.PrintMaker2();
}
//2������ģ�滯(����ģ�廯)�����ã�
template<class NameType,class AgeType>
void func2(Maker2<NameType,AgeType> &m1)
{
	m1.PrintMaker2();
}
//3��������ģ�廯
template<class T>
void func3(T &m1)
{
	m1.PrintMaker2();
}
void test9()
{
	Maker2<string,int> m("С��",20);
	func1(m);
	func2(m);
	func3(m);
}

//�š���ģ��ļ̳�
//1����ͨ��̳���ģ��
template<class T>
class Father
{
public:
	Father()
	{
		a=20;
	}
public:
	T a;
};
//��ͨ��
class Son:public Father<int>//Ҫ���߱���������ķ����������;�����ʲô����
{
public:
};
//��ģ��̳���ģ��
template<class T1,class T2>
class Son2:public Father<T2>//Ҫ���߱���������ķ����������;�����ʲô����
{
public:
	Son2()
	{
		b=20.1;
	}
public:
	T1 b;
};
void test10()
{
	Son s1;
	Son2<double,int> s2;
	cout<<s1.a<<"\n"<<s2.a<<"\t"<<s2.b<<endl;
}

//ʮ����ģ��ĳ�Ա������������ʵ��
//����ʵ��
template<class NameType,class AgeType>
class Maker5
{
public:
	Maker5(NameType name,AgeType age);
	//{
	//	this->name=name;
	//	this->age=age;
	//}
	void MakerPrint5();
	//{
	//	cout<<"name:"<<name<<endl;
	//	cout<<"age:"<<age<<endl;
	//}
public:
	NameType name;
	AgeType age;
};
//����ʵ��,Ҫд�ɺ���ģ��,����д�ϲ����б�
template<class NameType,class AgeType>
Maker5<NameType,AgeType>::Maker5(NameType name,AgeType age)
{
	this->name=name;
	this->age=age;
}
template<class NameType,class AgeType>
void Maker5<NameType,AgeType>::MakerPrint5()
{
	cout<<"name:"<<name<<endl;
	cout<<"age:"<<age<<endl;
}
void test11()
{
	Maker5<string,int> m5("����",18);
	m5.MakerPrint5();
}

//ʮһ����ģ��������Ԫ
//����ģ��(����)
template<class NameType,class AgeType>
class Maker6;
//��������ģ�棬���߱�����������printMaker2��ʵ��
template<class NameType,class AgeType>
void PrintMaker7(Maker6<NameType,AgeType> &m7);
//��Ԫ����ʵ��
template<class NameType,class AgeType>
class Maker6
{
	friend void PrintMaker7<>(Maker6<NameType,AgeType> &m7);//�ں�������()֮�����<>�������⣩
	//��������֪��printMaker7������û��ʵ�֣���Ҫ֪�������Ľṹ
	friend void PrintMaker6(Maker6<NameType,AgeType> &m6)
	{
		cout<<"����ʵ��"<<endl;
		cout<<"Name:"<<m6.name<<endl;
		cout<<"Age:"<<m6.age<<endl;
	}
public:
	Maker6(NameType name,AgeType age)
	{
		this->name=name;
		this->age=age;
	}
private:
	NameType name;
	AgeType age;
};
//��Ԫ����ʵ�֣���Ԫ������ʵ��Ҫд�ɺ���ģ��
template<class NameType,class AgeType>
void PrintMaker7(Maker6<NameType,AgeType> &m7)
{
	cout<<"����ʵ��"<<endl;
	cout<<"Name:"<<m7.name<<endl;
	cout<<"Age:"<<m7.age<<endl;
}
void test12()
{
	Maker6<string,int> m6("���",18);
	PrintMaker6(m6);
	PrintMaker7(m6);
}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test12();
	system("pause");
	return 0;
}