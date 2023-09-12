
#include "Intern.hpp"
#include <iostream>
#include "Color.hpp"

/* CONSTRUCTORS */

Intern::Intern( void ) {
	std::cout <<  COLOR_BRIGHT_YELLOW << "Default Constructor make new intern!" <<  COLOR_RESET << std::endl;
}

Intern::Intern( const Intern& to_copy ) {
	std::cout <<  COLOR_BRIGHT_YELLOW << "Copy Constructor make new intern!" <<  COLOR_RESET << std::endl;
	*this = to_copy;
}	

/* DESTRUCTOR */

Intern::~Intern( void ) {
	std::cout <<  COLOR_BRIGHT_YELLOW << "Intern Destructor called!" <<  COLOR_RESET << std::endl;
}

/* OPERATOR OVERLOADS */
//nothing to copy
Intern&	Intern::operator=( const Intern& toCopy ) {
	return (*this);
}

/* CLASS PUBLIC METHODS */

AForm*	Intern::makeForm( std::string formName, std::string formTarget)
{

}

/* CLASS PRIVATE METHODS */

ShrubberyCreationForm*	Intern::makeShrubForm( std::string target )
{
	
}

RobotomyRequestForm*	makeForm( std::string target )
{

}

ShrubberyCreationForm*	makeShrubForm( std::string target )
{

}