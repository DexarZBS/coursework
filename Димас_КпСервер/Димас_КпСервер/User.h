#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Human.h"
#include "Server.h"
#include"FileCreator.h"
#include"Logistick_centre.h"
#include"Rating.h"
#include"Statistick.h"
#include"Credit.h"
using namespace std;
class User
{
protected:
	vector<Credit>vecCredit;
	vector<Statistick>vecStat;
	vector<Rating>vecRating;
	vector<Human>vecHuman;
	vector<Human>vecAdmin;
	vector<Human>vecExpert;
	vector<Logistick_centre>vecStore;
public:
	User();
	void  receptionUserCredit(Server& obj,int j);
	void replenish_credit(Server& obj, int i);
	void leaseCredit(Server& obj, int i);
	void replenish_account(Server& obj, int i);
	void ExpertReview(Server& obj, int i);
	void Lease(int i, Server& obj);
	void Estimate(int i, Server& obj);
	void receptionUser(int i, Server& obj);
	void receptionAdmin(int i, Server& obj);
	void receptionExpert(int i, Server& obj);
	int AutorizationAdmin(Server& obj);
	int AutorizationClient(Server& obj);
	int AutorizationExpert(Server& obj);
	void addStore(Server& obj,int i);
	void addClient(Server& obj);
	void addAdmin(Server& obj);
	void addExpert(Server& obj);
	void delClient(Server& obj);
	void delAdmin(Server& obj);
	void delExpert(Server& obj);
	void findUser(Server& obj);
	void findAdmin(Server& obj);
	void findExpert(Server& obj);
	void printf_infoPromiser(Server& obj);
	void printf_infoStore(Server& obj);
	void printf_infoClient(Server& obj);
	void printf_infoAdmin(Server& obj);
	void printf_infoExpert(Server& obj);
	void seve_info_Client();
	void save_info_Admin();
	void save_info_Expert();
	void save_info_Store();
	void save_infi_Rating();
	void save_info_credit();
};
