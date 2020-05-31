#include "User.h"

int User::AutorizationExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::addStore(Server& obj,int i)
{
	char nameStore[100], bufarea[100], bufAmount[100], buf[100];
	int area;
	int amountDay;
	int sum;
	Logistick_centre log;
	recv(obj.GetNewConnection(), nameStore, sizeof(nameStore), 0);
	recv(obj.GetNewConnection(), bufarea, sizeof(bufarea), 0);
	recv(obj.GetNewConnection(), bufAmount, sizeof(bufAmount), 0);
	area = atoi(bufarea);
	amountDay = atoi(bufAmount);
	log.setNamestore(nameStore);
	log.setArea(area);
	log.setAmountDay(amountDay);
	log.setSum();
	sum = log.getSum();
	itoa(sum, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	char nameExpert[100];
	strcpy_s(nameExpert,sizeof(nameExpert),vecExpert[i].getName());
	log.setNameExpert(nameExpert);
	vecStore.push_back(log);
	save_info_Store();
	cout << "Был добавлен склад '" << nameStore << "'" << " экспертом = " << nameExpert << endl;
}

int User::AutorizationClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

User::User()
{
	FileCreator obj;
	obj.read_vector(vecHuman, FileClient);
	obj.read_vector(vecAdmin, FileAdmin);
	obj.read_vector(vecExpert, FileExpert);
	obj.read_vector(vecStore, FileStore);
	obj.read_vector(vecRating, FileRating);
	obj.read_vector(vecCredit, FileCredit);

}

void User::receptionUserCredit(Server& obj,int j)
{
	int check = 0;
	for (int i = 0; i < vecCredit.size(); i++)
	{
		if(strcmp(vecHuman[j].getName(),vecHuman[i].getName())==0 && strcmp(vecHuman[j].getPas_info(),vecHuman[i].getPas_info())==0 && strcmp(vecHuman[j].getTel(),vecHuman[i].getTel())==0)
		{
			char buf1[100];
			check++;
			itoa(check, buf1, 10);
			send(obj.GetNewConnection(), buf1, sizeof(buf1), 0);
			char date[100];
			char name[100];
			char tel[100], buf[100];
			char pas_indo[100];
			int sumcredit;
			strcpy_s(date, sizeof(date), vecCredit[i].getDate());
			strcpy_s(name, sizeof(name), vecCredit[i].getName());
			strcpy_s(pas_indo, sizeof(pas_indo), vecCredit[i].getPas_info());
			strcpy_s(tel, sizeof(tel), vecCredit[i].getTel());
			sumcredit = vecCredit[i].getSumcredit();
			itoa(sumcredit, buf, 10);
			send(obj.GetNewConnection(), date, sizeof(date), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			send(obj.GetNewConnection(), pas_indo, sizeof(pas_indo), 0);
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			break;
		}
	}
	if(check==0)
	{
		char buf[100];
		itoa(check, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
}

void User::replenish_credit(Server& obj, int i)
{
	char msg[100];
	int ch;
	receptionUserCredit(obj, i);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	ch = atoi(msg);
	if (ch == 0)
	{

	}
	else
	{
		ch = ch - 1;
		int sum;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		sum = atoi(buf);
		if(sum>vecHuman[i].getCash())
		{
			int eror = 1;
			char error[100];
				itoa(eror, error, 10);
				send(obj.GetNewConnection(), error, sizeof(error), 0);
		}
		else
		{

			int eror = 2;
			char error[100];
			itoa(eror, error, 10);
			send(obj.GetNewConnection(), error, sizeof(error), 0);
			int cheeeeck;
			if (sum < vecCredit[ch].getSumcredit())
			{
				cheeeeck = 1;
				char bur[100];
				itoa(cheeeeck, bur, 10);
				send(obj.GetNewConnection(), bur, sizeof(bur), 0);
				vecHuman[i].setCash(vecHuman[i].getCash() - sum);
				int rezault = vecCredit[ch].getSumcredit() - sum;
				vecCredit[ch].setSumCredit(rezault);
				char m[100];
				itoa(rezault, m, 10);
				send(obj.GetNewConnection(), m, sizeof(m), 0);
				save_info_credit();
				seve_info_Client();
			}
			if (sum > vecCredit[ch].getSumcredit())
			{
				cheeeeck = 2;
				char bur[100];
				itoa(cheeeeck, bur, 10);
				send(obj.GetNewConnection(), bur, sizeof(bur), 0);
				vecHuman[i].setCash(vecHuman[i].getCash() - sum);
				int rezault = sum - vecCredit[ch].getSumcredit();
				vecCredit[ch].setSumCredit(rezault);
				char m[100];
				itoa(rezault, m, 10);
				send(obj.GetNewConnection(), m, sizeof(m), 0);
				save_info_credit();
				seve_info_Client();
			}
			if (sum == vecCredit[ch].getSumcredit())
			{
				cheeeeck = 3;
				char bur[100];
				itoa(cheeeeck, bur, 10);
				vecHuman[i].setCash(vecHuman[i].getCash() - sum);
				send(obj.GetNewConnection(), bur, sizeof(bur), 0);
				auto rez = vecCredit.begin();
				vecCredit.erase(ch + rez);
				save_info_credit();
				seve_info_Client();
			}
		}
	}
}



void User::leaseCredit(Server& obj, int i)
{
	printf_infoStore(obj);
	int ch;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{

	}
	else
	{
		char name[100];
		char tel[100];
		char pas_indo[100];
		int sumcredit;
		char date[100];
		recv(obj.GetNewConnection(), date, sizeof(date), 0);
		Credit cred;
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		strcpy_s(pas_indo, sizeof(pas_indo), vecHuman[i].getPas_info());
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		sumcredit = vecStore[ch].getSum()*2;
		cred.setDate(date);
		cred.setName(name);
		cred.setPass_info(pas_indo);
		cred.setTel(tel);
		cred.setSumCredit(sumcredit);
		vecCredit.push_back(cred);
		save_info_credit();
		cout << "Клиент - " << vecHuman[i].getName() << " Взял в кредит  аренду склада - " << vecStore[ch].getNameStore() << endl;
	}
	
}

void User::replenish_account(Server& obj, int i)
{
	int sum;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	sum = sum + vecHuman[i].getCash();
	vecHuman[i].setCash(sum);
	seve_info_Client();
	cout << "Клиент - " << vecHuman[i].getName() << " Пополнил счет на сумму - " << sum << endl;
}

void User::ExpertReview(Server& obj, int i)
{
	int cof = 0;
	char nameExpert[100];
	float rang[100][100];
	if (vecRating.size() == 0 && vecStore.size() == 0)
	{
		int ch = 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);

	}
	/*if(vecReiting.size()%10==0)
	{
		int ch = 2;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);

	}*/
	else
	{

		int ch = 0;
		char buf[100];
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
		Rating temp;
		for (int i = 0; i < vecRating.size() - 1; i++)
		{
			for (int j = 0; j < vecRating.size() - i - 1; j++)
			{
				if (vecRating[j].getPosition() > vecRating[j + 1].getPosition())
				{
					temp = vecRating[j];
					vecRating[j] = vecRating[j + 1];
					vecRating[j + 1] = temp;
				}
			}
		}

		float rang[100][100];
		int pet = 0;
		for (int j = 0; j < vecRating.size() / 2; j++)
		{
			for (int i = 0; i < vecStore.size(); i++)
			{
				if (pet == vecRating.size())
				{
					break;
				}
				rang[i][j] = vecRating[pet].getRating();
				pet++;
			}
		}

		for (int i = 0; i < vecRating.size() / 2; i++)
		{
			cout << endl;
			for (int j = 0; j < vecStore.size(); j++)
			{
				cout << rang[i][j];
			}
		}
		cout << endl;

		int masCof[100];
		for (int i = 0; i < vecRating.size() / 2; i++)
		{
			int cof = 0;
			for (int j = 0; j < vecStore.size(); j++)
			{
				cof = rang[i][j] + cof;
			}
			cout << "kof - " << cof << endl;
			masCof[i] = cof;
		}
		float masAge[100];

		for (int i = 0; i < vecRating.size() / 2; i++)
		{
			float age = 0;
			for (int j = 0; j < vecStore.size(); j++)
			{
				float ag = rang[i][j] / masCof[i];
				age = age + ag;
			}
			age = age / (vecRating.size() / 2);
			cout << "age - " << age << endl;
			masAge[i] = age;
		}
		int check = 0;
		float iterator;
		iterator = masAge[0];
		for (int i = 0; i < vecRating.size() / 2; i++)
		{
			if (iterator < masAge[i])
			{
				iterator = masAge[i];
				check = i;
			}
		}
		char nameStore[100], bufarea[100], bufAmount[100], bufe[100];
		int area;
		int amountDay;
		int sum;
		strcpy_s(nameStore, sizeof(nameStore), vecStore[check].getNameStore());
		area = vecStore[check].getArea();
		amountDay = vecStore[check].getAmountDay();
		sum = vecStore[check].getSum();
		itoa(area, bufarea, 10);
		itoa(amountDay, bufAmount, 10);
		itoa(sum, bufe, 10);
		send(obj.GetNewConnection(), nameStore, sizeof(nameStore), 0);
		send(obj.GetNewConnection(), bufarea, sizeof(bufarea), 0);
		send(obj.GetNewConnection(), bufAmount, sizeof(bufAmount), 0);
		send(obj.GetNewConnection(), bufe, sizeof(bufe), 0);



	}
}

void User::Lease(int i, Server& obj)
{
	printf_infoStore(obj);
	int ch;
	char buf[100];
	recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if(ch ==-1 )
	{
	
	}
	else
	{
	if(vecHuman[i].getCash()<vecStore[ch].getSum())
	{
		int check = 1;
		char msg[100];
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	}
	else
	{
		int check = 0;
		char date[100];
		char msg[100];
		char name[100];
		char tel[100];
		char pas_indo[100];
		char password[100];
		char login[100];
		int cash;
		char nameExpert[100];
		char nameStore[100];
		int area;
		int amountDay;
		int sum;
		itoa(check, msg, 10);
		send(obj.GetNewConnection(), msg, sizeof(msg), 0);
		recv(obj.GetNewConnection(), date, sizeof(date), 0);
		Statistick stat;
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		strcpy_s(pas_indo, sizeof(pas_indo), vecHuman[i].getPas_info());
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
		strcpy_s(nameStore, sizeof(nameStore), vecStore[ch].getNameStore());
		area = vecStore[ch].getArea();
		amountDay = vecStore[ch].getAmountDay();
		sum = vecStore[ch].getSum();
		stat.setDate(date);
		stat.setName(name);
		stat.setPass_info(pas_indo);
		stat.setTel(tel);
		stat.setLogin(login);
		stat.setNamestore(nameStore);
		stat.setArea(area);
		stat.setAmountDay(amountDay);
		stat.setCash1(sum);
		vecHuman[i].setCash(vecHuman[i].getCash() - vecStore[ch].getSum());
		ofstream file(FileReport, ios::app);
		file << stat;
		file.close();
		seve_info_Client();
		cout << "Клиент - " << vecHuman[i].getName() << " Взял в аренду склад - " << vecStore[ch].getNameStore() << endl;
	}
	}
}

void User::Estimate(int i, Server& obj)
{
	int check = vecStore.size();
	if(check==0)
	{
		char cher[100];
		int a = 1;
		itoa(a, cher, 10);
		send(obj.GetNewConnection(), cher, sizeof(cher), 0);
	}
	else
	{
		char cher[100];
		int a = 0;
		itoa(a, cher, 10);
		send(obj.GetNewConnection(), cher, sizeof(cher), 0);
		int ch;
		char msg[100], nameExpert[100];
		printf_infoStore(obj);
		recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
		ch = atoi(msg);
		ch = ch - 1;
		int rate;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		rate = atoi(buf);
		Rating rat;
		rat.setRating(rate);
		rat.setPosition(ch);
		strcpy_s(nameExpert, sizeof(nameExpert), vecExpert[i].getName());
		rat.setNameExpert(nameExpert);
		vecRating.push_back(rat);
		save_infi_Rating();
		cout << "Expert - " << nameExpert << " поставил оценку складу " << vecStore[ch].getNameStore() << endl;
	}
}

void User::receptionUser(int i, Server& obj)
{
	User us;
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	strcpy_s(name, sizeof(name), vecHuman[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
	cash = vecHuman[i].getCash();
	itoa(cash, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
}

void User::receptionAdmin(int i, Server& obj)
{
	User uf;
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	strcpy_s(name, sizeof(name), vecAdmin[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
}

void User::receptionExpert(int i, Server& obj)
{
	User uf;
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	strcpy_s(name, sizeof(name), vecExpert[i].getName());
	send(obj.GetNewConnection(), name, sizeof(name), 0);
	strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
	send(obj.GetNewConnection(), tel, sizeof(tel), 0);
	strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
	send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
	strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
	send(obj.GetNewConnection(), login, sizeof(login), 0);
	strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
	send(obj.GetNewConnection(), password, sizeof(password), 0);
}

int User::AutorizationAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPassword(), pas) == 0)
		{
			char buf[100];
			char name[100];
			check++;
			itoa(check, buf, 10);
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			return i;
		}

	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
		return -1;
	}
}

void User::addClient(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecHuman.push_back(obj1);
	seve_info_Client();
	cout << "Новый пользователь был зарегестрирован!" << endl;
}

void User::addAdmin(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecAdmin.push_back(obj1);
	save_info_Admin();
	cout << "Новый Администратор был зарегестрирован!" << endl;
}

void User::addExpert(Server& obj)
{
	int check = 0;
	char msg[100];
	Human obj1;
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setName(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setTel(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPass_info(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setLogin(msg);
	recv(obj.GetNewConnection(), msg, sizeof(msg), 0);
	obj1.setPassword(msg);
	vecExpert.push_back(obj1);
	save_info_Expert();
	cout << "Новый Эксперт был зарегестрирован!" << endl;
}

void User::delClient(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			int cash = vecHuman[i].getCash();
			itoa(cash, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			auto res = vecHuman.begin();
			vecHuman.erase(res + i);
			seve_info_Client();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}

}

void User::delAdmin(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecAdmin.begin();
			vecAdmin.erase(res + i);
			save_info_Admin();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::delExpert(Server& obj)
{
	int check = 0;
	char log[100], pas[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), pas, sizeof(pas), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getPas_info(), pas) == 0)

		{
			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			auto res = vecExpert.begin();
			vecExpert.erase(res + i);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findUser(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		if (strcmp(vecHuman[i].getlogin(), log) == 0 && strcmp(vecHuman[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecHuman[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			seve_info_Client();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findAdmin(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		if (strcmp(vecAdmin[i].getlogin(), log) == 0 && strcmp(vecAdmin[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecAdmin[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Admin();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::findExpert(Server& obj)
{
	int check = 0;
	char log[100], tel[100];
	recv(obj.GetNewConnection(), log, sizeof(log), 0);
	recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		if (strcmp(vecExpert[i].getlogin(), log) == 0 && strcmp(vecExpert[i].getTel(), tel) == 0)
		{

			char buf[100];
			check++;
			itoa(check, buf, 10);
			send(obj.GetNewConnection(), buf, sizeof(buf), 0);
			char name[100], tel[100], pas_info[100], login[100], password[100];
			strcpy_s(name, sizeof(name), vecExpert[i].getName());
			send(obj.GetNewConnection(), name, sizeof(name), 0);
			strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
			send(obj.GetNewConnection(), tel, sizeof(tel), 0);
			strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
			send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
			send(obj.GetNewConnection(), login, sizeof(login), 0);
			strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
			send(obj.GetNewConnection(), password, sizeof(password), 0);
			save_info_Expert();
		}
	}
	if (check == 0)
	{
		char error[100];
		itoa(check, error, 10);
		send(obj.GetNewConnection(), error, sizeof(error), 0);
	}
}

void User::printf_infoPromiser(Server& obj)
{
	int size = vecCredit.size();
	char msg[100];
	itoa(size, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	for (int i = 0; i < vecCredit.size(); i++)
	{
		char date[100];
		char name[100];
		char tel[100], buf[100];
		char pas_indo[100];
		int sumcredit;
		strcpy_s(date, sizeof(date), vecCredit[i].getDate());
		strcpy_s(name, sizeof(name), vecCredit[i].getName());
		strcpy_s(pas_indo, sizeof(pas_indo), vecCredit[i].getPas_info());
		strcpy_s(tel, sizeof(tel), vecCredit[i].getTel());
		sumcredit = vecCredit[i].getSumcredit();
		itoa(sumcredit, buf, 10);
		send(obj.GetNewConnection(), date, sizeof(date), 0);
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		send(obj.GetNewConnection(), pas_indo, sizeof(pas_indo), 0);
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
}

void User::printf_infoStore(Server& obj)
{
	int size = vecStore.size();
	char msg[100];
	itoa(size, msg, 10);
	send(obj.GetNewConnection(), msg, sizeof(msg), 0);
	for(int i=0;i<vecStore.size();i++)
	{
		char nameStore[100], bufarea[100], bufAmount[100], buf[100];
		int area;
		int amountDay;
		int sum;
		strcpy_s(nameStore, sizeof(nameStore), vecStore[i].getNameStore());
		area = vecStore[i].getArea();
		amountDay = vecStore[i].getAmountDay();
		sum = vecStore[i].getSum();
		itoa(area, bufarea, 10);
		itoa(amountDay, bufAmount, 10);
		itoa(sum, buf, 10);
		send(obj.GetNewConnection(), nameStore, sizeof(nameStore), 0);
		send(obj.GetNewConnection(), bufarea, sizeof(bufarea), 0);
		send(obj.GetNewConnection(), bufAmount, sizeof(bufAmount), 0);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}

}

void User::printf_infoClient(Server& obj)
{
	char buf[100];
	int size;
	size = vecHuman.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecHuman.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], buf[100];
		int cash;
		strcpy_s(name, sizeof(name), vecHuman[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecHuman[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecHuman[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecHuman[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecHuman[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
		cash = vecHuman[i].getCash();
		itoa(cash, buf, 10);
		send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	}
}

void User::printf_infoAdmin(Server& obj)
{
	char buf[100];
	int size;
	size = vecAdmin.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecAdmin.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecAdmin[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecAdmin[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecAdmin[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecAdmin[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecAdmin[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::printf_infoExpert(Server& obj)
{
	char buf[100];
	int size;
	size = vecExpert.size();
	itoa(size, buf, 10);
	send(obj.GetNewConnection(), buf, sizeof(buf), 0);
	for (int i = 0; i < vecExpert.size(); i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100];
		float cash;
		strcpy_s(name, sizeof(name), vecExpert[i].getName());
		send(obj.GetNewConnection(), name, sizeof(name), 0);
		strcpy_s(tel, sizeof(tel), vecExpert[i].getTel());
		send(obj.GetNewConnection(), tel, sizeof(tel), 0);
		strcpy_s(pas_info, sizeof(pas_info), vecExpert[i].getPas_info());
		send(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
		strcpy_s(login, sizeof(login), vecExpert[i].getlogin());
		send(obj.GetNewConnection(), login, sizeof(login), 0);
		strcpy_s(password, sizeof(password), vecExpert[i].getPassword());
		send(obj.GetNewConnection(), password, sizeof(password), 0);
	}
}

void User::seve_info_Client()
{
	FileCreator obj;
	obj.write_vector_Account(vecHuman,FileClient);
}

void User::save_info_Admin()
{
	FileCreator obj;
	obj.write_vector_Account(vecAdmin,FileAdmin);
}

void User::save_info_Expert()
{
	FileCreator obj;
	obj.write_vector_Account(vecExpert,FileExpert);
}

void User::save_info_Store()
{
	FileCreator obj;
	obj.write_vector_Store(vecStore, FileStore);
}

void User::save_infi_Rating()
{
	FileCreator obj;
	obj.write_vector_Rating(vecRating,FileRating);
}

void User::save_info_credit()
{
	FileCreator obj;
	obj.write_vector_credit(vecCredit, FileCredit);
}
