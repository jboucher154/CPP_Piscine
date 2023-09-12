
#include "Bureaucrat.hpp"
 
/* CONSTRUCTORS */

Bureaucrat::Bureaucrat( void ) 
: name_("standardIssueBureaucrat"), grade_(150) {
	std::cout << "Bureaucrat default constructor created " << this->getName() << std::endl;
}
	
Bureaucrat::Bureaucrat( std::string name, int grade ) 
throw(GradeTooHighException, GradeTooLowException) 
: name_(name) 
{
	std::cout << "Bureaucrat parameterized constructor created " << this->getName() << ", Grade: " << this->getGrade() << std::endl;
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw (GradeTooLowException());
	}
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& to_copy ) 
: name_(to_copy.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

Bureaucrat::~Bureaucrat( void ) 
{
		std::cout << "Bureaucrat destructor called for " << this->getName() << std::endl;
}
/* OPERATOR OVERLOADS */

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& to_copy ) 
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &to_copy) {
		this->grade_ = to_copy.getGrade();
	}
	return (*this);
}
//include endl or no?
std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print) 
{
	output_stream << to_print.getName() << ", bureaucrat grade " << to_print.getGrade() << ".";
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
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException e)
	{
		std::cout << this->getName() << " could not execute " << form.getName() << "because their grade (" << this->getGrade() << ") is too low" << std::endl;
	}
}

void	Bureaucrat::signForm( AForm& toSign ) 
{
	try 
	{
		toSign.beSigned(*this);
		std::cout << this->getName() << " signed " << toSign.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException e)
	{
		std::cout << this->getName() << " couldn't sign " << toSign.getName() << "because their grade (" << this->getGrade() << ") is too low" << std::endl;
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