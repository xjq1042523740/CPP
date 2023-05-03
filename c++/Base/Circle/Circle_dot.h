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
	int getDistanceSeq(Dot &dot);	//����Բ����Ŀ���ľ���
	int IsLocateInside(Dot& dot);//�ж��Ƿ���Բ�� ���ڲ�����1����Բ�Ϸ���0�� ��԰�ⷵ��-1
private:
	int myR;
	Dot myO;
};

int IsLocateInside1(Dot& dot, Circle c);