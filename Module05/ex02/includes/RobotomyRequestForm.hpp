#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

class Bureaucrat;

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& to_copy );

		~RobotomyRequestForm( void );

		RobotomyRequestForm&	operator=( const RobotomyRequestForm& to_copy );

		/* PUBLIC METHODS */
		virtual void	execute(Bureaucrat const & executor) const throw(GradeTooLowException);

	private:
		std::string	target_;
};

#endif
