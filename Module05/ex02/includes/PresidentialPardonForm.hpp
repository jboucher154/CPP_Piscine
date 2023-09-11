#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class Bureaucrat;

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& to_copy );

		~PresidentialPardonForm( void );

		PresidentialPardonForm&	operator=( const PresidentialPardonForm& to_copy );

		/* PUBLIC METHODS */
		virtual void	execute(Bureaucrat const & executor) const throw(GradeTooLowException);
		
	private:
		std::string	target_;
};

#endif
