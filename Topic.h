#include <iostream>
#include "MyString.h"
#include "Vector.hpp"
#include "Question.h"
#include "User.h"

class Topic {
	MyString title;
	User creator;
	MyString description;
	unsigned id;
	size_t length;

	Vector<Question> questions;

public:
	Topic();
	Topic(const MyString& title, const User& creator, const MyString& description, unsigned id);
	
	const MyString& getTitle() const;
	const User& getCreator() const;
	const MyString& getDescription() const;
	const unsigned getId() const;
	size_t getSize() const;
	size_t getQuestionsCount() const;

	void add(const Question& obj);

	friend std::ostream operator<<(std::ostream os, const Topic& obj);
};
std::ostream operator<<(std::ostream os, const Topic& obj);
