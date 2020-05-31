#include "Rating.h"

void Rating::setPosition(int a)
{
	position = a;
}

void Rating::setRating(int a)
{
	rating = a;
}

void Rating::setNameExpert(char* a)
{
	strcpy_s(nameExpert, sizeof(nameExpert), a);
}

int Rating::getPosition()
{
	return position;
}

int Rating::getRating()
{
	return rating;
}

char* Rating::getNameExpert()
{
	return nameExpert;
}

istream& operator>>(istream& os, Rating& obj)
{
	os >> obj.rating >> obj.nameExpert >> obj.position;
	return os;
}
