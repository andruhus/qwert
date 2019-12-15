#pragma once
#include <iostream>
using namespace std;
class Abonent {
private:
	char firstName[64];
	char lastName[64];
	char mobilePhone[64];
	char nativeTown[64];
	char post[256];
	struct { unsigned int year = 0, month = 0, day = 0; } birthday;

	bool isNameCorrect(char* name);
	bool isTownCorrect(char* name);
	bool isMobilePhoneCorrect(char* mobilePhone);
	bool isPermutation(char* str1, char* str2);
	bool isDateCorrect(int a, int b, int curDate);
	int strlength(char* str);
	int strcopy(char* str1, char* str2);
	int countDay(int month, int year);
	bool isEquals(char* str1, char* str2);

public:
	Abonent(char* firstName, char* lastName, char* mobilePhone, char* nativeTown, char* post, int year, int month, int day);
	Abonent();
	~Abonent();
	void setFirstName(char* firstName);
	char* getFirstName();
	void setLastName(char* lastName);
	char* getLastName();
	void setMobilePhone(char* mobilePhone);
	char* getMobilePhone();
	void setNativeTown(char* nativeTown);
	char* getNativeTown();
	void setPost(char* post);
	char* getPost();
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();
	friend ostream& operator<<(ostream& out, Abonent& ab);
	friend bool operator==(Abonent& ab, char* mobilePhone);
	friend bool operator!=(Abonent& ab, char* mobilePhone);
};

inline ostream& operator<<(ostream& out, Abonent& ab)
{
	return out << ab.firstName << ", " << ab.lastName << ", " << ab.mobilePhone << ", " << ab.nativeTown << ", " << ab.post << ", " << ab.birthday.year << ", " << ab.birthday.month << ", " << ab.birthday.day;

}

inline bool operator==(Abonent& ab, char* mobilePhone)
{
	return ab.isEquals(ab.mobilePhone, mobilePhone);
}

inline bool operator!=(Abonent& ab, char* mobilePhone)
{
	return !ab.isEquals(ab.mobilePhone, mobilePhone);
}