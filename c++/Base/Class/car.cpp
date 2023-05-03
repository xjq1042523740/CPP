#include "car.h"

void Car::Init()
{
	brand = "BWM";
	Size = 5;
	Color = "blue";
}

void Car::CarPrint()
{
	cout<< "brand: " << brand << "  Size: " << Size << "  Color: " << Color <<endl;
}

int Car::getSize()
{
	return Size;
}

string Car::getbrand()
{
	return brand;
}
string Car::getColor()
{
	return Color;
}

void Truck::setnum(int n)
{
	num = n;
}
void Truck::setmyT(int t)
{
	myT = t;
}
void Truck::setbrand(string b)
{
	brand = b;
}
int Truck::getnum()
{
	return num;
}
int Truck::getmyT()
{
	return myT;
}
string Truck::getbrand()
{
	return brand;
}
void Truck::Pint()
{
	cout<< "brand:" << brand << "  num: "<< num <<"  myT: " << myT <<endl;
	Car::Init();
	Car::CarPrint();
}