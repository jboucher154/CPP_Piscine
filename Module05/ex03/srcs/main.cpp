
// #include "Bureaucrat.hpp"
#include "Color.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	testInternClass( void )
{
		Intern	intern0;
		Intern	intern1(intern0);
		Intern	intern2 = intern0;
}

void	testInternFormCreation( void )
{
	Intern	intern;

	{
		try
		{
			AForm	*shrubs = intern.makeForm("shrubbery creation", "spaceship");
			AForm	*robo = intern.makeForm("robotomy request", "You");
			AForm	*pres = intern.makeForm("presidential pardon", "Donald Duck");

			std::cout << "Shrubs form : \n" << *shrubs << std::endl;
			std::cout << "Robo form : \n" << *shrubs << std::endl;
			std::cout << "Presform : \n" << *shrubs << std::endl;

			if (shrubs)
				delete	shrubs;
			if (robo)
				delete	robo;
			if (pres)
				delete	pres;
		}
		catch (Intern::InvalidFormException e)
		{
			std::cerr << COLOR_RED << "Test 1: " << e.what() << COLOR_RESET << std::endl;
		}
	}
	{
		try 
		{
			AForm	*shrubs = intern.makeForm("shrubb creation", "My Head");
			std::cout << "Shrubs form : \n" << *shrubs << std::endl;
			if (shrubs)
				delete	shrubs;	
		}
		catch (Intern::InvalidFormException e)
		{
			std::cerr << COLOR_RED << "Test 2: " << e.what() << COLOR_RESET << std::endl;
		}
	}
}

int	main( void )
{
	testInternClass();
	testInternFormCreation();
	return (0);
}
