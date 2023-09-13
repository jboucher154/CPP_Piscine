
#include "Bureaucrat.hpp"
#include "Color.hpp"
 
/* CONSTRUCTORS */

Bureaucrat::Bureaucrat( void ) 
: name_("standardIssueBureaucrat"), grade_(150) {
	std::cout << COLOR_BRIGHT_BLUE << "Making new Bureaucrat..." << COLOR_RESET << std::endl;
	std::cout << COLOR_BRIGHT_BLUE << "Bureaucrat default constructor created " << this->getName() << ", Grade: " << this->getGrade() << COLOR_RESET << std::endl;
}
	
Bureaucrat::Bureaucrat( std::string name, int grade ) 
throw(GradeTooHighException, GradeTooLowException) 
: name_(name) 
{
	std::cout << COLOR_BRIGHT_BLUE << "Making new Bureaucrat..." << COLOR_RESET << std::endl;
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw (GradeTooLowException());
	}
	this->grade_ = grade;
	std::cout << COLOR_BRIGHT_BLUE << "Bureaucrat parameterized constructor created " << this->getName() << ", Grade: " << this->getGrade() << COLOR_RESET << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& to_copy ) 
: name_(to_copy.getName())
{
	std::cout << COLOR_BRIGHT_BLUE << "Bureaucrat copy constructor called" << COLOR_RESET << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

Bureaucrat::~Bureaucrat( void ) 
{
		std::cout << COLOR_BRIGHT_BLUE << "Bureaucrat destructor called for " << this->getName() << COLOR_RESET << std::endl;
}
/* OPERATOR OVERLOADS */

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& to_copy ) 
{
	std::cout << COLOR_BRIGHT_BLUE << "Bureaucrat copy assignment operator called" << COLOR_RESET << std::endl;
	if (this != &to_copy) {
		this->grade_ = to_copy.getGrade();
	}
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print) 
{
	output_stream << COLOR_BRIGHT_BLUE << to_print.getName() << ", bureaucrat grade " << to_print.getGrade() << COLOR_RESET;
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

std::string const	Bureaucrat::getName( void ) const 
{
	return (this->name_);
}

int	Bureaucrat::getGrade( void ) const 
{
	return (this->grade_);
}

void	Bureaucrat::incrementGrade( void ) throw(GradeTooHighException) 
{
	if (this->grade_ == 1) {
		throw (GradeTooHighException());
	}
	else {
		this->grade_--;
	}
}

void	Bureaucrat::decrementGrade( void ) throw(GradeTooLowException) 
{
	if (this->grade_ == 150) {
		throw (GradeTooLowException());
	}
	else {
		this->grade_++;
	}
}

void	Bureaucrat::executeForm( const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << COLOR_BRIGHT_BLUE << this->getName() << " executed " << form.getName() << COLOR_RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << COLOR_BRIGHT_RED << this->getName() << " could not execute " << form.getName() << "because: " << e.what() << "!" << COLOR_RESET << std::endl;
	}
}

void	Bureaucrat::signForm( AForm& toSign ) 
{
	try 
	{
		toSign.beSigned(*this);
		std::cout << COLOR_BRIGHT_BLUE << this->getName() << " signed " << toSign.getName() << COLOR_RESET << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << COLOR_BRIGHT_RED << this->getName() << " couldn't sign " << toSign.getName() << " because: " << e.what() << COLOR_RESET << std::endl;
	}
}

/* NESTED CLASS METHODS */

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() 
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() 
{
	return ("Grade is too low");
}