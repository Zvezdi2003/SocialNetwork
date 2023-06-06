#include "Comment.h"

Comment::Comment()
{
	commentIndex = 0;
}

Comment::Comment(const MyString& authorName, const MyString& commentText, unsigned commentIndex) : authorName(authorName), commentIndex(commentIndex)
{
	this->commentIndex = commentIndex;
}

void Comment::addReply(const char* _reply)
{
	MyString reply(_reply);

	replies.pushBack(reply);
}

void Comment::upvote()
{
	upvotesCounter++;
}

void Comment::downvote()
{
	downvotesCounter++;
}

void Comment::printReplies() const
{
	for (size_t i = 0; i < replies.getSize(); i++)
	{
		std::cout << replies[i] << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Comment& obj)
{
	os << obj.authorName << obj.commentText << obj.commentIndex;
}
	
