#include "Function.h"

void checkImput(int a)
{
	while (true)
	{
		if (!cin)
		{
			cout << "Введите цифру !" << endl;
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
		cout << "Имя не может содержать цифры !!" << endl;
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
		cout << "В номер телефона нельзя поместить символы " << endl;
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
			cout << "Непрвильный ввод даты ! Введите 14 12 2000" << endl;
			return 1;
		}
	}
}

void replenish_credit(Server& obj)
{
	receptionUserCredit(obj);
	cout << "Выберите кредит по которому хотите заплатить :" << endl;
	cout << "Для выхода нажмите 0";
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
		cout << "Введитк сумму для оплаты :";
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
			cout << "Недостаточно средст на счете " << endl;
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
				cout << "Остаток по кредиту составляет : " << sum << endl;
			}
			if (check == 2)
			{
				int sum;
				char sum1[100];
				recv(obj.getConnetc(), sum1, sizeof(sum), 0);
				sum = atoi(sum1);
				cout << "Остаток в размере : " << sum << " Будет переведен на ваш счет " << endl;
			}
			if (check == 3)
			{
				cout << "Вы погасили кредит " << endl;
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
		cout << "У вас нет кредитов " << endl;
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
		cout << "Дата оформления : " << date << endl;
		cout << "Имя заемщика : " << name << endl;
		cout << "Паспортные даннык заемщика : " << pas_info << endl;
		cout << "Номер телефона заемщика : " << tel << endl;
		cout << "Сумаа кредита : " << sum << endl;
	}
}

void rentCredit(Server& obj)
{
	PrintfInfoStore(obj);
	cout << "Выберите нужный склад " << endl;
	cout << "Для выхода нажмите 0 " << endl;
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
		cout << "Введите сегодняшнюю дату : ";
			char date[100];
			cin >> date;
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "Кредит успешно оформлен !" << endl;
			system("pause");
			system("cls");
	}
}

void replenish_account(Server& obj)
{
	system("cls");
	cout << "Меню пополнения счета >>" << endl;
	cout << "Введите сумму : ";
	int sum;
	cin >> sum;
	checkImput(sum);
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Транзакция прошла успешно !" << endl;
}

void rent(Server& obj)
{
	
	int size = PrintfInfoStore(obj);
	int ch;
	while(true)
	{
		cout << "Выберите нужный склад " << endl;
		cout << "Для выхода нажмите 0 " << endl;
		cin >> ch;
		checkImput(ch);
		if (ch > size || ch < 0)
		{
			cout << "Нет такого варианта попробуйте еще раз" << endl;
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
			cout << "Недостаточно средств " << endl;
			system("pause");
			system("cls");
		}
		else 
		{
			system("cls");
			char date[100];
				cout << "Введите сегодняшнюю дату : ";
				cin >> date;
				int check=checkDate(date);
			send(obj.getConnetc(), date, sizeof(date), 0);
			cout << "Аренда склада оформлена !" << endl;
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
		cout << "Нет ни одной оценки или нет ни одного доступного склада  " << endl;
	}
	if (ch == 2)
	{
		cout << "Не все ставки получили оценки !" << endl;
	}
	if (ch == 0)
	{
		cout << "Лучший склад по мнению экспертов : " << endl;
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
		cout << "Название склада : " << nameStore << endl;
		cout << "Площадь склада : " << area << endl;
		cout << "Кол-во дней аренды : " << amountDay << endl;
		cout << "Стоимость : " << sum << endl;
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
		cout << "Нет доступных складов " << endl;
	}
	else
	{
		int ch;
		char msg[100];
		int rate;
		char buf[100];
		cout << "Меню выставления оценок >>" << endl;
		PrintfInfoStore(obj);
		cout << "Выберите нужный склад " << endl;
		cin >> ch;
		checkImput(ch);
		itoa(ch, msg, 10);
		send(obj.getConnetc(), msg, sizeof(msg), 0);
		cout << "Введите оценку от 1 до 10 " << endl;
		while (true)
		{
			cin >> rate;
			checkImput(rate);
			if (rate < 1 && rate>10)
			{
				cout << "Введите оценку в диапозоне от 1 до 10" << endl;
			}
			else
			{
				break;
			}
		}
		itoa(rate, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		cout << "Оценка сохранена !" << endl;
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
	cout << "Меню добавления Склада >>" << endl;
	cout << "Введите название склада : ";
	cin >> nameStore;
	send(obj.getConnetc(), nameStore, sizeof(nameStore), 0);
	cout << "Введите площадь склада : ";
	cin >> area;
	checkImput(area);
	itoa(area, bufarea, 10);
	send(obj.getConnetc(), bufarea, sizeof(bufarea), 0);
	cout << "Введите кол-во дней аренды : ";
	cin >> amountDay;
	checkImput(amountDay);
	itoa(amountDay, bufAmount, 10);
	send(obj.getConnetc(), bufAmount, sizeof(bufAmount), 0);
	cout << "Склад был оформлен успешно !" << endl;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	sum = atoi(buf);
	cout <<setw(15)<< "Сумма = " << sum << endl;
	cout << setw(15) << "Кол-во дней аренды = " << amountDay << endl;
	system("pause");

}

void addAccount(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистраци>>" << endl;
	while(true)
	{
		cout << "Ваша имя :";
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
		cout << "Ваш номер телефона : +375";
		cin >> buf;
		int check = checkTel(buf);
		if(check!=1)
		{
			break;
		}
	}
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Ваш паспортный номер : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте свой пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "регистрация прошла успешно " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации >>" << endl;
	cout << "Логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		system("cls");
		cout << "Нет такого пользоватьеля " << endl;
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Добро пожаловать " << name << ":)" << endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации >>" << endl;
	cout << "Логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Пороль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		system("cls");
		cout << "Нет такого Администратора  " << endl;
		Menu menu;
		menu.startMenu(obj);
	}
	else
	{
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Добро пожаловать Администратор " << name << ":)" << endl;
	}
}

int PrintfInfoStore(Server& obj)
{
	int size;
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	cout.setf(ios::right);
	cout  << "№" << setw(16) << "Название" << setw(17) << "Площадь" << setw(20) << "Кол-во дней" << setw(20) << "Сумма к оплате " << endl;
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
		cout  << "№" << i + 1<< setw(16) << nameStore << setw(17) << area << setw(20) << amountDay << setw(20) << sum << endl;
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
	cout << setw(10) << "имя" << setw(20) << "номер телефона" << setw(20) << "паспортные д." << setw(20) << "Сумма кредита " << setw(20) << "Дата оформления" << endl;
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
	cout << setw(10) << "имя" << setw(20) << "номер телефона" << setw(20) << "паспортные д." << setw(10) << "логин" << setw(10) << "пороль" << endl;
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
	cout << setw(10) <<"имя" << setw(20) << "номер телефона" << setw(20) << "паспортные д."<<setw(10) << "логин" <<setw(10)<< "пороль" << setw(20) << "денег на счете" << endl;
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
	cout << "Меню удаления пользователя " << endl;
	cout << "Введите логин пользователя : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные пользователя : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Пользователь:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Состояние кошелька : " << cash << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления Администратора " << endl;
	cout << "Введите логин админа : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные админа : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого пользователя нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Админ:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления Эксперта " << endl;
	cout << "Введите логин : ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите паспортные данные : ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "такого Эксперта нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Эксперт:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		cout << "удален!" << endl;
		system("pause");
		system("cls");
	}
}

void findAccount(Server& obj)
{
	system("cls");
	cout << "Меню поиска >>" << endl;
	cout << "Введите логин Эксперта : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "такого Эксперта нет " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя : " << name << endl;
		cout << "Номер телефона : " << tel << endl;
		cout << "Паспортные данные : " << pas_info << endl;
		cout << "Логин : " << login << endl;
		cout << "Пороль : " << password << endl;
		system("pause");
		system("cls");
	}
}

