#include "Credit.h"

void Credit::setDate(char* dat)
{
	strcpy_s(date, sizeof(date), dat);
}

void Credit::setName(char* nam)
{
	strcpy_s(name, sizeof(name), nam);
}

void Credit::setTel(char* tel)
{
	strcpy_s(this->tel, sizeof(this->tel), tel);
}

void Credit::setPass_info(char* info)
{
	strcpy_s(this->pas_indo, sizeof(pas_indo), info);
}

void Credit::setSumCredit(int a)
{
	sumcredit = a;
}

char* Credit::getDate()
{
	return date;
}

int Credit::getSumcredit()
{
	return sumcredit;
}

char* Credit::getName()
{
	return name;
}

char* Credit::getTel()
{
	return tel;
}

char* Credit::getPas_info()
{
	return pas_indo;
}

istream& operator>>(istream& os, Credit& obj)
{
	os >>obj.getDate()>> obj.name >> obj.pas_indo >> obj.tel >> obj.sumcredit;
	return os;
}
