#include "Cube.h"
using namespace std;

void Cube::Init()
{
	myH = 0;
	myL = 0;
	myW = 0;
}
void Cube::setH(int h)
{
	myH = h;
}
void Cube::setW(int w)
{
	myW = w;
}
void Cube::setL(int l)
{
	myL = l;
}
int Cube::getS()
{
	return 2*(myL*myW + myL*myH + myH*myW);
}
int Cube::getV()
{
	return myL*myW*myH;
}
int Cube::getH()
{
	return myH;
}
int Cube::getW()
{
	return myW;
}
int Cube::getL()
{
	return myL;
}
bool Cube::equation(Cube &c)
{
	if(c.getH()==myH && c.getL()==myL && c.getW()==myW)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Isequation(Cube &c1, Cube &c2)
{
	if(c1.getH()==c2.getH() && c1.getL()==c2.getL() && c1.getW()==c2.getW())
	{
		return true;
	}
	else
	{
		return false;
	}
}