#pragma once

#include<iostream>
#include<string>
using namespace std;

class Dot
{
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
private:
	int myX;
	int myY;
};

class Circle
{
public:
	void setR(int x);
	void setO(int x, int y);
	void setO(Dot o);
	int getR();
	Dot getO();
	int getDistanceSeq(Dot &dot);	//计算圆心与目标点的距离
	int IsLocateInside(Dot& dot);//判断是否在圆内 在内部返回1，在圆上返回0， 在园外返回-1
private:
	int myR;
	Dot myO;
};

int IsLocateInside1(Dot& dot, Circle c);