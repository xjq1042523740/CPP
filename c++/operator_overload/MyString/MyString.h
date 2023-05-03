#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class MyString
{
	friend ostream &operator<<(ostream &out, MyString &str);
	friend istream &operator>>(istream &in, MyString &str);
public:
	MyString();
	MyString(int n, char c);	//有参构造
	MyString(const MyString &str);	//拷贝构造

	MyString operator+(const MyString &str);			//MyString + MyString
	MyString operator+(const char* s);	//MyString + const MyString

	MyString &operator=(const MyString &str);		//MyString=str


	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *s);

	int Size();
	char &operator[](int index);
	~MyString();
private:
	char* pM;
	int mSize;
};

