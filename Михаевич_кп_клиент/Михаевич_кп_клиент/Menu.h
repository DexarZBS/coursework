#pragma once
#include<iostream>
#include"Server.h"
#include"Function.h"
using namespace std;
class Menu
{
	void displayAccount(Server& obj);
	void displayClient(Server& obj);
	void CheckImputSwitch(int check);
	void MenuChangeAdmin(Server& obj);
	void MenuChangeUser(Server& obj);
	void MenuChangeExpert(Server& obj);

	void MenuUser(Server& Connection);
	void MenuAdmin(Server& Connection);
	void MenuExpert(Server& Connection);
public:		
	void startMenu(Server& Connection);
	
};
