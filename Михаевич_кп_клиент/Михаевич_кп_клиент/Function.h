#pragma once
#include<iostream>
#include<iomanip>
#include"Server.h"
#include"Menu.h"
using namespace std;
int checkName(char* a);
int checkTel(char* a);
int checkDate(char* a);
void replenish_credit(Server& obj);
void receptionUserCredit(Server& obj);
void rentCredit(Server& obj);
void replenish_account(Server& obj);
void rent(Server& obj);
void ExpertOpinion(Server& obj);
void rate(Server& obj);
void addStore(Server& obj);
void addAccount(Server& obj);
void AutorizationUser(Server& obj);
void AutorizationAdmin(Server& obj);
int PrintfInfoStore(Server& obj);
void Printf_infoPromiser(Server& obj);
void PrintfInfoAdminExpert(Server& obj);
void PrintfInfoClient(Server& obj);
void DelClient(Server& obj);
void DelAdmin(Server& obj);
void DelExpert(Server& obj);
void findAccount(Server& obj);
void checkImput(int a);

