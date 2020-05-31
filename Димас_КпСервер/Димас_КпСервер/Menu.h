#pragma once
#include"User.h"
#include"Server.h"
class Menu :public User
{
	void AutorizationCheck(int check,Server &connectoin);
	void MenuChangeUser(Server& obj, int i, User& user);
	void MenuChangeAdmin(Server& obj, int i, User& user);
	void MenuChangeExpert(Server& obj, int i, User& user);
public:
	void startMenu(Server& obj);
	void AdminMenu(Server& obj, int i, User& user);
	void UserMenu(Server& obj, int i, User& user);
	void ExpertMenu(Server& obj, int i, User& user);
};