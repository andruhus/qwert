#include "stdafx.h"
#include <cstdlib>
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu() {
	init();
	while (true)
	{
		int key = mainMenu();
		switch (key)
		{
		case 1: addContact(); break;
		case 2: deleteContact(); break;
		case 3: editContact(); break;
		case 4: showAllContacts(); break;
		case 0: exit(); return;
		default: cout << "Choose from 0 to 4!" << endl; break;
		}
		system("pause");
	}
}
void Menu::init()
{
	FILE* file;
	char name[] = "PhoneBook.db";
	if (fopen_s(&file, name, "r+b"))
	{
		cout << "File is Empty!" << endl;
		system("pause");
		return;
	}
	if (file != NULL) {
		while (!feof(file))
		{
			Abonent ab;
			fread(((char*)& ab), sizeof(Abonent), 1, file);
			if (!feof(file)) contacts.add(ab);

		}
		fclose(file);
	}
}
bool Menu::addContact()
{

	char firstName[64];
	char lastName[64];
	char adding_mobilePhone[64];
	char mobilePhone[64] = {'+','3','8','0'};
	char nativeTown[64];
	char post[256];
	unsigned int year, month, day;
	char answer;
	do
	{
		try
		{
			cin.clear(); cin.ignore(32767, '\n');
			cout << "Input First name(symbol without digit. Example: Brus) : " << endl;
			cin.getline(firstName, 64);

			cout << "Input Last name(symbol without digit. Example: Brusov): " << endl;
			cin.getline(lastName, 64);

			cout << "Input Mobile phone(digit without symbol. Example +3801112222): " << endl;
			cout << "+380";
			cin.getline(adding_mobilePhone, 64);
			for (int i = 0; adding_mobilePhone[i] > 0; i++)
				mobilePhone[i + 4] = adding_mobilePhone[i];

			cout << "Input native city/town(symbol without digit. Example: Kyiv): " << endl;
			cin.getline(nativeTown, 64);

			cout << "Input ocupation: " << endl;
			cin.getline(post, 256);

			cout << "Input Birhday(YYYY/MM/DD)" << endl;
			cout << "Input year(1900-2019): " << endl;
			cin >> year;
			cout << "Input month(1-12): " << endl;
			cin >> month;
			cout << "Input day(1-31): " << endl;
			cin >> day;
			Abonent ab = Abonent(firstName, lastName, mobilePhone, nativeTown, post, year, month, day);
			contacts.add(ab);
		}
		catch (exception e)
		{

			cout << "Try again" << endl;
			cin.clear(); cin.ignore(32767, '\n');
		}
		cout << "Input another contact?[yes/no]: " << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return true;
}

void Menu::deleteContact()
{
	cin.clear(); cin.ignore(32767, '\n');
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		if (i >= contacts.size()) break;
		showContact(i);
		char answ;
		cout << "Press 't' if you want to delete this very account" << endl;
		cin >> answ;
		if (answ == 't')
		{
			Abonent* ab = contacts.getAbonent(i);
			contacts.deleteByMobilePhone(ab->getMobilePhone());
			cout << "the contact was successfully deleted" << endl;
			system("pause");
			
		}
		system("cls");
		
	}
	
}

void Menu::editContact()
{
	cin.clear(); cin.ignore(32767, '\n');
	system("cls");
	Abonent* ab = nullptr;
	int ind_of_ab;
	for (int i = 0; i < 10; i++)
	{
		if (i >= contacts.size()) break;
		system("cls");
		showContact(i);
		char answ;
		cout << "Press 't' if you want to edit this very account" << endl;
		cin >> answ;
		if (answ == 't')
		{
			ab = contacts.getAbonent(i);
			ind_of_ab = i;
			break;
		}
	}

	if (ab == nullptr) return;


	int key = -1;
	while (key != 0)
	{
		system("cls");
		showContact(ind_of_ab);
		cout << "Choose Item to edit: " << endl;
		key = chooseItemToEdit();
		cin.clear(); cin.ignore(32767, '\n');
		switch (key)
		{
		case 1:
			cout << "Input new First name: " << endl;
			char firstName[64];
			cin.getline(firstName, 64);
			ab->setFirstName(firstName);
			break;
		case 2:
			cout << "Input new Last name: " << endl;
			char lastName[64];
			cin.getline(lastName, 64);
			ab->setLastName(lastName);
			break;
		case 3:
			cout << "Input new Mobile phone: " << endl;
			char mobilePhone[64];
			cin.getline(mobilePhone, 64);
			ab->setMobilePhone(mobilePhone);
			break;
		case 4:
			cout << "Input new native city/town: " << endl;
			char nativeTown[64];
			cin.getline(nativeTown, 64);
			ab->setNativeTown(nativeTown);
			break;
		case 5:
			cout << "Input new occupation: " << endl;
			char post[256];
			cin.getline(post, 256);
			ab->setPost(post);
			break;
		case 6:
			cout << "Input new Birhday(YYYY/MM/DD)" << endl;
			unsigned int year, month, day;
			cout << "Input year: " << endl;
			cin >> year;
			ab->setYear(year);
			cout << "Input month: " << endl;
			cin >> month;
			ab->setMonth(month);
			cout << "Input day: " << endl;
			cin >> day;
			ab->setDay(day);
			break;
		case 0: return;
		default: cout << "Choose from 0 to 6!" << endl; break;
		}
	}
	
}



inline void Menu::exit()
{
	FILE* file;
	char name[] = "PhoneBook.db";
	if ((fopen_s(&file, name, "w+b")))
	{
		cout << "File is not exist!" << endl;
		//fopen_s(&file, name, "w");
		return;
	}
	else
	{
		try
		{
			if (file != NULL) {
				for (int i = 0; i < contacts.size(); i++) {
					Abonent* ab = contacts.getAbonent(i);
					fwrite((char*)ab, sizeof(Abonent), 1, file);

				}
				fclose(file);
			}
		}
		catch (exception e)
		{
			e.what();
		}
	}
}
int Menu::mainMenu() {
	int key = -1;
	system("cls");
	cout << "\tMenu: " << endl <<
		"1 - Add new contact" << endl <<
		"2 - Delete contact" << endl <<
		"3 - Edit contact" << endl <<
		"4 - Show all contacts" << endl <<
		"0 - Exit" << endl;
	cin >> key;
	while (cin.fail())
	{
		cout << "Incorrect Input!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> key;
	}
	return key;
}
int Menu::chooseItemToEdit()
{
	cout << "1 - First name" << endl << "2 - Last name" << endl <<
		"3 - Mobile phone" << endl << "4 - Native town" << endl <<
		"5 - Occupation" << endl << "6 - Birthday" << endl << "0 - Exit" << endl;
	int key = -1;
	while (key < 0 || key > 6)
	{
		cin >> key;
		while (cin.fail())
		{
			cout << "Error, input again: " << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> key;
		}
	}
	return key;
}

void Menu::showContact(int i)
{
	if (i >= contacts.size()) return;
	Abonent* ab = contacts.getAbonent(i);
	cout << "*************************" << endl;
	cout << "First name: " << ab->getFirstName() << endl;
	cout << "Last name: " << ab->getLastName() << endl;
	cout << "Mobile Phone: " << ab->getMobilePhone() << endl;
	cout << "Native town: " << ab->getNativeTown() << endl;
	cout << "Occupaton: " << ab->getPost() << endl;

	cout << "Birhday: " << endl << "Year: " << ab->getYear() << endl << "Month: " << ab->getMonth() << endl << "Day: " << ab->getDay() << endl;
}

void Menu::showAllContacts()
{
	for (int i = 0; i < contacts.size(); i++)
	{
		showContact(i);
	}
	if (contacts.size() == 0) cout << "Nothing to show" << endl;
	//contacts.showAllAbonents();
}
