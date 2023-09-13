#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& to_copy );

		~ShrubberyCreationForm( void );

		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& to_copy );

		/* PUBLIC METHODS */
		virtual void	execute(const Bureaucrat& executor) const throw(GradeTooLowException, FormNotSignedException);
		std::string		getTarget( void ) const;
		
	private:
		std::string	target_;
};

#endif
