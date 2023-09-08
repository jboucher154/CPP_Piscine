
#include "../includes/Bureaucrat.hpp"
#include "../includes/Color.hpp"

void	testBureaucratExceptionsLow( void ) {
	{
		try {
			Bureaucrat	maggot("maggot", 160);
			std::cout << maggot;
		}
		catch (Bureaucrat::GradeTooLowException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try {
			Bureaucrat	maggot("maggot", 150);
			std::cout << maggot;
			maggot.decrementGrade();
			std::cout << maggot;
		}
		catch (Bureaucrat::GradeTooLowException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try {
			Bureaucrat	maggot("maggot", INT_MAX);
			std::cout << maggot;
			maggot.decrementGrade();
			std::cout << maggot;
		}
		catch (Bureaucrat::GradeTooLowException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
}

void	testBureaucratExceptionsHigh( void ) {
	{
		try {
			Bureaucrat	sauron("sauron", 0);
			std::cout << sauron;
		}
		catch (Bureaucrat::GradeTooHighException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try {
			Bureaucrat	sauron("sauron", 1);
			std::cout << sauron;
			sauron.incrementGrade();
			std::cout << sauron;
		}
		catch (Bureaucrat::GradeTooHighException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try {
			Bureaucrat	sauron("sauron", -1);
			std::cout << sauron;
		}
		catch (Bureaucrat::GradeTooHighException e) {
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
}

void	testBasicBureaucrat( void ) {
	{	
		Bureaucrat	scum;

		std::cout << scum;
		scum.incrementGrade();
		std::cout << scum;
		scum.incrementGrade();
		std::cout << scum;
		scum.decrementGrade();
		std::cout << scum;
		scum.decrementGrade();
		std::cout << scum;
	}
	{	
		Bureaucrat	scum("Maggot", 150);

		std::cout << scum;
		scum.incrementGrade();
		std::cout << scum;
		scum.incrementGrade();
		std::cout << scum;
		scum.decrementGrade();
		std::cout << scum;
		scum.decrementGrade();
		std::cout << scum;
	}
	{	
		Bureaucrat	scum("Orc1", 150);

		std::cout << scum;
		scum.incrementGrade();
		std::cout << scum;

		Bureaucrat	scum1(scum);
		std::cout << scum1;

		scum1.incrementGrade();
		std::cout << scum;
		std::cout << scum1;
		scum.decrementGrade();
		scum1.decrementGrade();
		std::cout << scum;
		std::cout << scum1;
	}
	{	
		Bureaucrat	scum("Orc", 150);
		Bureaucrat	midLevel("Uruk-hai", 75);

		std::cout << scum;
		std::cout << midLevel;
		midLevel = scum;
		std::cout << scum;
		std::cout << midLevel;		
	}
}

int	main( void ) {

	std::cout << COLOR_BRIGHT_GREEN << "\nBASIC BUREAUCRAT TESTS\n";
	testBasicBureaucrat();
	std::cout << COLOR_BRIGHT_MAGENTA << "\nBureaucratExceptionsHigh TESTS\n";
	testBureaucratExceptionsHigh();
	std::cout << COLOR_BRIGHT_YELLOW << "\nBureaucratExceptionsLow TESTS\n";
	testBureaucratExceptionsLow();
	std::cout << COLOR_RESET << std::endl;
	return (0);
}
