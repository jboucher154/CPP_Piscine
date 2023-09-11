
#include "AForm.hpp"


/* CONSTRUCTORS */

AForm::AForm( void ) 
: name_("genericAForm"), signGrade_(149), executeGrade_(150), signed_(false)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm( const std::string name, const int signGrade, const int executeGrade ) 
throw(GradeTooLowException, GradeTooHighException)
: name_(name), signGrade_(signGrade), executeGrade_(executeGrade), signed_(false)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	if (signGrade > 150 || executeGrade > 150)
	{
		throw (GradeTooLowException());
	}
	if (signGrade < 1 || executeGrade < 1)
	{
		throw (GradeTooHighException());
	}
}

AForm::AForm( const AForm& to_copy ) 
: name_(to_copy.getName()), signGrade_(to_copy.getSignGrade()), executeGrade_(to_copy.getExecuteGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = to_copy;
}

/* DESTRUCTOR */

AForm::~AForm( void )
{
	std::cout << "AForm destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

AForm&	AForm::operator=( const AForm& to_copy )
{
	std::cout << "AForm copy assignment operater overload called" << std::endl;
	if (this != &to_copy)
	{
		this->signed_ = to_copy.getSignedStatus();
	}
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const AForm& to_print)
{
	output_stream << "AForm: " << to_print.getName();
	output_stream << " Signing Grade: " << to_print.getSignGrade();
	output_stream << " Execution Grade: " << to_print.getExecuteGrade();
	output_stream << " Signed: " << to_print.getSignedStatus() << " ";
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

std::string const	AForm::getName( void ) const
{
	return (this->name_);
}

bool	AForm::getSignedStatus( void ) const
{
	return (this->signed_);
}

int	AForm::getSignGrade( void ) const
{
	return (this->signGrade_);
}

int	AForm::getExecuteGrade( void ) const
{
	return (this->executeGrade_);
}

void	AForm::beSigned(Bureaucrat& cog) throw(GradeTooLowException)
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

/* CLASS PROTECTED METHODS */

void	AForm::copySignedStatus( int signedStatus )
{
	this->signed_ = signedStatus;
}

/* NESTED CLASS METHODS */

const char*	AForm::GradeTooHighException::what( void ) const throw() 
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what( void ) const throw() 
{
	return ("Grade is too low");
}