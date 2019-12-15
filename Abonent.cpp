#include "stdafx.h"
#include "Abonent.h"
#include <iostream>
using namespace std;


Abonent::Abonent() {

}
Abonent::Abonent(char* firstName, char* lastName, char* mobilePhone, char* nativeTown, char* post, int year, int month, int day)
{
	setFirstName(firstName);
	setLastName(lastName);
	setMobilePhone(mobilePhone);
	setNativeTown(nativeTown);
	setPost(post);
	setYear(year);
	setMonth(month);
	setDay(day);
}
Abonent::~Abonent() {

}
void Abonent::setFirstName(char* firstName)
{
	if (isNameCorrect(firstName)) strcopy(this->firstName, firstName); else throw exception("Error firstName");
}
char* Abonent::getFirstName()
{
	return firstName;
}
void Abonent::setLastName(char* lastName)
{
	if (isNameCorrect(lastName)) strcopy(this->lastName, lastName); else throw exception("Error lastName");

}
char* Abonent::getLastName()
{
	return lastName;
}
void Abonent::setMobilePhone(char* mobilePhone)
{
	if (isMobilePhoneCorrect(mobilePhone))strcopy(this->mobilePhone, mobilePhone); else throw exception("Error mobilePhone");

}
char* Abonent::getMobilePhone()
{
	return mobilePhone;
}
void Abonent::setNativeTown(char* nativeTown)
{
	if (isTownCorrect(nativeTown))strcopy(this->nativeTown, nativeTown); else throw exception("Error nativeTown");

}
char* Abonent::getNativeTown()
{
	return nativeTown;
}
void Abonent::setPost(char* post)
{
	strcopy(this->post, post);
}
char* Abonent::getPost()
{
	return post;
}
void Abonent::setYear(int year)
{
	if (isDateCorrect(1900, 2019, year)) this->birthday.year = year; else throw exception("Error year");

}
int Abonent::getYear()
{
	return birthday.year;
}
void Abonent::setMonth(int month)
{
	if (isDateCorrect(1, 12, month)) this->birthday.month = month; else throw exception("Error month");

}
int Abonent::getMonth()
{
	return birthday.month;
}
void Abonent::setDay(int day)
{
	if (isDateCorrect(1, countDay(birthday.month, birthday.year), day)) this->birthday.day = day; else throw exception("Error day");

}
int Abonent::getDay()
{
	return birthday.day;
}

int Abonent::countDay(int month, int year) {
	if (month == 2)
		if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
			return 28;
		else
			return 29;
	return 28 + int(month + floor(month / 8)) % 2 + 2 % month + 2 * floor(1 / month);
}
bool Abonent::isNameCorrect(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]))
		{
			cout << "Incorrect Name Input!" << endl;
			return false;
		}
	return true;
}
bool Abonent::isTownCorrect(char* name)
{
	if (strlength(name) == 0) return false;
	for (int i = 0; i < strlength(name); i++)
		if (!isalpha(name[i]) && (int)name[i] != 32 && (int)name[i] != 45)
		{
			cout << "Incorrect Town Input!" << endl;
			return false;
		}
	return true;
}

bool Abonent::isMobilePhoneCorrect(char* mobilePhone)
{
	if (strlength(mobilePhone) == 0) return false;
	for (int i = 0; i < strlength(mobilePhone); i++) if (!isdigit(mobilePhone[i]) && mobilePhone[i] != '+')
	{
		cout << "Incorrect Phone Input!" << endl;
		return false;
	}
	return true;
}

bool Abonent::isEquals(char* str1, char* str2)
{
	if (strlength(str1) != strlength(str2)) return false;
	
	int size = strlength(str1) > strlength(str2) ? strlength(str2) : strlength(str1);
	if (size == 0) return false;
	for (int i = 0; i < size; i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	
	return true;
}

bool Abonent::isDateCorrect(int a, int b, int curDate)
{
	if (curDate == 0 || curDate < a || curDate > b)
	{
		cout << "Verify day, month and year!" << endl;
		if (cin.fail()) {
			cout << "Incorrect Date Input!" << endl;
			cin.clear(); cin.ignore(32767, '\n');
		}
		return false;
	}
	return true;
}


int Abonent::strlength(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

int Abonent::strcopy(char* str1, char* str2)
{
	int i = -1;
	if (str1 != nullptr && str2 != nullptr)
		do {
			i++;
			str1[i] = str2[i];

		} while (str2[i] != '\0');

		return i;
}




