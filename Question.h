#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "Comment.h"
#include <stdexcept>
class Question
{
	MyString header;
	MyString content;
	unsigned id;
		
	Vector<Comment> comments;
	
public:
	Question();
	Question(const MyString& header, const MyString& content, unsigned id);

	/*void addComment(const MyString& authorName, const MyString& text);
	void printComments() const;*/

	const MyString& getHeader() const;
	const MyString& getContent() const;
	const unsigned getId() const;

	void setId(unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Question& obj);
};

std::ostream& operator<<(std::ostream& os, const Question& obj);

