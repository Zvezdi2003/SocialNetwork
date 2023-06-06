#include "User.h"


int User::usersCounter = 0;

User::User(const MyString& firstName, const MyString& lastName, const MyString& password, double points) : firstName(firstName), lastName(lastName), password(password) {

	usersCounter++;
	id = usersCounter;

	this->firstName = firstName;
	this->lastName = lastName;
	this->password = password;
	this->points = points;
}  

User::User() {
	usersCounter++;
	id = usersCounter;

	this->id = 0;
	this->points = 0;
}

const MyString& User::getFirstName() const {
	return firstName;
}
const MyString& User::getLastName() const {
	return lastName;
}

const MyString& User::getPassword() const {
	return password;
}
const unsigned User::getId() const
{
	return id;
}
const double User::getPoints() const
{
	return id;
}