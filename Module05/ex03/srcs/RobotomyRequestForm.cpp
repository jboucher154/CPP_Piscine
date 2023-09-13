
#include "RobotomyRequestForm.hpp"
#include <ctime>
#include "Color.hpp"
 
/* CONSTRUCTORS */

RobotomyRequestForm::RobotomyRequestForm( void ) 
: AForm("RobotomyRequestForm", 72, 45), target_("defaultTarget") 
{
	std::cout << "RobotomyRequestForm default constructor created form for target: " <<  this->target_ << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) 
: AForm("RobotomyRequestForm", 72, 45), target_(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor created form for target: " <<  this->target_ << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& to_copy )
: AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

RobotomyRequestForm::~RobotomyRequestForm( void ) 
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& to_copy ) 
{
	std::cout << "RobotomyRequestForm copy assignment operator overload called" << std::endl;
	if (this != &to_copy)
	{
		this->AForm::copySignedStatus(to_copy.getSignedStatus());
		this->target_ = to_copy.target_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const throw(GradeTooLowException, FormNotSignedException)
{
	this->AForm::execute(executor);
	srand(time(NULL));
	int	success = std::rand() % 2;//check this
	std::cout << COLOR_BRIGHT_CYAN;
	std::cout << "Vrrrrrrrr...Drrrrrrrr...Vrrrrrrrr" << std::endl;
	std::cout << "     Drrrrrrrr...Vrrrrrrrr...Drrrrrrrr" << std::endl;
	std::cout << "Vrrrrrrrr...Drrrrrrrr...Vrrrrrrrr" << std::endl;
	if (success % 2)
	{
		std::cout << this->target_ << " has been successfully robotomized!" <<std::endl;
	}
	else
	{
		std::cout << "Robotomy has failed." << std::endl;
	}
	std::cout << COLOR_RESET;
	success++;
}
