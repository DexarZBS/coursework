#include "Function.h"

void checkImput(int a)
{
	while (true)
	{
		if (!cin)
		{
			cout << "������� ����� !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}



int checkName(char* a)
{
	for(int i=0;i<strlen(a);i++)
	{
	if(isalpha(a[i])==0)
	{
		cout << "��� �� ����� ��������� ����� !!" << endl;
		return 1;
	}
	}
}

int checkTel(char* a)
{
	for(int i=0;i<strlen(a);i++)
	{
	if(isdigit(a[i])==0)
	{
		cout << "� ����� �������� ������ ��������� ������� " << endl;
		return 1;
	}
	}
}

int checkDate(char* a)
{
	char help[2] = { "." };
	for(int i=0;i<strlen(a);i++)
	{
		if(i==3 || i==6)
		{
			a[i] = help[1];
		}
		if(isdigit(a[i])==0 && i!=3 && i!=6)
		{
			cout << "����������� ���� ���� ! ������� 14 12 2000" << endl;
			return 1;
		}
	}
}

void replenish_credit(Server& obj)
{
	receptionUserCredit(obj);
	cout << "�������� ������ �� �������� ������ ��������� :" << endl;
	cout << "��� ������ ������� 0";
	int ch;
	cin >> ch;
	checkImput(ch);
	if(ch==0)
	{
		char b[100];
		itoa(ch, b, 10);
		send(obj.getConnetc(), b, sizeof(b), 0);
	}
	else
	{
		char b[100];
		itoa(ch, b, 10);
		send(obj.getConnetc(), b, sizeof(b), 0);
		cout << "������� ����� ��� ������ :";
		int sum;
		cin >> sum;
		checkImput(sum);
		char buf[100];
		itoa(sum, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		int eror ;
		char error[100];
		recv(obj.getConnetc(), error, sizeof(error), 0);
		eror = atoi(error);
		if(eror==1)
		{
			cout << "������������ ������ �� ����� " << endl;
		}
		else
		{
			int check;
			char bur[100];
			recv(obj.getConnetc(), bur, sizeof(bur), 0);
			check = atoi(bur);
			if (check == 1)
			{
				int sum;
				char sum1[100];
				recv(obj.getConnetc(), sum1, sizeof(sum1), 0);
				sum = atoi(sum1);
				cout << "������� �� ������� ���������� : " << sum << endl;
			}
			if (check == 2)
			{
				int sum;
				char sum1[100];
				recv(obj.getConnetc(), sum1, sizeof(sum), 0);
				sum = atoi(sum1);
				cout << "������� � ������� : " << sum << " ����� ��������� �� ��� ���� " << endl;
			}
			if (check == 3)
			{
				cout << "�� �������� ������ " << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void receptionUserCredit(Server& obj)
{
	system("cls");
	int ch;
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if(ch==0)
	{
		cout << "� ��� ��� �������� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		char name[100], tel[100], pas_info[100], date[100], buf[100];
		int sum;
		recv(obj.getConnetc(), date, sizeof(date), 0);
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		sum = atoi(buf);
		cout << "���� ���������� : " << date << endl;
		cout << "��� �������� : " << name << endl;
		cout << "���������� ������ �������� : " << pas_info << endl;
		cout << "����� �������� �������� : " << tel << endl;
		cout << "����� ������� : " << sum << endl;
	}
}

void rentCredit(Server& obj)
{
	PrintfInfoStore(obj);
	cout << "�������� ������ ����� " << endl;
	cout << "��� ������ ������� 0 " << endl;
	int ch;
	cin >> ch;
	checkImput(ch);
	if (ch == 0)
	{
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
	}
	else
	{
		ch = ch - 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		cout << "������� ����������� ���� : ";
			char date[100];
			cin >> date;
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "������ ������� �������� !" << endl;
			system("pause");
			system("cls");
	}
}

void replenish_account(Server& obj)
{
	system("cls");
	cout << "���� ���������� ����� >>" << endl;
	cout << "������� ����� : ";
	int sum;
	cin >> sum;
	checkImput(sum);
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ������ ������� !" << endl;
}

void rent(Server& obj)
{
	
	int size = PrintfInfoStore(obj);
	int ch;
	while(true)
	{
		cout << "�������� ������ ����� " << endl;
		cout << "��� ������ ������� 0 " << endl;
		cin >> ch;
		checkImput(ch);
		if (ch > size || ch < 0)
		{
			cout << "��� ������ �������� ���������� ��� ���" << endl;
		}
		else
		{
			break;
		}
	}
	if(ch==0)
	{
		ch = -1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
	}
	else
	{
		ch = ch - 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		if(ch==1)
		{
			cout << "������������ ������� " << endl;
			system("pause");
			system("cls");
		}
		else 
		{
			system("cls");
			char date[100];
				cout << "������� ����������� ���� : ";
				cin >> date;
				int check=checkDate(date);
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "������ ������ ��������� !" << endl;
			system("pause");
			system("cls");
		}
	}
}

void ExpertOpinion(Server& obj)
{
	int ch;
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 1)
	{
		cout << "��� �� ����� ������ ��� ��� �� ������ ���������� ������  " << endl;
	}
	if (ch == 2)
	{
		cout << "�� ��� ������ �������� ������ !" << endl;
	}
	if (ch == 0)
	{
		cout << "������ ����� �� ������ ��������� : " << endl;
		char nameStore[100], bufarea[100], bufAmount[100], buf[100];
		int area;
		int amountDay;
		int sum;
		recv(obj.getConnetc(), nameStore, sizeof(nameStore), 0);
		recv(obj.getConnetc(), bufarea, sizeof(bufarea), 0);
		recv(obj.getConnetc(), bufAmount, sizeof(bufAmount), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		area = atoi(bufarea);
		amountDay = atoi(bufAmount);
		sum = atoi(buf);
		cout << "�������� ������ : " << nameStore << endl;
		cout << "������� ������ : " << area << endl;
		cout << "���-�� ���� ������ : " << amountDay << endl;
		cout << "��������� : " << sum << endl;
		system("pause");
		system("cls");
	}
}

void rate(Server& obj)
{
	system("cls");
	char cher[100];
	recv(obj.getConnetc(), cher, sizeof(cher), 0);
	int a = atoi(cher);
	if(a==1)
	{
		cout << "��� ��������� ������� " << endl;
	}
	else
	{
		int ch;
		char msg[100];
		int rate;
		char buf[100];
		cout << "���� ����������� ������ >>" << endl;
		PrintfInfoStore(obj);
		cout << "�������� ������ ����� " << endl;
		cin >> ch;
		checkImput(ch);
		itoa(ch, msg, 10);
		send(obj.getConnetc(), msg, sizeof(msg), 0);
		cout << "������� ������ �� 1 �� 10 " << endl;
		while (true)
		{
			cin >> rate;
			checkImput(rate);
			if (rate < 1 && rate>10)
			{
				cout << "������� ������ � ��������� �� 1 �� 10" << endl;
			}
			else
			{
				break;
			}
		}
		itoa(rate, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		cout << "������ ��������� !" << endl;
		system("pause");
	}
}

void addStore(Server& obj)
{
	system("cls");
	char nameStore[100], bufarea[100], bufAmount[100], buf[100];
	float area;
	float amountDay;
	int sum;
	cout << "���� ���������� ������ >>" << endl;
	cout << "������� �������� ������ : ";
	cin >> nameStore;
	send(obj.getConnetc(), nameStore, sizeof(nameStore), 0);
	cout << "������� ������� ������ : ";
	cin >> area;
	checkImput(area);
	itoa(area, bufarea, 10);
	send(obj.getConnetc(), bufarea, sizeof(bufarea), 0);
	cout << "������� ���-�� ���� ������ : ";
	cin >> amountDay;
	checkImput(amountDay);
	itoa(amountDay, bufAmount, 10);
	send(obj.getConnetc(), bufAmount, sizeof(bufAmount), 0);
	cout << "����� ��� �������� ������� !" << endl;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	cout <<setw(15)<< "����� = " << sum << endl;
	cout << setw(15) << "���-�� ���� ������ = " << amountDay << endl;
	system("pause");

}

void addAccount(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "����������>>" << endl;
	while(true)
	{
		cout << "���� ��� :";
		cin >> buf;
		int check=checkName(buf);
		if(check!=1)
		{
			break;
		}
	}
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	while(true)
	{
		cout << "��� ����� �������� : +375";
		cin >> buf;
		int check = checkTel(buf);
		if(check!=1)
		{
			break;
		}
	}
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "��� ���������� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "���������� ���� ������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "����������� ������ ������� " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		system("cls");
		cout << "��� ������ ������������� " << endl;
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� " << name << ":)" << endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "���� ����������� >>" << endl;
	cout << "����� : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "������ : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		system("cls");
		cout << "��� ������ ��������������  " << endl;
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "����� ���������� ������������� " << name << ":)" << endl;
	}
}

int PrintfInfoStore(Server& obj)
{
	int size;
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	cout.setf(ios::right);
	cout  << "�" << setw(16) << "��������" << setw(17) << "�������" << setw(20) << "���-�� ����" << setw(20) << "����� � ������ " << endl;
	for(int i=0;i<size;i++)
	{
		char nameStore[100], bufarea[100], bufAmount[100], buf[100];
		int area;
		int amountDay;
		int sum;
		recv(obj.getConnetc(), nameStore, sizeof(nameStore), 0);
		recv(obj.getConnetc(), bufarea, sizeof(bufarea), 0);
		recv(obj.getConnetc(), bufAmount, sizeof(bufAmount), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		area = atoi(bufarea);
		amountDay = atoi(bufAmount);
		sum = atoi(buf);
		cout  << "�" << i + 1<< setw(16) << nameStore << setw(17) << area << setw(20) << amountDay << setw(20) << sum << endl;
	}
	cout.unsetf(ios::right);
	return size;
}

void Printf_infoPromiser(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout.setf(ios::right);
	cout << setw(10) << "���" << setw(20) << "����� ��������" << setw(20) << "���������� �." << setw(20) << "����� ������� " << setw(20) << "���� ����������" << endl;
	for(int i=0;i<size;i++)
	{

		char name[100], tel[100], pas_info[100], date[100], buf[100];
		int sum;
		recv(obj.getConnetc(), date, sizeof(date), 0);
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		sum = atoi(buf);
		cout << setw(10) << name << setw(20) << tel << setw(20) << pas_info << setw(15) << sum << setw(25) << date << endl;
	}
	cout.unsetf(ios::right);
	system("pause");
	system("cls");
}

void PrintfInfoAdminExpert(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout.setf(ios::right);
	cout << setw(10) << "���" << setw(20) << "����� ��������" << setw(20) << "���������� �." << setw(10) << "�����" << setw(10) << "������" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << setw(10) << name << setw(20) << tel << setw(20) << pas_info << setw(10) << login << setw(10) << password << endl;
	}
	cout.unsetf(ios::right);
	system("pause");
	system("cls");
}

void PrintfInfoClient(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout.setf(ios::right);
	cout << setw(10) <<"���" << setw(20) << "����� ��������" << setw(20) << "���������� �."<<setw(10) << "�����" <<setw(10)<< "������" << setw(20) << "����� �� �����" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << setw(10) << name << setw(20) << tel  << setw(20) << pas_info  << setw(10) << login  <<setw(10)<< password  << setw(20) << cash << endl;
	}
	cout.unsetf(ios::right);
	system("pause");
	system("cls");
}

void DelClient(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� ������������ " << endl;
	cout << "������� ����� ������������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "������������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "��������� �������� : " << cash << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������������� " << endl;
	cout << "������� ����� ������ : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ ������������ ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�����:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "���� �������� �������� " << endl;
	cout << "������� ����� : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ���������� ������ : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		cout << "������!" << endl;
		system("pause");
		system("cls");
	}
}

void findAccount(Server& obj)
{
	system("cls");
	cout << "���� ������ >>" << endl;
	cout << "������� ����� �������� : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "������� ����� �������� :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "������ �������� ��� " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���������� ������:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "��� : " << name << endl;
		cout << "����� �������� : " << tel << endl;
		cout << "���������� ������ : " << pas_info << endl;
		cout << "����� : " << login << endl;
		cout << "������ : " << password << endl;
		system("pause");
		system("cls");
	}
}

