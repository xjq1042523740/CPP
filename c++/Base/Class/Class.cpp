#define _CRT_SECURE_NO_WARNINGS 1
#include"car.h"
using namespace std;

int main()
{
	Car c;
	c.Init();
	c.CarPrint();
	cout<< c.getColor() <<endl;
	cout<< c.getbrand() <<endl;
	cout<< c.getSize() <<endl;
	Truck t;
	t.setnum(8);
	t.setmyT(50);
	t.setbrand("ÈýÒ»");
	t.getnum();
	t.getmyT();
	t.getbrand();
	t.Pint();
	system("pause");
	return 0;
}