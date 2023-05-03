#include "Circle_dot.h"
using namespace std;


void Dot::setX(int x)
{
	myX = x;
}
void Dot::setY(int y)
{
	myY = y;
}
int Dot::getX()
{
	return myX;
}
int Dot::getY()
{
	return myY;
}

void Circle::setR(int x)
{
	myR = x;
}
void Circle::setO(int x, int y)
{
	myO.setX(x);
	myO.setY(y);
}
void Circle::setO(Dot o)
{
	myO = o;
}
int Circle::getR()
{
	return myR;
}
Dot Circle::getO()
{
	return myO;
}
int Circle::getDistanceSeq(Dot &dot)	//计算圆心与目标点的距离
{
	int seq;
	seq = (myO.getX()-dot.getX())*(myO.getX()-dot.getX())+(myO.getY()-dot.getY())*(myO.getY()-dot.getY());
	return seq;
}
int Circle::IsLocateInside(Dot& dot)	//判断是否在圆内 在内部返回1，在圆上返回0， 在园外返回-1
{
	if(getDistanceSeq(dot) == myR*myR)
	{
		return 0;
	}
	else if(getDistanceSeq(dot) > myR*myR)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int IsLocateInside1(Dot& dot, Circle c)	//判断是否在圆内 在内部返回1，在圆上返回0， 在园外返回-1
{
	if(c.getDistanceSeq(dot) == c.getR()*c.getR())
	{
		return 0;
	}
	else if(c.getDistanceSeq(dot) > c.getR()*c.getR())
	{
		return -1;
	}
	else
	{
		return 1;
	}
}