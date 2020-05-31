#include "Human.h"
Human::Human()
{
	cash = 0;
}

void Human::setCash(int a)
{
	cash = a;
}

int Human::getCash()
{
	return cash;
}


void Human::setName(char* nam)
{
	strcpy_s(name, sizeof(name), nam);
}

void Human::setTel(char* tel)
{
	strcpy_s(this->tel, sizeof(this->tel), tel);
}

void Human::setPass_info(char* info)
{
	strcpy_s(this->pas_indo, sizeof(pas_indo), info);
}

void Human::setPassword(char* pass)
{
	strcpy_s(this->password, sizeof(password), pass);
}

void Human::setLogin(char* log)
{
	strcpy_s(this->login, 100, log);
}

char* Human::getName()
{
	return name;
}

char* Human::getTel()
{
	return tel;
}

char* Human::getPas_info()
{
	return pas_indo;
}

char* Human::getlogin()
{
	return login;
}

char* Human::getPassword()
{
	return password;
}

ostream& operator<<(ostream& os, Human& obj)
{
	os << "\t" << obj.getName() << "\t" << obj.getTel() << "\t" << obj.getPas_info() << "\t" << obj.getlogin() << "\t" << obj.getPassword() << endl;
	return os;
}

istream& operator>>(istream& os, Human& obj)
{
	os >> obj.name >> obj.tel >> obj.pas_indo >> obj.login >> obj.password >> obj.cash;
	return os;
}


