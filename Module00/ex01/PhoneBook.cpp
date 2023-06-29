
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

/*****************PUBLIC METHODS*****************/

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the rad 80's phonebook!" << std::endl << std::endl;
	contact_index = 0;
	filled = false;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Thank you for using the rad 80's phone book!" << std::endl;
	std::cout << "Catch you on the flip side!" << std::endl;
}

int	PhoneBook::ui(void)
{
	std::string	input;
	int	res;

	while (true)
	{
		std::cout << "What ya wanna do?" << std::endl;
		std::cout << "Choose from: ADD, SEARCH, or EXIT" << std::endl;
		res = _get_input(&input);
		if (res == FAILURE)
			break ;
		if (input.compare("ADD") == 0)
			res = _add_contact();
		else if (input.compare("SEARCH") == 0)
			res = _search();
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Oh snap, thats invalid input, please try again." << std::endl;
		if (res == FAILURE)
			break ;
	}
	if (res == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

/*****************PRIVATE METHODS*****************/
/*SEARCH METHODS*/

int	PhoneBook::_search(void)
{
	std::string			input;
	int					index = 0;
	std::stringstream	sstr_index;

	_display_summary();
	std::cout << std::endl << "Enter the index of the contact you wish to display:" << std::endl;
	if (_get_input(&input) == FAILURE)
		return (FAILURE);
	sstr_index << input;
	sstr_index >> index;
	if (index >= 8 || index < 0)
		std::cout << "Please enter an index from 0 - 7" << std::endl;
	else if (filled == false && index >= contact_index)
		std::cout << "Yo, theres no contact entered at index " << index << std::endl;
	else
	{
		_display_searched(index);
	}
	return (SUCCESS);
}

void	PhoneBook::_display_summary(void)
{
	std::cout << "Here's your contacts to choose from:" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].get_first_name().empty())
			break ;
		std::cout << std::setw(10);
		std::cout << i << "|";
		_print_field(contacts[i].get_first_name());
		std::cout << "|";
		_print_field(contacts[i].get_last_name());
		std::cout << "|";
		_print_field(contacts[i].get_nickname());
		std::cout << std::endl;
	}
}
void	PhoneBook::_print_field(std::string to_print)
{
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
void	PhoneBook::_display_searched(int searched)
{
	std::cout << "Contact Information:" << std::endl;
	std::cout << contacts[searched].get_first_name() << std::endl;
	std::cout << contacts[searched].get_last_name() << std::endl;
	std::cout << contacts[searched].get_nickname() << std::endl;
	std::cout << contacts[searched].get_phone_number() << std::endl;
	std::cout << contacts[searched].get_darkest_secret() << std::endl;
	std::cout << std::endl;
}
/*ADD CONTACT METHODS*/

int	PhoneBook::_add_contact(void)
{
	int	res;

	if (contact_index >= 8)
	{
		if (filled == false)
			filled = true;
		contact_index = 0;
	}
	res = _set_contact_info();
	contact_index++;
	if (res != FAILURE)
		std::cout << "Tubular! Contact added succesfully" << std::endl << std::endl;
	return (res);
}
int	PhoneBook::_set_contact_info(void)
{
	if (_set_first_name() == FAILURE)
		return (FAILURE);
	if (_set_last_name() == FAILURE)
		return (FAILURE);
	if (_set_nickname() == FAILURE)
		return (FAILURE);
	if (_set_phone_number() == FAILURE)
		return (FAILURE);
	if (_set_darkest_secret() == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
int	PhoneBook::_set_first_name(void)
{
	std::string	first_name;
	int	res;

	std::cout << "Awesome sauce, let's get started with the contact's first name:" << std::endl;
	res = _get_input(&first_name);
	if (res != FAILURE)
		contacts[contact_index].set_first_name(first_name);
	return (res);
}
int	PhoneBook::_set_last_name(void)
{
	std::string	last_name;
	int	res;

	std::cout << "Cowabunga! Whats the last name:" << std::endl;
	res = _get_input(&last_name);
	if (res != FAILURE)
		contacts[contact_index].set_last_name(last_name);
		return (res);
}
int	PhoneBook::_set_nickname(void)
{
	std::string	nickname;
	int	res;

	std::cout << "Radicola, now enter a nickname for your contact:" << std::endl;
	res = _get_input(&nickname);
	if (res != FAILURE)
		contacts[contact_index].set_nickname(nickname);
	return (res);
}

int	PhoneBook::_set_phone_number(void)
{
	std::string	phone_number;
	int	res;

	std::cout << "Righteous, now enter phone number (000 000 0000):" << std::endl;
	res = _get_input(&phone_number);
	if (res == FAILURE)
		return (FAILURE);
	if (phone_number.length() != 12)
	{
		std::cout << "Yo, enter a 10 digit phone number like this, ex: 000 000 0000:" << std::endl;
		_set_phone_number();
	}
	else if (phone_number.find_first_not_of("0123456789 ", 0) != std::string::npos)
	{
		std::cout << "C'mon, lets enter only digits separated by spaces, ex: 000 000 0000:" << std::endl;
		_set_phone_number();
	}
	else if (phone_number[3] != ' ' || phone_number[7] != ' ')
	{
		std::cout << "Oh snap, thats not quite right. Please format phone number per example, ex: 000 000 0000:" << std::endl;
		_set_phone_number();
	}
	contacts[contact_index].set_phone_number(phone_number);
	return (SUCCESS);
}
int	PhoneBook::_set_darkest_secret(void)
{
	std::string	darkest_secret;
	int	res;

	std::cout << "Now seriously, enter the contacts darkest secret:" << std::endl;
	res = _get_input(&darkest_secret);
	if (res != FAILURE)
		contacts[contact_index].set_darkest_secret(darkest_secret);
	return (res);
}

/*UTILITY FOR GETTING INPUT*/

int	PhoneBook::_get_input(std::string *read_to)
{
	std::getline(std::cin, *read_to);
	if (std::cin.eof() == 1)
	{
		std::cout << "Oh, bummer, you hit the EOF. If you wanted to leave you could have just typed EXIT, anyway" << std::endl;
		return (FAILURE);
	}
	std::cin.sync();
	return (SUCCESS);
}
