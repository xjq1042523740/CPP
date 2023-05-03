#define _CRT_SECURE_NO_WARNINGS 1

#include"Cube.h"
using namespace std;

int main()
{
	Cube c1;
	c1.setH(10);
	c1.setL(20);
	c1.setW(30);
	Cube c2;
	c2.setH(10);
	c2.setL(20);
	c2.setW(30);
	cout<< c1.getS()<<endl;
	cout<< c1.getV()<<endl;
	cout<< c1.equation(c2)<<endl;
	cout<< Isequation(c1,c2) <<endl;
	return 0;
}