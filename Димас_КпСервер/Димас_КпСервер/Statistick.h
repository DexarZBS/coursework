#pragma once
#include<iostream>
#include"Human.h"
#include"Logistick_centre.h"
using namespace std;
class Statistick :public Human , public Logistick_centre
{
	char date[100];
	int cash1;
public:
	void setDate(char* a);
	void setCash1(int a);
	int getCahs1();
	char* getDate();
	friend ostream& operator<<(ostream& os, Statistick& obj);
};
