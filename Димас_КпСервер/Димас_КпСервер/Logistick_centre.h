#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Logistick_centre
{
	char nameExpert[100];
	char nameStore[100];
	int area;
	int amountDay;
	int sum;
public:
	void setNameExpert(char* a);
	char* getNameExpert();
	void setNamestore(char* a);
	void setArea(int a);
	void setAmountDay(int a);
	void setSum();
	char* getNameStore();
	int getArea();
	int getAmountDay();
	int getSum();
	friend istream& operator>>(istream& os, Logistick_centre& obj);
};