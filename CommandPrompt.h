#pragma once
#include "Vector.hpp"
#include "User.h"
#include "Topic.h"
#include "Comment.h"
#include <cstring>
#include <iostream>
class CommandPrompt
{
	User currentUser;
	bool isLoggedIn = false;
	Vector<User> users;
	Vector<Topic> topics;
	Vector<Question> questions;
public:
	bool registerUser(const MyString& firstName,
		const MyString& lastName,
		const MyString& password,
		unsigned id,
		double points);
	bool login(const MyString& firstName, const MyString& pass);
	bool search(const MyString& text) const;
	void open(const MyString& title) const;
	void open(unsigned id) const;
	void post(const MyString& header, const MyString& content, unsigned id);
	void p_open(const MyString& title) const;
	void p_open(unsigned id) const;
	void addComment(const MyString& comment);
	void printComments(const MyString& comments) const;
	void reply(unsigned id);
	void upvote(unsigned id);
	void downvote(unsigned id);
	void p_close() const;
	void quit() const;
	void exit() const;
	void whoami() const;
	void about(unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const CommandPrompt& obj);
};
std::ostream& operator<<(std::ostream& os, const CommandPrompt& obj);