#include "Topic.h"


Topic::Topic() {
	this->id = 0;
}

Topic::Topic(const MyString& title, const User& creator, const MyString& description, unsigned id) : title(title), creator(creator), description(description)
{
	this->id = id;
}

const MyString& Topic::getTitle() const
{
	return title;
}

const User& Topic::getCreator() const
{
	return creator;
}

const MyString& Topic::getDescription() const
{
	return description;
}

const unsigned Topic::getId() const {
	return id;
}

size_t Topic::getQuestionsCount() const
{
	return questions.getSize();
}

size_t Topic::getSize() const {
	return length;
}
void Topic::add(const Question& obj)
{
	questions.pushBack(obj);
}


std::ostream& operator<<(std::ostream& os, const Topic& obj)
{
	return os << obj.getTitle() << obj.getDescription() << obj.getCreator().getFirstName() << obj.getCreator().getId() << obj.getId();
}
