#pragma once
#include "CommandPrompt.h"

class SocialNetwork {
	CommandPrompt command;
	Vector<User> users;

public:
	SocialNetwork() = default;

	bool registerUser(const MyString& firstName,
		const MyString& lastName,
		const MyString& password,
		unsigned id,
		double points);

	bool login(const MyString& firstName, const MyString& pass);



};