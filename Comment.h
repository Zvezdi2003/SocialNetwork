#pragma once
#include "MyString.h"
#include "Vector.hpp"

class Comment
{
	MyString authorName;
	MyString commentText;
	Vector<MyString> replies;
	unsigned commentIndex;
	unsigned upvotesCounter = 0;
	unsigned downvotesCounter = 0;

public:
	Comment();
	Comment(const MyString& authorName, const MyString& commentText, unsigned commentIndex);
	
	void addReply(const char* reply);
	void upvote();
	void downvote();

	void printReplies() const;

	friend std::ostream& operator<<(std::ostream& os, const Comment& obj);
};
std::ostream& operator<<(std::ostream& os, const Comment& obj);
