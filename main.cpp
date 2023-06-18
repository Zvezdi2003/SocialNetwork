#include <iostream>
#include "CommandPrompt.h"
#include "MyString.h"
#include "GlobalConstants.h"
#include "SocialNetwork.h"

int main()
{
	SocialNetwork s;
	CommandPrompt c;

	MyString command;
	std::cout << "> ";
	std::cin >> command;


	while (command != EXIT_COMMAND)
	{
		if (command == SIGNUP_COMMAND)
		{
			MyString firstName, lastName, password;
			std::cout << "> Enter your first name: ";
			std::cin >> firstName;
			std::cout << "> Enter your last name: ";
			std::cin >> lastName;
			std::cout << "> Enter your password: ";
			std::cin >> password;
			s.registerUser(firstName, lastName, password);
			std::cout << std::endl;
			std::cout << std::endl;
		}

		else if (command == LOGIN_COMMAND)
		{
			MyString firstName, password;
			std::cout << "> Enter your first name: ";
			std::cin >> firstName;
			std::cout << "> Enter your password: ";
			std::cin >> password;
			s.login(firstName, password);
			std::cout << std::endl;
		}

		else if (command == LOGOUT_COMMAND)
		{
			s.logout();
			std::cout << std::endl;
		}

		else if (command == CREATE_COMMAND) 
		{
			MyString topicTitle, description;
			std::cout << "> Enter topic title: ";
			std::cin.ignore();
			getline(std::cin, topicTitle, 1024);
			std::cout << "> Enter description: ";
			std::cin.ignore();
			getline(std::cin, description, 1024);
			c.create(topicTitle, s.getCurrentUser(), description);
			std::cout << "> Success!";
			std::cout << std::endl;
		}

		else if (command == SEARCH_COMMAND)
		{
			MyString text;
			getline(std::cin, text, 1024);
			c.search(text);
			std::cout << std::endl;
		}

		else if (command == OPEN_COMMAND)
		{
			MyString paramStr;
			std::cin >> paramStr;
			if (isNumber(paramStr)) 
			{
				int id = atoi(paramStr.c_str());

				c.open(id);
				std::cout << std::endl;
			}
			else
			{
				MyString title = paramStr;

				c.open(title);
				std::cout << std::endl;
			}
		}

		else if (command == POST_COMMAND) 
		{
			MyString header, content;
			std::cout << "Enter the header of post: ";
			std::cin >> header;
			std::cout << "Enter the content of post: ";
			std::cin >> content;
			c.post(header, content, 0);

			std::cout << std::endl;
		}

		else if (command == P_OPEN_COMMAND)
		{
			MyString paramStr;
			std::cin >> paramStr;
			if (isNumber(paramStr)) 
			{
				int id = atoi(paramStr.c_str());

				c.p_open(id);

				std::cout << std::endl;
			}
			else
			{
				MyString title = paramStr;
				c.p_open(title);

				std::cout << std::endl;
			}
		}

		else if (command == COMMENT_COMMAND)
		{
			MyString authorName, commentText;
			std::cin >> authorName;
			std::cin >> commentText;
			c.addComment(authorName, commentText, 0);

			std::cout << std::endl;
		}

		else if (command == COMMENTS_COMMAND)
		{
			c.printComments();

			std::cout << std::endl;
		}

		else if (command == REPLY_COMMAND)
		{
			unsigned id;
			std::cin >> id;
			c.reply(id);

			std::cout << std::endl;
		}

		else if (command == UPVOTE_COMMAND)
		{
			unsigned id;
			User user;
			std::cin >> id;
			c.upvote(id, user);

			std::cout << std::endl;
		}

		else if (command == DOWNVOTE_COMMAND)
		{
			unsigned id;
			User user;
			std::cin >> id;
			c.downvote(id, user);

			std::cout << std::endl;
		}

		else if (command == P_CLOSE_COMMAND)
		{
			c.p_close();

			std::cout << std::endl;
		}

		else if (command == QUIT_COMMAND)
		{
			c.quit();

			std::cout << std::endl;
		}

		else if (command == WHOAMI_COMMAND)
		{
			s.whoami();

			std::cout << std::endl;
		}

		else if (command == ABOUT_COMMAND)
		{
			unsigned id;
			std::cin >> id;
			c.about(id);

			std::cout << std::endl;
		}

		else if (command == LIST_COMMAND)
		{
			c.list();

			std::cout << std::endl;
		}

		std::cout << "> ";
		std::cin >> command;
	}

}