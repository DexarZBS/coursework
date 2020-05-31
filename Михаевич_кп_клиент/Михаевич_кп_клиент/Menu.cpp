#include"Menu.h"
void Menu::displayAccount(Server& obj)
{
	cout << "Login �������� : ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	float cash;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << login << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "###########################################################" << endl;
	cout << "���� ������������ ������: " << endl;
	cout << "��� : " << name << endl;
	cout << "����� �������� : " << tel << endl;
	cout << "���������� ������ : " << pas_info << endl;
	cout << "����� : " << login << endl;
	cout << "������ : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");
}
void Menu::displayClient(Server& obj)
{
	cout << "Login �������� : ";
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
	cout << "���� ������������ ������: " << endl;
	cout << "��� : " << name << endl;
	cout << "����� �������� : " << tel << endl;
	cout << "���������� ������ : " << pas_info << endl;
	cout << "��������� �������� : " << cash << endl;
	cout << "����� : " << login << endl;
	cout << "������ : " << password << endl;
	cout << "###########################################################" << endl;
	system("pause");

}

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "������ ������ �������� ,�������� ������� !" << endl;
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
		cout << "�� ������ ������ �������� >>" << endl;
		cout << "1)���" << endl;
		cout << "2)���������� ������ " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)�����" << endl;
		cout << "5)������" << endl;
		cout << "6)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ��� :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ���������� ������ :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ������� :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������ : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
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
		cout << "�� ������ ������ �������� >>" << endl;
		cout << "1)���" << endl;
		cout << "2)���������� ������ " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)�����" << endl;
		cout << "5)������" << endl;
		cout << "6)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ��� :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ���������� ������ :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ������� :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������ : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
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
		cout << "�� ������ ������ �������� >>" << endl;
		cout << "1)���" << endl;
		cout << "2)���������� ������ " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)�����" << endl;
		cout << "5)������" << endl;
		cout << "6)�����" << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ��� :";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ���������� ������ :";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ������� :+375";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������ : ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� �������� ������� �������� !!" << endl;
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
		cout << "1)����������� " << endl;
		cout << "2)����������� " << endl;
		cout << "3)����� ��� �������������" << endl;
		cout << "4)����� ��� ������� " << endl;
		cout << "5)�����" << endl;
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
		cout << "1)���������� ����� " << endl;
		cout << "2)���������� � ������ " << endl;
		cout << "3)����� ��������� ������" << endl;
		cout << "4)��������� ����" << endl;
		cout << "5)�������� ��������� ������ " << endl;
		cout << "6)������ ��������� " << endl;
		cout << "7)��������� �������� " << endl;
		cout << "8)�������� ��������� ��������" << endl;
		cout << "9)���� � ����� �������� " << endl;
		cout << "10)�����" << endl;
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
		cout << "1)����� ���������� � ���� ��������" << endl;
		cout << "2)����� ���������� � ���� ��������������� " << endl;
		cout << "3)���� ���������� � ���� ��������� " << endl;
		cout << "4)����� ������� " << endl;
		cout << "5)����� ��������������" << endl;
		cout << "6)����� �������� " << endl;
		cout << "7)������� ������� ������� " << endl;
		cout << "8)������� ������� �������������� " << endl;
		cout << "9)������� ������� �������� " << endl;
		cout << "10)�������� ������ " << endl;
		cout << "11)�������� ��������� " << endl;
		cout << "12)��������� ������� �������� " << endl;
		cout << "13)�������� ��������� ������� ��������" << endl;
		cout << "14)������ ��������� �� �������� " << endl;
		cout << "15)�����" << endl;
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

		cout << "1)�������� ����� " << endl;
		cout << "2)�������� ������ " << endl;
		cout << "3)��������� �������� " << endl;
		cout << "4)�������� ��������� �������� " << endl;
		cout << "5)����� ���� ��������� ������� " << endl;
		cout << "6)�����" << endl;
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

