#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "User.h"
#include <stdexcept>

class Comment
{
	MyString authorName;
	MyString commentText;
	Vector<MyString> replies;
	Vector<unsigned> upvoteUsersIds;
	Vector<unsigned> downvoteUsersIds;
	unsigned commentIndex;

public:
	Comment();
	Comment(const MyString& authorName, const MyString& commentText, unsigned commentIndex);
	
	void addReply(const MyString& reply);
	void upvote(const User& user);
	void downvote(const User&);

	const MyString& getAuthorName() const;
	const MyString& getCommentText() const;
	const unsigned getCommentIndex() const;

	void printReplies() const;

	friend std::ostream& operator<<(std::ostream& os, const Comment& obj);
	friend std::istream& operator>>(std::istream& os, Comment& obj);

};
std::ostream& operator<<(std::ostream& os, const Comment& obj);
std::istream& operator>>(std::istream& os, Comment& obj);
