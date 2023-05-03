#define _CRT_SECURE_NO_WARNINGS 1
#include"Circle_dot.h"

int main()
{
	Dot d1;
	d1.setX(10);
	d1.setY(10);
	Circle c1;
	c1.setO(30,10);
	c1.setR(10);
	cout<< c1.IsLocateInside(d1) <<endl;
	cout << IsLocateInside1(d1, c1)<<endl;
	return 0;
}