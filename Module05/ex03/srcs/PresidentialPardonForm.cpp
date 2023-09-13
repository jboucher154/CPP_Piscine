
#include "PresidentialPardonForm.hpp"
#include "Color.hpp"
 
/* CONSTRUCTORS */

PresidentialPardonForm::PresidentialPardonForm( void ) 
: AForm("PresidentialPardonForm", 25, 5), target_("defaultTarget") 
{
	std::cout << "PresidentialPardonForm default constructor created form for target: " <<  this->target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) 
: AForm("PresidentialPardonForm", 25, 5), target_(target)
{
	std::cout << "PresidentialPardonForm parameterized constructor created form for target: " <<  this->target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& to_copy )
: AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

PresidentialPardonForm::~PresidentialPardonForm( void ) 
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& to_copy ) 
{
	std::cout << "PresidentialPardonForm copy assignment operator overload called" << std::endl;
	if (this != &to_copy)
	{
		this->AForm::copySignedStatus(to_copy.getSignedStatus());
		this->target_ = to_copy.target_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const throw(GradeTooLowException, FormNotSignedException)
{
	this->AForm::execute(executor);
	std::cout <<  COLOR_BRIGHT_YELLOW;
	std::cout << "Attention....ATTENTION!!!!" << std::endl;
	std::cout << "Hear ye, hear ye" << std::endl;
	std::cout << "The magnanimous President of the Galaxy, Zaphod Beeblebrox," << std::endl;
	std::cout << "herby pardons " <<  this->target_ << std::endl;
	std::cout << "That is all." << std::endl;
	std::cout <<  COLOR_RESET;
}

