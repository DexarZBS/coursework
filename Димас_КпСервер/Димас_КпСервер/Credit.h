#pragma once
#include<iostream>
using namespace std;
class Credit 
{
	char date[100];
	char name[100];
	char tel[100];
	char pas_indo[100];
	int sumcredit;
public:
	void setDate(char* dat);
	void setName(char* nam);
	void setTel(char* tel);
	void setPass_info(char* info);
	void setSumCredit(int a);
	char* getDate();
	int getSumcredit();
	char* getName();
	char* getTel();
	char* getPas_info();
	friend istream& operator>>(istream& os, Credit& obj);
};
