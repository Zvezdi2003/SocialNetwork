#include <iostream>
#include "MyString.h"
#include "Vector.hpp"
#include "Question.h"

class Topic {
	MyString title;
	MyString creator;
	MyString description;
	Vector<Question> questions;
	unsigned id;
public:
	Topic();
	Topic(const MyString& title, const MyString& creator, const MyString& description, unsigned id);

	const MyString& getTitle() const;
	const MyString& getCreator() const;
	const MyString& getDescription() const;
	const Vector<Question>& getQuestions() const;
	const unsigned getId() const;

	void add(const Question& obj);

	friend std::ostream operator<<(std::ostream os, const Topic& obj);
};
std::ostream operator<<(std::ostream os, const Topic& obj);
