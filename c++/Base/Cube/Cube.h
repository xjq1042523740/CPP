#pragma once

#include<iostream>
#include<string>
using namespace std;

class Cube
{
public:
	void Init();
	void setH(int h);
	void setW(int w);
	void setL(int l);
	int getH();
	int getW();
	int getL();
	int getS();
	int getV();
	bool equation(Cube &c);

private:
	int myH;
	int myL;
	int myW;
};
bool Isequation(Cube &c1, Cube &c2);

