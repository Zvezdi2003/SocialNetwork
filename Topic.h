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
	Topic(const MyString& title, const User& creator, const MyString& description);
	
	const MyString& getTitle() const;
	const User& getCreator() const;
	const MyString& getDescription() const;
	const unsigned getId() const;
	size_t getSize() const;
	size_t getQuestionsCount() const;

	void empty();
	bool isEmpty() const;
	void add(const Question& obj);
	void printQuestions() const;
	const Question& findQuestion(const MyString& obj)const;
	const Question& findQuestion(unsigned id)const;
	friend std::ostream operator<<(std::ostream os, const Topic& obj);

	const Question& operator[](unsigned id)const;
	Question& operator[](unsigned id);
};
std::ostream operator<<(std::ostream os, const Topic& obj);
