#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
// # include <string>

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
		virtual void	execute( const Bureaucrat& executor ) const throw(GradeTooLowException, FormNotSignedException);
		
	private:
		std::string	target_;
};

#endif
