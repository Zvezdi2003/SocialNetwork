#include "CommandPrompt.h"


CommandPrompt::CommandPrompt()
{
	deserialize();
}

void CommandPrompt::create(const MyString& topicTitle, const User& creator, const MyString& description)
{
	Topic topic(topicTitle, creator, description);
	topics.pushBack(topic);
}
void CommandPrompt::search(const MyString& text) const
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (contains(topics[i].getTitle(), text))
		{
			std::cout << " >> " << topics[i].getTitle() << " {id: " << topics[i].getId() << "}" << std::endl;
		}
	}
}

bool CommandPrompt::open(const MyString& title)
{
	for (size_t i = 0; i < topics.getSize(); i++)
	{
		if (topics[i].getTitle() == title)
		{
			std::cout << ">" << "Welcome to " << "\"" << topics[i].getTitle() << "\"!";
			openedTopic = i;
			return true;
		}
	}
	return false;
}

bool CommandPrompt::open(unsigned id)
{
	if (topics.getSize() <= id) {
		std::cout << "Topic index not found";
		return false;
	}
	std::cout << ">" << "Welcome to " << "\"" << topics[id].getTitle() << "\"!";
	openedTopic = id;
	return true;
}

void CommandPrompt::post(const MyString& header, const MyString& content, unsigned id)
{
	if (openedTopic != -1)
	{
		Question question(header, content, topics.getSize());
		topics[openedTopic].add(question);
	}
}

bool CommandPrompt::p_open(const MyString& title)
{
	if (openedTopic != -1) {
		std::cout << topics[openedTopic].findQuestion(title);
		return true;
	}
	return false;
}

bool CommandPrompt::p_open(unsigned id)
{
	if (openedTopic != -1) {
		std::cout << topics[openedTopic].findQuestion(id);
		return true;
	}
	return false;
}

void CommandPrompt::addComment(const MyString& authorName, const MyString& commentText, unsigned commentIndex)
{
	if (openedQuestion != -1) {
		Comment comment(authorName, commentText, topics[openedTopic][openedQuestion].getId());
		topics[openedTopic][openedQuestion].addComment(comment);
		std::cout << "> Posted";
	}
}

void CommandPrompt::printComments() const
{
	if (openedQuestion != -1)
	{
		topics[openedTopic][openedQuestion].printComments();
	}
}

void CommandPrompt::reply(unsigned id)
{
	if (openedQuestion != -1)
	{
		MyString reply;
		std::cin >> reply;
		topics[openedTopic][openedQuestion][id].addReply(reply);
		std::cout << "> Posted";
	}
}

void CommandPrompt::upvote(unsigned id, const User& user)
{
	if (topics[openedTopic][openedQuestion].getSize() <= id)
	{
		throw std::invalid_argument("Invalid id!");
	}
	topics[openedTopic][openedQuestion][id].upvote(user);
}

void CommandPrompt::downvote(unsigned id, const User& user)
{
	if (topics[openedTopic][openedQuestion].getSize() <= id)
	{
		throw std::invalid_argument("Invalid id!");
	}
	topics[openedTopic][openedQuestion][id].downvote(user);
}

void CommandPrompt::p_close()
{
	if (openedQuestion == -1)
	{
		std::cout << "The post is already closed!" << std::endl;
	}
}

void CommandPrompt::quit()
{
	if (openedTopic == -1)
	{
		std::cout << "The topic is already closed!" << std::endl;
	}
}

void CommandPrompt::about(unsigned id) const
{
	std::cout << " >> Name: " << topics[id].getTitle(); 
	std::cout << " >> Description: " << topics[id].getDescription();
	std::cout << " >> Created by: " << topics[id].getCreator().getFirstName() << " " << topics[id].getCreator().getLastName() << " {id: " << id << "}";
	std::cout << " >> Questions asked: " << topics[id].getQuestionsCount();
}

void CommandPrompt::list()
{
	if (openedTopic != -1)
	{
		topics[openedTopic].printQuestions();
	}
}

void CommandPrompt::serialize() const
{
	std::ofstream ofs("file.bin", std::ios::out | std::ios::binary);
	if (!ofs.is_open())
	{
		throw std::logic_error("It could not open");
	}

	ofs.write((const char*)&currentQuestion, sizeof(currentQuestion));
	ofs.write((const char*)&topics, sizeof(topics));

	ofs.close();
}
void CommandPrompt::deserialize()
{
	std::ifstream ifs("file.bin", std::ios::in | std::ios::binary);
	if (!ifs.is_open())
	{
		throw std::logic_error("It could not open");
	}
	ifs.read((char*)&currentQuestion, sizeof(currentQuestion));
	ifs.read((char*)&topics, sizeof(topics));
	ifs.close();
}


CommandPrompt::~CommandPrompt()
{
	serialize();
}
