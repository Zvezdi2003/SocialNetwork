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
	Topic currentTopic;
	Question currentQuestion;
	bool isLoggedIn = false;
	Vector<User> users;
	Vector<Topic> topics;
	Vector<Question> questions;
	Vector<Comment> comments;
public:
	bool registerUser(const MyString& firstName,
		const MyString& lastName,
		const MyString& password,
		unsigned id,
		double points);
	bool login(const MyString& firstName, const MyString& pass);
	void search(const MyString& text) const;
	bool open(const MyString& title);
	bool open(unsigned id);
	void post(const MyString& header, const MyString& content, unsigned id);
	bool p_open(const MyString& title);
	bool p_open(unsigned id);
	void addComment(const MyString& authorName, const MyString& commentText, unsigned commentIndex);
	void printComments(const MyString& comments) const;
	void reply(unsigned id);
	void upvote(unsigned id);
	void downvote(unsigned id);
	void p_close() const;
	void quit() const;
	void exit() const;
	void whoami() const;
	void about(unsigned id) const;

};
