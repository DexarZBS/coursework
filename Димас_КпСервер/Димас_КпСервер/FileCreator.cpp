#include "FileCreator.h"

void FileCreator::write_vector_Account(vector<Human>& vec, string nameFile)
{
	int check = 0;
	ofstream file(nameFile);
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Store(vector<Logistick_centre>& vec, string nameFile)
{
	int check = 0;
	ofstream file(nameFile);
	for (vector<Logistick_centre>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getNameStore() << "\t" << i->getArea() << "\t" << i->getAmountDay() << "\t" << i->getSum() << "\t" << i->getNameExpert();
		}
		else
		{
			file << i->getNameStore() << "\t" << i->getArea() << "\t" << i->getAmountDay() << "\t" << i->getSum() << "\t" << i->getNameExpert() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Rating(vector<Rating>& vec, string nameFile)
{
	int check = 0;
	ofstream file(nameFile);
	for (vector<Rating>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getRating()<<"\t" << i->getNameExpert() << "\t" << i->getPosition();
		}
		else
		{
			file << i->getRating() << "\t" << i->getNameExpert() << "\t" << i->getPosition() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_credit(vector<Credit>& vec, string namefile)
{
	int check = 0;
	ofstream file(namefile);
	for (vector<Credit>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file<< i->getDate()<< "\t"<< i->getName() << "\t" << i->getPas_info() << "\t" << i->getTel() << "\t" << i->getSumcredit();
		}
		else
		{
			file << i->getDate() << "\t" << i->getName() << "\t" << i->getPas_info() << "\t" << i->getTel() << "\t" << i->getSumcredit() << endl;
		}
		check++;
	}
	file.close();
}
