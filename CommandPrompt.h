#pragma once
#include "Vector.hpp"
#include "User.h"
#include "Topic.h"
#include "Comment.h"
#include <cstring>
#include <iostream>
class CommandPrompt
{
	Question currentQuestion;
	Vector<Topic> topics;
	int openedTopic = -1;
	int openedQuestion = -1;

	void serialize() const;
	void deserialize();
public:
	CommandPrompt();
	void create(const MyString& topicTitle, const User& creator, const MyString& description);
	void search(const MyString& text) const;
	bool open(const MyString& title);
	bool open(unsigned id);
	void post(const MyString& header, const MyString& content, unsigned id);
	bool p_open(const MyString& title);
	bool p_open(unsigned id);
	void addComment(const MyString& authorName, const MyString& commentText, unsigned commentIndex);
	void printComments() const;
	void reply(unsigned id);
	void upvote(unsigned id, const User&);
	void downvote(unsigned id, const User&);
	void p_close();
	void quit();
	void about(unsigned id) const;
	void list();

	~CommandPrompt();
};
