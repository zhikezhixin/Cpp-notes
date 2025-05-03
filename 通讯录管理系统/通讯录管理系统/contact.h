#pragma once
#include <iostream>
#include <string>
#include <cstring> // 包含 memset 头文件

#define max 1000

using namespace std;

struct contacts
{
	string name;
	string sex;
	string number;
	string adress;
};

struct adressbook
{
	struct contacts people[max];
	int num ;
};

void Menu();

void InitialContact(struct adressbook* cont);

void AddContacts(struct adressbook* cont);

void FindContact(struct adressbook* cont);

void ShowContact(struct adressbook* cont);

void ModifyContact(struct adressbook* cont);

void DeletContact(struct adressbook* cont);

void ClearContact(struct adressbook* cont);


