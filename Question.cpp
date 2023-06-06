#include "Question.h"

Question::Question()
{
	id = 0;
}

Question::Question(const MyString& header, const MyString& content, unsigned id) : header(header), content(content)
{
	this->id = id;
}

//void Question::addComment(const MyString& authorName, const MyString& text)
//{
//	Comment comment(authorName, text, comments.getSize() + 1);
//	comments.pushBack(comment);
//}

//void Question::printComments() const
//{
//	for (size_t i = 0; i < comments.getSize(); i++)
//	{
//		std::cout << comments[i].printReplies() << std::endl;
//	}
//}
const MyString& Question::getHeader() const
{
	return header;
}

const unsigned Question::getId() const
{
	return id;
}
void Question::setId(unsigned id)
{
	if (id < 0)
		throw std::out_of_range("Invalid id!");
}

std::ostream& operator<<(std::ostream& os, const Question& obj)
{
	os << obj.header << obj.content << obj.id;
}
