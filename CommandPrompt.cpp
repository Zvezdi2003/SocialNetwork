#include "CommandPrompt.h"


bool CommandPrompt::registerUser(const MyString& firstName,
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

bool CommandPrompt::login(const MyString& firstName, const MyString& pass)
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (users[i].getFirstName() == firstName && users[i].getPassword() == pass)
		{
			isLoggedIn = true;
			currentUser = users[i];
			return true;
		}
	}
	return false;
}

bool CommandPrompt::search(const MyString& text) const
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getTitle() == text)
		{
			std::cout << topics[i] << std::endl;
			return true;
			break;
		}
	}
	return false;
}

void CommandPrompt::open(const MyString& title) const
{
}

void CommandPrompt::open(unsigned id) const
{
}

void CommandPrompt::post(const MyString& header, const MyString& content, unsigned id) 
{
	Question question(header, content, 0);
	questions.pushBack(question);
}

void CommandPrompt::p_open(const MyString& title) const
{
}

void CommandPrompt::p_open(unsigned id) const
{
}

void CommandPrompt::addComment(const MyString& comment)
{
}

void CommandPrompt::printComments(const MyString& comments) const
{
}

void CommandPrompt::reply(unsigned id)
{
}

void CommandPrompt::upvote(unsigned id)
{
}

void CommandPrompt::downvote(unsigned id)
{
}

void CommandPrompt::p_close() const
{
}

void CommandPrompt::quit() const
{
}

void CommandPrompt::exit() const
{
}

void CommandPrompt::whoami() const
{
	for (size_t i = 0; i < users.getSize(); i++)
	{
		std::cout << users[i] << std::endl;
	}
}

void CommandPrompt::about(unsigned id) const
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		std::cout << topics[i] << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const CommandPrompt& obj)
{
	
}