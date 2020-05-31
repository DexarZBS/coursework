#pragma once
#include<iostream>
using namespace std;
class Rating 
{
	int position;
	int rating;
	char nameExpert[100];
public:
	void setPosition(int a);
	void setRating(int a);
	void setNameExpert(char* a);
	int getPosition();
	int getRating();
	char* getNameExpert();
	friend istream& operator >>(istream& os, Rating& obj);
};