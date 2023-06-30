/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:43:47 by jebouche          #+#    #+#             */
/*   Updated: 2023/06/30 17:32:30 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Color.hpp"

/*****************PUBLIC METHODS*****************/

PhoneBook::PhoneBook(void) {
	std::cout << BGCOLOR_BLUE_GREEN << "Welcome to the rad 80's phonebook!" << COLOR_RESET << "\n\n";
	this->_contact_index = 0;
	this->_filled = false;
}

PhoneBook::~PhoneBook(void) {
	std::cout << BGCOLOR_PURPLE_YELLOW << "Thank you for using the rad 80's phone book!" << std::endl;
	std::cout << "Catch you on the flip side!" << COLOR_RESET << std::endl;
}

int	PhoneBook::userInterface(void) {
	std::string	input;
	int	res;

	while (true)
	{
		std::cout << COLOR_CYAN;
		std::cout << "What ya wanna do?" << std::endl;
		std::cout << "Choose from: ADD, SEARCH, or EXIT" << std::endl;
		std::cout << COLOR_RESET;
		res = _getInput(&input);
		if (res == FAILURE)
			break ;
		if (input.compare("ADD") == 0)
			res = _addContact();
		else if (input.compare("SEARCH") == 0)
			res = _search();
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << BGCOLOR_WHITE_RED << "Oh snap, thats invalid input, please try again." << COLOR_RESET << std::endl;
		if (res == FAILURE)
			break ;
	}
	if (res == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

/*****************PRIVATE METHODS*****************/
/*SEARCH METHODS*/

int	PhoneBook::_search(void) {
	std::string			input;
	int					index = 0;
	std::istringstream	sstr_index;

	if (this->_filled == false && this->_contact_index == 0)
	{
		std::cout << BGCOLOR_WHITE_RED << "Yo, You haven't added any contacts yet." << COLOR_RESET << std::endl;
		return (SUCCESS);
	}
	_displaySummary();
	std::cout << std::endl << "Enter the index of the contact you wish to display:" << std::endl;
	if (_getInput(&input) == FAILURE)
		return (FAILURE);
	sstr_index.str(input);
	sstr_index >> index;
	if (sstr_index.fail() || index >= 8 || index < 0)
		std::cout << BGCOLOR_WHITE_RED << "Please enter an index from 0 - 7" << COLOR_RESET<< std::endl;
	else if (this->_filled == false && index >= this->_contact_index)
		std::cout << BGCOLOR_WHITE_RED << "Yo, theres no contact entered at index " << index << COLOR_RESET << std::endl;
	else
	{
		_displaySearched(index);
	}
	return (SUCCESS);
}

void	PhoneBook::_displaySummary(void) {
	std::cout << "Here's your contacts to choose from:" << std::endl;
	std::cout << BGCOLOR_PURPLE_YELLOW;
	_printField("INDEX");
	std::cout << "|";
	_printField("FIRST NAME");
	std::cout << "|";
	_printField("LAST NAME");
	std::cout << "|";
	_printField("NICKNAME");
	std::cout << COLOR_RESET << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].getFirstName().empty())
			break ;
		std::cout << std::setw(10);
		std::cout << i << "|";
		_printField(this->_contacts[i].getFirstName());
		std::cout << "|";
		_printField(this->_contacts[i].getLastName());
		std::cout << "|";
		_printField(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::_printField(std::string to_print) {
	if (to_print.length() > 10)
	{
		for (int i = 0; i < 9; i++)
		{
			std::cout << to_print[i];
		}
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << to_print;
	}
}

void	PhoneBook::_displaySearched(int searched) {
	std::cout << BGCOLOR_PURPLE_YELLOW;
	std::cout << "Contact Information:";
	std::cout << COLOR_RESET << std::endl;
	std::cout << COLOR_YELLOW << "First Name: " << COLOR_RESET << this->_contacts[searched].getFirstName() << std::endl;
	std::cout << COLOR_YELLOW << "Last Name: " << COLOR_RESET << this->_contacts[searched].getLastName() << std::endl;
	std::cout << COLOR_YELLOW << "Nickname: " << COLOR_RESET << this->_contacts[searched].getNickname() << std::endl;
	std::cout << COLOR_YELLOW << "Phone Number: " << COLOR_RESET << this->_contacts[searched].getPhoneNumber() << std::endl;
	std::cout << COLOR_YELLOW << "Darkest Secret: " << COLOR_RESET << this->_contacts[searched].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
/*ADD CONTACT METHODS*/

int	PhoneBook::_addContact(void) {
	int	res;

	if (this->_contact_index >= 8)
	{
		if (this->_filled == false)
			this->_filled = true;
		this->_contact_index = 0;
	}
	res = _setContactInfo();
	this->_contact_index++;
	if (res != FAILURE)
		std::cout << BGCOLOR_GREEN_YELLOW << "Tubular! Contact added succesfully" << COLOR_RESET << std::endl << std::endl ;
	return (res);
}
int	PhoneBook::_setContactInfo(void) {
	if (_setFirstName() == FAILURE)
		return (FAILURE);
	if (_setLastName() == FAILURE)
		return (FAILURE);
	if (_setNickname() == FAILURE)
		return (FAILURE);
	if (_setPhoneNumber() == FAILURE)
		return (FAILURE);
	if (_setDarkestSecret() == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
int	PhoneBook::_setFirstName(void) {
	std::string	first_name;
	int	res;

	std::cout << "Awesome sauce, let's get started with the contact's " << COLOR_BRIGHT_GREEN "first name" << COLOR_RESET ":" << std::endl;
	do {
		res = _getInput(&first_name);
		if (res != FAILURE)
			this->_contacts[_contact_index].setFirstName(first_name);
		if (first_name.empty())
			std::cout << COLOR_BRIGHT_RED << "This can't be empty" << COLOR_RESET << std::endl;
	} 
	while (res != FAILURE && first_name.empty());
	return (res);
}
int	PhoneBook::_setLastName(void) {
	std::string	last_name;
	int	res;

	std::cout << "Cowabunga! Whats the " << COLOR_BRIGHT_GREEN << "last name" << COLOR_RESET ":" << std::endl;
	do {
		res = _getInput(&last_name);
		if (res != FAILURE)
			this->_contacts[_contact_index].setLastName(last_name);
		if (last_name.empty())
			std::cout << COLOR_BRIGHT_RED << "This can't be empty" << COLOR_RESET << std::endl;
	}
	while (res != FAILURE && last_name.empty());
		return (res);
}
int	PhoneBook::_setNickname(void) {
	std::string	nickname;
	int	res;

	std::cout << "Radicola, now enter a " << COLOR_BRIGHT_GREEN << "nickname" << COLOR_RESET << " for your contact:" << std::endl;
	do {
		res = _getInput(&nickname);
		if (res != FAILURE)
			this->_contacts[_contact_index].setNickname(nickname);
		if (nickname.empty())
			std::cout << COLOR_BRIGHT_RED << "This can't be empty" << COLOR_RESET << std::endl;
	}
	while (res != FAILURE && nickname.empty());
	return (res);
}

int	PhoneBook::_setPhoneNumber(void) {
	std::string	phone_number;
	int valid;
	int	res;

	valid  = 0;
	std::cout << "Righteous, now enter " << COLOR_BRIGHT_GREEN << "phone number" << COLOR_RESET << " (000 000 0000):" << std::endl;
	do {
		res = _getInput(&phone_number);
		if (res == FAILURE)
			return (FAILURE);
		if (phone_number.length() != 12)
		{
			std::cout << "Yo, enter a 10 digit phone number like this, ex: 000 000 0000:" << std::endl;
			std::cout << COLOR_BRIGHT_RED << "This can't be empty" << COLOR_RESET << std::endl;
		}
		else if (phone_number.find_first_not_of("0123456789 ", 0) != std::string::npos)
		{
			std::cout << "C'mon, lets enter only digits separated by spaces, ex: 000 000 0000:" << std::endl;
		}
		else if (phone_number[3] != ' ' || phone_number[7] != ' ')
		{
			std::cout << "Oh snap, thats not quite right. Please format phone number per example, ex: 000 000 0000:" << std::endl;
		}
		else
			valid = 1;	
	}
	while (phone_number.empty() || valid == 0);
	this->_contacts[_contact_index].setPhoneNumber(phone_number);
	return (SUCCESS);
}

int	PhoneBook::_setDarkestSecret(void) {
	std::string	darkest_secret;
	int	res;

	std::cout << "Now seriously, enter the contact's " << COLOR_BRIGHT_GREEN << "darkest secret" << COLOR_RESET << ":" << std::endl;
	do {
		res = _getInput(&darkest_secret);
		if (res != FAILURE)
			this->_contacts[_contact_index].setDarkestSecret(darkest_secret);
		if (darkest_secret.empty())
			std::cout << COLOR_BRIGHT_RED << "This can't be empty" << COLOR_RESET << std::endl;
	}
	while (res != FAILURE && darkest_secret.empty());
	return (res);
}

/*UTILITY FOR GETTING INPUT*/

int	PhoneBook::_getInput(std::string *read_to) {
	std::getline(std::cin, *read_to);
	if (std::cin.eof() == 1)
	{
		std::cout << BGCOLOR_WHITE_RED;
		std::cout << "Oh, bummer, you hit the EOF. If you wanted to leave you could have just typed 'EXIT', anyway" << std::endl;
		std::cout << COLOR_RESET;
		return (FAILURE);
	}
	std::cin.sync();
	return (SUCCESS);
}
