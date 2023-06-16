#pragma once
#include "SocialNetwork.h"

bool SocialNetwork::registerUser(const MyString& firstName,
	const MyString& lastName,
	const MyString& password,
	unsigned id,
	double points)
{
	if (points < 0)
		return false;

	User user(firstName, lastName, password, 0);
	users.pushBack(user);
	return true;
}

bool SocialNetwork::login(const MyString& firstName, const MyString& pass)
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (users[i].getFirstName() == firstName && users[i].getPassword() == pass)
		{
			
		}
	}
	return false;
}
