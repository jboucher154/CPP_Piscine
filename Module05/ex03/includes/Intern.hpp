#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	AForm;

// class	ShrubbryCreationForm;
// class	PresidentialPardonForm;
// class	RobotomyRequestForm;

class	Intern 
{
	public:
		Intern( void );
		Intern( const Intern& to_copy );

		~Intern( void );

		Intern&	operator=( const Intern& to_copy );

		/* PUBLIC METHODS */
		AForm*	makeForm( std::string formName, std::string formTarget) throw (InvalidFormException);
		/* NESTED CLASSES */
		class	InvalidFormException : public std::exception
		{
			public:
				virtual const char*	what( void ) const throw();
		};
		

	private:
		typedef	AForm*	(Intern::*t_possibleForms[])(std::string);
		AForm*	makeShrubForm( std::string const target );
		AForm*	makeRobotomyForm( std::string const target );
		AForm*	makePresidentialForm( std::string const target );
};

#endif
