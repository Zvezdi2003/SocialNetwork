#include "Comment.h"
#include "User.h"

Comment::Comment()
{
	commentIndex = 0;
}

Comment::Comment(const MyString& authorName, const MyString& commentText, unsigned commentIndex) : authorName(authorName), commentIndex(commentIndex)
{
	this->commentIndex = commentIndex;
}

void Comment::addReply(const MyString& _reply)
{
	MyString reply(_reply);

	replies.pushBack(reply);
}

void Comment::upvote(const User& user)
{
	for (size_t i = 0; i < upvoteUsersIds.getSize(); i++)
	{
		if (upvoteUsersIds[i] == user.getId())
		{
			upvoteUsersIds.popAt(i);
			return;
		}
	}

	upvoteUsersIds.pushBack(user.getId());
}

void Comment::downvote(const User& user)
{
	for (size_t i = 0; i < downvoteUsersIds.getSize(); i++)
	{
		if (downvoteUsersIds[i] == user.getId())
		{
			downvoteUsersIds.popAt(i);
			return;
		}
	}

	downvoteUsersIds.pushBack(user.getId());
}

const MyString& Comment::getAuthorName() const
{
	return authorName;
}

const MyString& Comment::getCommentText() const
{
	return commentText;
}

const unsigned Comment::getCommentIndex() const
{
	return commentIndex;
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
	os << " >> " << obj.commentText << "{id:" << obj.commentIndex << "}";
}

std::istream& operator>>(std::istream& os, Comment& obj)
{
	os >> obj.commentText >> obj.commentIndex;
}
