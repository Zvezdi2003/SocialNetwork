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

void CommandPrompt::search(const MyString& text) const
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (contains(topics[i].getTitle(), text))
		{
			std::cout << ">" << topics[i].getTitle() << topics[i].getId() << std::endl;
		}
	}
}

bool CommandPrompt::open(const MyString& title) 
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getTitle() == title)
		{
			currentTopic = topics[i];
			std::cout << ">" << topics[i].getTitle();
			return true;
		}
	}
	return false;
}

bool CommandPrompt::open(unsigned id) 
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getId() == id)
		{
			currentTopic = topics[i];
			std::cout << ">" << topics[i].getTitle();
			return true;
		}
	}
	return false;
}

void CommandPrompt::post(const MyString& header, const MyString& content, unsigned id)
{
	Question question(header, content, id);
	questions.pushBack(question);
}

bool CommandPrompt::p_open(const MyString& title) 
{
	for (size_t i = 0; i < questions.getSize(); i++)
	{
		if (questions[i].getHeader() == title)
		{
			currentQuestion = questions[i];
			std::cout << ">" << questions[i].getHeader();
			return true;
		}
	}
	return false;
}

bool CommandPrompt::p_open(unsigned id) 
{
	for (size_t i = 0; i < questions.getSize(); i++)
	{
		if (questions[i].getId() == id)
		{
			currentQuestion = questions[i];
			std::cout << ">" << questions[i].getHeader();
			return true;
		}
	}
	return false;
}

void CommandPrompt::addComment(const MyString& authorName, const MyString& commentText, unsigned commentIndex)
{
	Comment comment(authorName, commentText, commentIndex);
	comments.pushBack(comment);
}

void CommandPrompt::printComments(const MyString& comments) const
{
	for (size_t i = 0; i < comments.length(); i++)
	{
		std::cout << ">" << comments[i] << std::endl;
	}
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
		std::cout << ">" << users[i].getFirstName() << ", " << users[i].getPoints() << std::endl;
	}
}

void CommandPrompt::about(unsigned id) const
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getId() == id)
		{
			std::cout << ">" << topics[i].getTitle() << std::endl << topics[i].getDescription() << std::endl <<
				topics[i].getCreator().getFirstName() << topics[i].getCreator().getId() << std::endl <<
				topics[i].getQuestionsCount() << std::endl;
		}
	}
}
