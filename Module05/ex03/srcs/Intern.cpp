
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

Intern&	Intern::operator=( const Intern& toCopy ) {
	//nothing to copy
	( void ) toCopy;
	return (*this);
}

/* CLASS PRIVATE METHODS */
AForm*	Intern::makeShrubForm( std::string const target )
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyForm( std::string const target )
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialForm( std::string const target )
{
	return (new PresidentialPardonForm(target));
}

const char*	Intern::InvalidFormException::what( void ) const throw() 
{
	return ("Invalid form title was passed.");
}
/* CLASS PUBLIC METHODS */

AForm*	Intern::makeForm( std::string formName, std::string formTarget)
throw (InvalidFormException)
{
	std::string validForms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	Intern::t_possibleForms forms = { &Intern::makeRobotomyForm, &Intern::makeShrubForm, &Intern::makePresidentialForm };
	// AForm*	(Intern::*forms[3])(std::string co nst target) = { &Intern::makeRobotomyForm, &Intern::makeShrubForm, &Intern::makePresidentialForm };
	AForm*	returnForm = nullptr;
	for (int i = 0; i < 3; i++)
	{
		if (!formName.compare(validForms[i]))
		{
			returnForm = (this->*forms[i])(formTarget);
			std::cout << COLOR_BRIGHT_GREEN << "Intern creates " << formName << " for target " << formTarget << COLOR_RESET << std::endl;
			return (returnForm);
		}
	}
	std::cout << COLOR_RED << "Error: the requested form [" << formName << "] does not exist. Form was not allocated." << std::endl;
	std::cout << "Please check your spelling." << std::endl;
	std::cout << "Usage Note: The form request is case sensitive and must be lowercase." << COLOR_RESET << std::endl;
	throw (InvalidFormException());
}
