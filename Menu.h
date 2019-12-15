#pragma once
#include "Contacts.h"
class Menu {
private:
	Contacts contacts;
	bool addContact();
	void deleteContact();
	void editContact();
	void showAllContacts();
	void showContact(int i);
	int chooseItemToEdit();
	int mainMenu();
	void exit();
public:
	Menu();
	void init();
};