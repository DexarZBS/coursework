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
	os << "Дата заключения контракта : " << obj.getDate() << endl;
	os << "Имя клиента : " << obj.getName() << endl;
	os << "Паспортные данные : " << obj.getPas_info() << endl;
	os << "Номер телефона : " << obj.getTel() << endl;
	os << "Название склада : " << obj.getNameStore() << endl;
	os << "Площадь склада : " << obj.getArea() << endl;
	os << "Кол-во дней аренды : " << obj.getArea() << endl;
	os << "Сумма к оплате : " << obj.getCahs1() << endl;
	os << "#################################################################" << endl;
	return os;
}
