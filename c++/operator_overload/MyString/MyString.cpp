#include "MyString.h"

MyString::MyString()
{
	this->pM = new char[1];
	*(this->pM) = '\0';
	this->mSize = 0;
}
MyString::MyString(int n, char c)	//有参构造:给pM赋值n个c
{
	this->pM = new char[n+1];
	memset(this->pM, c, n);
	(this->pM)[n] = '\0';
	this->mSize = n;
}

MyString::MyString(const MyString &str)	//拷贝构造
{
	this->pM = new char[str.mSize+1];
	strcpy(this->pM, str.pM);
	this->mSize = str.mSize;
}

MyString MyString::operator+(const MyString &str)			//MyString + MyString
{
	MyString temp;
	int num = 0;
	if(temp.pM != NULL)
	{
		delete[] temp.pM;
		temp.pM = NULL;
	}
	num = this->mSize + str.mSize + 1;
	temp.pM = new char[num];
	strcpy(temp.pM, this->pM);
	strcat(temp.pM, str.pM);
	temp.mSize = num-1;
	return temp;
}
MyString MyString::operator+(const char* s)				//MyString + const MyString
{
	MyString temp;
	int num = 0;
	if(temp.pM != NULL)
	{
		delete[] temp.pM;
		temp.pM = NULL;
	}
	num = this->mSize + strlen(s) + 1;
	temp.pM = new char[num];
	strcpy(temp.pM, this->pM);
	strcat(temp.pM, s);
	temp.mSize = num-1;
	return temp;
}	

MyString &MyString::operator=(const MyString &str)		//MyString=str
{
	if(this->pM != NULL)
	{
		delete[] this->pM;
		this->pM = NULL;
	}
	this->pM = new char[str.mSize+1];
	strcpy(this->pM,str.pM);
	this->mSize = str.mSize;
	return *this;	
}

MyString &MyString::operator+=(const MyString &str)
{
	MyString temp(*this);
	if(this->pM != NULL)
	{
		delete[] this->pM;
		this->pM = NULL;
	}
	this->pM = new char[this->mSize + str.mSize+1];
	strcpy(this->pM, temp.pM);
	strcat(this->pM,str.pM);
	this->mSize = temp.mSize + str.mSize;
	return *this;
}
MyString &MyString::operator+=(const char *s)
{
	MyString temp(*this);
	if(this->pM != NULL)
	{
		delete[] this->pM;
		this->pM = NULL;
	}
	this->pM = new char[this->mSize + strlen(s)+1];
	strcpy(this->pM, temp.pM);
	strcat(this->pM, s);
	this->mSize = temp.mSize + strlen(s);
	return *this;
}

int MyString::Size()
{
	return strlen(this->pM);
}

char &MyString::operator[](int index)
{
	return (this->pM)[index];
}

MyString::~MyString()
{
	if(this->pM != NULL)
	{
		delete[] this->pM;
		this->pM = NULL;
	}
}



ostream &operator<<(ostream &out, MyString &str)
{
	out<<str.pM;
	return out;
}
istream &operator>>(istream &in, MyString &str)
{
	char temp[1024]={0};
	in>>temp;
	int len = strlen(temp);
	if(str.pM != NULL)
	{
		delete[] str.pM;
		str.pM = NULL;
	}
	str.pM = new char[len+1];
	strcpy(str.pM, temp);
	str.mSize = len;
	return in;
}
