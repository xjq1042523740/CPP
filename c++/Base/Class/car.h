#pragma once
#include<iostream>
#include<string>
using namespace std;

class Car
{
public://公有权限
	void Init();
	void CarPrint();
	int getSize();
	string getColor();
	string getbrand();
private://私有权限
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