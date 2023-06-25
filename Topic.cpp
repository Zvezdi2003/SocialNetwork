#include "Topic.h"


Topic::Topic() {
	this->id = 0;
}

Topic::Topic(const MyString& title, const User& creator, const MyString& description)
{
	this->title = title;
	this->creator = creator;
	this->description = description;
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

void Topic::empty()
{
	title = "";
	creator.empty();
	description = "";
	id = 0;
	length = 0;

	questions.clear();
}

bool Topic::isEmpty() const
{
	return title == "" && creator.isEmpty() && description == "" && id == 0 && length == 0 && questions.getSize() == 0;
}

void Topic::add(const Question& obj)
{
	questions.pushBack(obj);
}

void Topic::printQuestions() const
{
	for (size_t i = 0; i < questions.getSize(); i++)
	{
		std::cout << questions[i] << '\n';
	}
}
std::ostream& operator<<(std::ostream& os, const Topic& obj)
{
	return os << obj.getTitle() << obj.getDescription() << obj.getCreator().getFirstName() << obj.getCreator().getLastName() << obj.getCreator().getId() << obj.getId();
}
const Question& Topic::findQuestion(const MyString& title)const {
	for (size_t i = 0; i < questions.getSize(); i++)
	{
		if (questions[i].getHeader() == title)
		{
			return questions[i];
		}
	}
	throw std::logic_error("The question was not found!");
}

const Question& Topic::findQuestion(unsigned id)const {
	if (questions.getSize() <= id) {
		throw std::out_of_range("The index is not valid!");
	}

	return questions[id];
}

const Question& Topic::operator[](unsigned id)const {
	if (questions.getSize() <= id) {
		throw std::invalid_argument("The index is invalid!");
	}
	return questions[id];
}

Question& Topic::operator[](unsigned id) {
	if (questions.getSize() <= id) {
		throw std::invalid_argument("The index is invalid!");
	}
	return questions[id];
}
