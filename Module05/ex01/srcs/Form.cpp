
#include "Form.hpp"


/* CONSTRUCTORS */

Form::Form( void ) 
: name_("genericForm"), signGrade_(149), executeGrade_(150), signed_(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form( const std::string name, const int signGrade, const int executeGrade ) 
throw(GradeTooLowException, GradeTooHighException)
: name_(name), signGrade_(signGrade), executeGrade_(executeGrade), signed_(false)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	if (signGrade > 150 || executeGrade > 150)
	{
		throw (GradeTooLowException());
	}
	if (signGrade < 1 || executeGrade < 1)
	{
		throw (GradeTooHighException());
	}
}

Form::Form( const Form& to_copy ) 
: name_(to_copy.getName()), signGrade_(to_copy.getSignGrade()), executeGrade_(to_copy.getExecuteGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = to_copy;
}

/* DESTRUCTOR */

Form::~Form( void )
{
	std::cout << "Form destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

Form&	Form::operator=( const Form& to_copy )
{
	std::cout << "Form copy assignment operater overload called" << std::endl;
	if (this != &to_copy)
	{
		this->signed_ = to_copy.getSignedStatus();
	}
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const Form& to_print)
{
	output_stream << "Form: " << to_print.getName();
	output_stream << " Signing Grade: " << to_print.getSignGrade();
	output_stream << " Execution Grade: " << to_print.getExecuteGrade();
	output_stream << " Signed: " << to_print.getSignedStatus() << " ";
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

std::string const	Form::getName( void ) const
{
	return (this->name_);
}

bool	Form::getSignedStatus( void ) const
{
	return (this->signed_);
}

int	Form::getSignGrade( void ) const
{
	return (this->signGrade_);
}

int	Form::getExecuteGrade( void ) const
{
	return (this->executeGrade_);
}

void	Form::beSigned(Bureaucrat& cog) throw(GradeTooLowException)
{
	if (cog.getGrade() > this->signGrade_)
	{
		throw (GradeTooLowException());
	}
	else
	{
		this->signed_ = true;
	}
}

const char*	Form::GradeTooHighException::what( void ) const throw() 
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what( void ) const throw() 
{
	return ("Grade is too low");
}