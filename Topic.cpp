#include "Topic.h"


Topic::Topic() {
	this->id = 0;
}

Topic::Topic(const MyString& title, const MyString& creator, const MyString& description, unsigned id): title(title), creator(creator), description(description)
{
	this->id = id;
}

const MyString& Topic::getTitle() const
{
	return title;
}

const MyString& Topic::getCreator() const
{
	return creator;
}

const MyString& Topic::getDescription() const
{
	return description;
}

const Vector<Question>& Topic::getQuestions() const
{
	return questions;
}

const unsigned Topic::getId() const {
	return id;
}

void Topic::add(const Question& obj)
{
	questions.pushBack(obj);
}


std::ostream& operator<<(std::ostream& os, const Topic& obj)
{
	os << obj.getTitle() << obj.getCreator() << obj.getDescription() << obj.getId();
}
