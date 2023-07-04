
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void) {}

Contact::~Contact(void) {}

/*SETTERS*/

void	Contact::setFirstName(std::string fname) {
	this->_first_name = fname;
}

void	Contact::setLastName(std::string lname) {
	this->_last_name = lname;
}

void	Contact::setNickname(std::string nname) {
	this->_nickname = nname;
}

void	Contact::setPhoneNumber(std::string pnumber) {
	this->_phone_number = pnumber;
}

void	Contact::setDarkestSecret(std::string secret) {
	this->_darkest_secret = secret;	
}

/*GETTERS*/

std::string	Contact::getFirstName(void) const {
	return (this->_first_name);
}

std::string	Contact::getLastName(void) const {
	return (this->_last_name);
}

std::string	Contact::getNickname(void) const {
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const {
	return (this->_phone_number);
}

std::string	Contact::getDarkestSecret(void) const {
	return (this->_darkest_secret);
}
