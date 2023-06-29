
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void)
{
	// std::cout << "Empty Contact created" << std::endl;
}
Contact::~Contact(void)
{
	// std::cout << "Deconstructing Contact"  << std::endl;
}
/*SETTERS*/
void	Contact::set_first_name(std::string fname)
{
	first_name = fname;
}
void	Contact::set_last_name(std::string lname)
{
	last_name = lname;
}
void	Contact::set_nickname(std::string nname)
{
	nickname = nname;
}

void	Contact::set_phone_number(std::string pnumber)
{
	phone_number = pnumber;
}
void	Contact::set_darkest_secret(std::string secret)
{
	darkest_secret = secret;	
}
/*GETTERS*/
std::string	Contact::get_first_name(void)
{
	return (first_name);
}
std::string	Contact::get_last_name(void)
{
	return (last_name);
}
std::string	Contact::get_nickname(void)
{
	return (nickname);
}
std::string	Contact::get_phone_number(void)
{
	return (phone_number);
}
std::string	Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}
