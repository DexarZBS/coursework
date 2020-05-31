#include "Logistick_centre.h"

void Logistick_centre::setNameExpert(char* a)
{
	strcpy_s(nameExpert, sizeof(nameExpert), a);
}

char* Logistick_centre::getNameExpert()
{
	return nameExpert;
}

void Logistick_centre::setNamestore(char* a)
{
	strcpy_s(nameStore, sizeof(nameStore), a);
}

void Logistick_centre::setArea(int a)
{
	area = a;
}

void Logistick_centre::setAmountDay(int a)
{
	amountDay = a;
}

void Logistick_centre::setSum()
{
	sum = (area * 3) * (amountDay / 0.1);
}

char* Logistick_centre::getNameStore()
{
	return nameStore;
}

int Logistick_centre::getArea()
{
	return area;
}

int Logistick_centre::getAmountDay()
{
	return amountDay;
}

int Logistick_centre::getSum()
{
	return sum;
}

istream& operator>>(istream& os, Logistick_centre& obj)
{
	os >> obj.nameStore >> obj.area >> obj.amountDay >> obj.sum >> obj.nameExpert;
	return os;
}
