#include "Menu.h"

void Menu::AutorizationCheck(int check,Server &connectoin)
{
	if(check==-1)
	{
		startMenu(connectoin);
	}
	else
	{
	
	}
}

void Menu::MenuChangeUser(Server& obj, int i, User& user)
{
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1: char name[100], nam[100];
			strcpy_s(nam, sizeof(nam), vecHuman[i].getName());
			recv(obj.GetNewConnection(), name, sizeof(name), 0);
			vecHuman[i].setName(name);
			cout << "User-" << nam << " Изменил имя на - " << name << endl;
			FileCreator file;
			file.write_vector_Account(vecHuman, FileClient);
			break;
		case 2:
			char pas_info[100], pas[100], na[100];
			strcpy_s(na, sizeof(na), vecHuman[i].getName());
			strcpy_s(pas, sizeof(pas), vecHuman[i].getPas_info());
			recv(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			vecHuman[i].setPass_info(pas_info);
			cout << "User - " << na << " Изменил паспортные с - " << pas << " На - " << pas_info << endl;
			FileCreator f;
			file.write_vector_Account(vecHuman, FileClient);
			break;
		case 3:
			char tel[100], t[100], names[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(t, sizeof(t), vecHuman[i].getTel());
			recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
			vecHuman[i].setTel(tel);
			cout << "User - " << names << " Изменил номер телефона с - +375" << t << " На - +375" << tel << endl;
			FileCreator fi;
			file.write_vector_Account(vecHuman, FileClient);
			break;
		case 4:
			char login[100], log[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(log, sizeof(log), vecHuman[i].getlogin());
			recv(obj.GetNewConnection(), login, sizeof(login), 0);
			vecHuman[i].setLogin(login);
			cout << "User - " << names << " Изменил login с - " << log << " На - " << login << endl;
			file.write_vector_Account(vecHuman, FileClient);
			break;
		case 5:
			char password[100], pass[100];
			strcpy_s(names, sizeof(names), vecHuman[i].getName());
			strcpy_s(pass, sizeof(pass), vecHuman[i].getPassword());
			recv(obj.GetNewConnection(), password, sizeof(password), 0);
			vecHuman[i].setPassword(password);
			cout << "User - " << names << " Изменил Password с - " << pass << " На - " << password << endl;
			file.write_vector_Account(vecHuman, FileClient);
			break;
		case 6:UserMenu(obj, i, user); break;
		}
	}
}

void Menu::MenuChangeAdmin(Server& obj, int i, User& user)
{
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1: char name[100], nam[100];
			strcpy_s(nam, sizeof(nam), vecAdmin[i].getName());
			recv(obj.GetNewConnection(), name, sizeof(name), 0);
			vecAdmin[i].setName(name);
			cout << "Admin-" << nam << " Изменил имя на - " << name << endl;
			FileCreator file;
			file.write_vector_Account(vecAdmin, FileAdmin);
			break;
		case 2:
			char pas_info[100], pas[100], na[100];
			strcpy_s(na, sizeof(na), vecAdmin[i].getName());
			strcpy_s(pas, sizeof(pas), vecAdmin[i].getPas_info());
			recv(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			vecAdmin[i].setPass_info(pas_info);
			cout << "Admin - " << na << " Изменил паспортные с - " << pas << " На - " << pas_info << endl;
			FileCreator f;
			file.write_vector_Account(vecAdmin,FileAdmin);
			break;
		case 3:
			char tel[100], t[100], names[100];
			strcpy_s(names, sizeof(names), vecAdmin[i].getName());
			strcpy_s(t, sizeof(t), vecAdmin[i].getTel());
			recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
			vecAdmin[i].setTel(tel);
			cout << "Admin - " << names << " Изменил номер телефона с - +375" << t << " На - +375" << tel << endl;
			FileCreator fi;
			file.write_vector_Account(vecAdmin,FileAdmin);
			break;
		case 4:
			char login[100], log[100];
			strcpy_s(names, sizeof(names), vecAdmin[i].getName());
			strcpy_s(log, sizeof(log), vecAdmin[i].getlogin());
			recv(obj.GetNewConnection(), login, sizeof(login), 0);
			vecAdmin[i].setLogin(login);
			cout << "Admin - " << names << " Изменил login с - " << log << " На - " << login << endl;
			fi.write_vector_Account(vecAdmin,FileAdmin);
			break;
		case 5:
			char password[100], pass[100];
			strcpy_s(names, sizeof(names), vecAdmin[i].getName());
			strcpy_s(pass, sizeof(pass), vecAdmin[i].getPassword());
			recv(obj.GetNewConnection(), password, sizeof(password), 0);
			vecAdmin[i].setPassword(password);
			cout << "Admin - " << names << " Изменил Password с - " << pass << " На - " << password << endl;
			fi.write_vector_Account(vecAdmin,FileAdmin);
			break;
		case 6:AdminMenu(obj, i, user); break;
		}
	}
}

void Menu::MenuChangeExpert(Server& obj, int i, User& user)
{
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1: char name[100], nam[100];
			strcpy_s(nam, sizeof(nam), vecExpert[i].getName());
			recv(obj.GetNewConnection(), name, sizeof(name), 0);
			vecExpert[i].setName(name);
			cout << "Expert -" << nam << " Изменил имя на - " << name << endl;
			FileCreator file;
			file.write_vector_Account(vecExpert, FileExpert);
			break;
		case 2:
			char pas_info[100], pas[100], na[100];
			strcpy_s(na, sizeof(na), vecExpert[i].getName());
			strcpy_s(pas, sizeof(pas), vecExpert[i].getPas_info());
			recv(obj.GetNewConnection(), pas_info, sizeof(pas_info), 0);
			vecExpert[i].setPass_info(pas_info);
			cout << "Expert - " << na << " Изменил паспортные с - " << pas << " На - " << pas_info << endl;
			FileCreator f;
			file.write_vector_Account(vecExpert, FileExpert);
			break;
		case 3:
			char tel[100], t[100], names[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(t, sizeof(t), vecExpert[i].getTel());
			recv(obj.GetNewConnection(), tel, sizeof(tel), 0);
			vecExpert[i].setTel(tel);
			cout << "Expert - " << names << " Изменил номер телефона с - +375" << t << " На - +375" << tel << endl;
			FileCreator fi;
			file.write_vector_Account(vecExpert, FileExpert);
			break;
		case 4:
			char login[100], log[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(log, sizeof(log), vecExpert[i].getlogin());
			recv(obj.GetNewConnection(), login, sizeof(login), 0);
			vecExpert[i].setLogin(login);
			cout << "Admin - " << names << " Изменил login с - " << log << " На - " << login << endl;
			fi.write_vector_Account(vecExpert, FileExpert);
			break;
		case 5:
			char password[100], pass[100];
			strcpy_s(names, sizeof(names), vecExpert[i].getName());
			strcpy_s(pass, sizeof(pass), vecExpert[i].getPassword());
			recv(obj.GetNewConnection(), password, sizeof(password), 0);
			vecExpert[i].setPassword(password);
			cout << "Admin - " << names << " Изменил Password с - " << pass << " На - " << password << endl;
			fi.write_vector_Account(vecExpert, FileExpert);
			break;
		case 6:ExpertMenu(obj, i, user); break;
		}
	}
}

void Menu::startMenu(Server& obj)
{
	while (1)
	{
		int var;
		Menu Menu;
		User user;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:user.addClient(obj); break;
		case 2:var = user.AutorizationClient(obj); AutorizationCheck(var,obj); UserMenu(obj, var, user);  break;
		case 3:var = user.AutorizationAdmin(obj); AutorizationCheck(var, obj); AdminMenu(obj, var, user); break;
		case 4:var = user.AutorizationExpert(obj); AutorizationCheck(var, obj); ExpertMenu(obj, var, user); break;
		case 5:exit(1);
		}
	}
}

void Menu::AdminMenu(Server& obj, int i, User& user)
{
	while (true)
	{
		User a;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:a.printf_infoClient(obj); break;
		case 2:a.printf_infoAdmin(obj); break;
		case 3:a.printf_infoExpert(obj); break;
		case 4:a.findUser(obj); break;
		case 5:a.findAdmin(obj); break;
		case 6:a.findExpert(obj); break;
		case 7:a.delClient(obj); break;
		case 8:a.delAdmin(obj); break;
		case 9:a.delExpert(obj); break;
		case 10:a.addAdmin(obj); break;
		case 11:a.addExpert(obj); break;
		case 12:a.receptionAdmin(i, obj); break;
		case 13:MenuChangeAdmin(obj, i, user); break;
		case 14:user.printf_infoPromiser(obj); break;
		case 15:startMenu(obj); break;
		}
	}
}

void Menu::UserMenu(Server& obj, int i, User& user)
{
	while (true)
	{
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:user.Lease(i, obj); break;
		case 2:user.leaseCredit(obj,i); break;
		case 3:user.replenish_account(obj, i); break;
		case 4:user.replenish_account(obj, i); break;
		case 6:ExpertReview(obj, i); break;
		case 5:replenish_account(obj, i); break;
		case 7:receptionUser(i, obj); break;
		case 8:MenuChangeUser(obj, i, user); break;
		case 9:user.receptionUserCredit(obj, i); break;
		case 10:startMenu(obj);
		}
		
	}
}

void Menu::ExpertMenu(Server& obj, int i, User& user)
{
	while (true)
	{
		User a;
		char buf[100];
		int ch;
		recv(obj.GetNewConnection(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		switch (ch)
		{
		case 1:a.addStore(obj, i); break;
		case 2:a.Estimate(i, obj); break;
		case 3:receptionExpert(i, obj); break;
		case 4:MenuChangeExpert(obj, i, user); break;
		case 5:a.printf_infoStore(obj); break;
		case 6:startMenu(obj);
		}
	}
}

