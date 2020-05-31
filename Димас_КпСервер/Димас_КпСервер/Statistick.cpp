#include "Statistick.h"

void Statistick::setDate(char* a)
{
	strcpy_s(date, sizeof(date), a);
}

void Statistick::setCash1(int a)
{
	cash1 = a;
}

int Statistick::getCahs1()
{
	return cash1;
}

char* Statistick::getDate()
{
	return date;
}

ostream& operator<<(ostream& os, Statistick& obj)
{
	os << "���� ���������� ��������� : " << obj.getDate() << endl;
	os << "��� ������� : " << obj.getName() << endl;
	os << "���������� ������ : " << obj.getPas_info() << endl;
	os << "����� �������� : " << obj.getTel() << endl;
	os << "�������� ������ : " << obj.getNameStore() << endl;
	os << "������� ������ : " << obj.getArea() << endl;
	os << "���-�� ���� ������ : " << obj.getArea() << endl;
	os << "����� � ������ : " << obj.getCahs1() << endl;
	os << "#################################################################" << endl;
	return os;
}
