#pragma once
#include "MyString.h"


class User
{
	static int usersCounter;

	MyString firstName;
	MyString lastName;
	MyString password;
	unsigned id;
	double points;

public:
	User();
	User(const MyString& firstName, const MyString& lastName, const MyString& password, double points);

	const MyString& getFirstName() const;
	const MyString& getLastName() const;
	const MyString& getPassword() const;
	const unsigned getId() const;
	const double getPoints() const;
};



