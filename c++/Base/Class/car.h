#pragma once
#include<iostream>
#include<string>
using namespace std;

class Car
{
public://����Ȩ��
	void Init();
	void CarPrint();
	int getSize();
	string getColor();
	string getbrand();
private://˽��Ȩ��
	int Size;
	string Color;
	string brand;
};

class Truck:public Car
{
public:
	void setnum(int n);
	void setmyT(int t);
	void setbrand(string b);
	int getnum();
	int getmyT();
	string getbrand();
	void Pint();
private:
	int num;
	int myT;
	string brand;
};