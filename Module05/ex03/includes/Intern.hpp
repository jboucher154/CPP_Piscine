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
		AForm*	makeForm( std::string formName, std::string formTarget);
		
	private:
		ShrubberyCreationForm*	makeShrubForm( std::string target );
		RobotomyRequestForm*	makeForm( std::string target );
		ShrubberyCreationForm*	makeShrubForm( std::string target );
};

#endif
