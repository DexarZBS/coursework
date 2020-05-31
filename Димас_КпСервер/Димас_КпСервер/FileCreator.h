#pragma once
#include"User.h"
#include"Logistick_centre.h"
#include"Rating.h"
#include<iostream>
#include"Credit.h"
#include<fstream>
#include<string>
static string FileClient = "klient.txt";
static string FileAdmin = "Admin.txt";
static string FileExpert = "Expert.txt";
static string FileStore = "Stor.txt";
static string FileRating = "Rating.txt";
static string FileReport = "Report.txt";
static string FileCredit = "Credit.txt";
using namespace std;
class FileCreator
{
public:
	template<class T>
	void read_vector(vector<T>& vec, string nameFile);
	void write_vector_Account(vector<Human>& vec, string nameFile);
	void write_vector_Store(vector<Logistick_centre>& vec, string nameFile);
	void write_vector_Rating(vector<Rating>& vec, string nameFile);
	void write_vector_credit(vector<Credit>& vec, string namefile);

};

template<class T>
inline void FileCreator::read_vector(vector<T>& vec, string nameFile)
{
	ifstream file;
	file.open(nameFile);
	if (file.peek() == EOF)
	{
	}
	else
	{
		while (!file.eof())
		{

			T obj;
			file >> obj;
			vec.push_back(obj);
		}
	}
	file.close();
}


