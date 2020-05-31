#include"Menu.h"
void Menu::displayAccount(Server& obj)
{
	cout << "Login аккаунта : ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "###########################################################" << endl;
	cout << "Ваши персональные данные: " << endl;
	cout << "Имя : " << name << endl;
	cout << "Номер телефона : " << tel << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");
}
void Menu::displayClient(Server& obj)
{
	cout << "Login аккаунта : ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	int cash;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cash = atoi(msg);
	cout << "###########################################################" << endl;
	cout << "Ваши персональные данные: " << endl;
	cout << "Имя : " << name << endl;
	cout << "Номер телефона : " << tel << endl;
	cout << "Паспортные данные : " << pas_info << endl;
	cout << "Состояние кошелька : " << cash << endl;
	cout << "Логин : " << login << endl;
	cout << "Пороль : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");

}

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "Ошибка выбора варианта ,повторит попытку !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}
void Menu::MenuChangeAdmin(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuAdmin(obj);
		}
	}
}
void Menu::MenuChangeUser(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuUser(obj);
		}
	}
}
void Menu::MenuChangeExpert(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Вы берите нужный параметр >>" << endl;
		cout << "1)Имя" << endl;
		cout << "2)Паспотрные данные " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин" << endl;
		cout << "5)Пороль" << endl;
		cout << "6)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новые паспортные данные :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новые телефон :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый Логин : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пороль : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "данные успешно изменены успешно изменено !!" << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuExpert(obj);
		}
	}
}
void Menu::startMenu(Server& Connection)
{
	while (1)
	{
		char buf[100];
		int ch;
		cout << "1)Регистрация " << endl;
		cout << "2)Авторизация " << endl;
		cout << "3)Войти как администратор" << endl;
		cout << "4)Войти как эксперт " << endl;
		cout << "5)выход" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addAccount(Connection); break;
		case 2:AutorizationUser(Connection); MenuUser(Connection); system("cls"); break;
		case 3:AutorizationAdmin(Connection); 	MenuAdmin(Connection); system("cls"); break;
		case 4:AutorizationUser(Connection); MenuExpert(Connection); system("cls"); break;
		case 5:exit(1);
		}
	}
}

void Menu::MenuUser(Server& Connection)
{
	while (true)
	{
		cout << "1)Арендовать склад " << endl;
		cout << "2)Арендовать в кредит " << endl;
		cout << "3)Взять обешанный платеж" << endl;
		cout << "4)пополнить счет" << endl;
		cout << "5)погасить обещанный платеж " << endl;
		cout << "6)Мнение экспертов " << endl;
		cout << "7)параметры аккаунта " << endl;
		cout << "8)изменить параметры аккаунта" << endl;
		cout << "9)ифно о ваших кредитах " << endl;
		cout << "10)выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:rent(Connection); break;
		case 2:rentCredit(Connection); break;
		case 3:replenish_account(Connection); break;
		case 4:replenish_account(Connection); break;
		case 5:replenish_account(Connection); break;
		case 6:ExpertOpinion(Connection); break;
		case 7:displayClient(Connection); break;
		case 8:MenuChangeUser(Connection); break;
		case 9:receptionUserCredit(Connection); break;
		case 10:startMenu(Connection); break;
		}
	}
}

void Menu::MenuAdmin(Server& Connection)
{
	while(true)
	{
		cout << "1)Вывод информации о всех клиентах" << endl;
		cout << "2)Вывод информации о всех Администраторах " << endl;
		cout << "3)Выво информации о всех Экспертах " << endl;
		cout << "4)Найти клиента " << endl;
		cout << "5)Найти администратора" << endl;
		cout << "6)Найти эксперта " << endl;
		cout << "7)Удалить аккаунт клиента " << endl;
		cout << "8)Удалить аккаунт администратора " << endl;
		cout << "9)Удалить аккаунт эксперта " << endl;
		cout << "10)Добавить Админа " << endl;
		cout << "11)Добавить экесперта " << endl;
		cout << "12)Параметры данного аккаунта " << endl;
		cout << "13)Изменить параметры данного аккаунта" << endl;
		cout << "14)Список должников по кредитам " << endl;
		cout << "15)Выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:PrintfInfoClient(Connection); break;
		case 2:PrintfInfoAdminExpert(Connection); break;
		case 3:PrintfInfoAdminExpert(Connection); break;
		case 4:findAccount(Connection); break;
		case 5:findAccount(Connection); break;
		case 6:findAccount(Connection); break;
		case 7:DelClient(Connection); break;
		case 8:DelAdmin(Connection); break;
		case 9:DelExpert(Connection); break;
		case 10:addAccount(Connection); break;
		case 11:addAccount(Connection); break;
		case 12:displayAccount(Connection); break;
		case 13:MenuChangeAdmin(Connection); break;
		case 14:Printf_infoPromiser(Connection); break;
		case 15:startMenu(Connection);
		}
	}
}

void Menu::MenuExpert(Server& Connection)
{
	while (true)
	{

		cout << "1)Добавить склад " << endl;
		cout << "2)Добавить оценку " << endl;
		cout << "3)Параметры аккаунта " << endl;
		cout << "4)Изменить параметры аккаунта " << endl;
		cout << "5)Вывод всех доступных складов " << endl;
		cout << "6)Выход" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addStore(Connection); break;
		case 2:rate(Connection); break;
		case 3:displayAccount(Connection); break;
		case 4:MenuChangeExpert(Connection); break;
		case 5:PrintfInfoStore(Connection); break;
		case 6:startMenu(Connection);
		}
	}
}

