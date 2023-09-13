
#include "Bureaucrat.hpp"
#include "Color.hpp"

void	testBureaucratExceptionsLow( void ) {
	try {
		Bureaucrat	maggot("maggot", 160);
		std::cout << maggot << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	maggot("maggot", 150);
		std::cout << maggot << std::endl;
		maggot.decrementGrade();
		std::cout << maggot << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	maggot("maggot", INT_MAX);
		std::cout << maggot << std::endl;
		maggot.decrementGrade();
		std::cout << maggot << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	maggot("maggotymaggot", 1);
		std::cout << maggot << std::endl;
		for (int i = 0; i < 150; i++)
		{
			maggot.decrementGrade();
			if (maggot.getGrade() == 1)
				std::cout << maggot.getName() << " reached bottom level!" << std::endl;

		}
		std::cout << maggot << std::endl;
	}
	catch (std::exception& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
}

void	testBureaucratExceptionsHigh( void ) {

	try {
		Bureaucrat	sauron("Sauron", 0);
		std::cout << sauron << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Sauron", 1);
		std::cout << sauron << std::endl;
		sauron.incrementGrade();
		std::cout << sauron << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Sauron", -1);
		std::cout << sauron << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Morgoth", 150);
		std::cout << sauron << std::endl;
		for (int i = 0; i < 150; i++)
		{
			sauron.incrementGrade();
			if (sauron.getGrade() == 1)
				std::cout << sauron.getName() << " reached top level!" << std::endl;
		}
		std::cout << sauron << std::endl;
	}
	catch (std::exception& e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
}

void	testBasicBureaucrat( void ) {
	{	
		Bureaucrat	scum;

		std::cout << scum << std::endl;
		scum.incrementGrade();
		std::cout << scum << std::endl;
		scum.incrementGrade();
		std::cout << scum << std::endl;
		scum.decrementGrade();
		std::cout << scum << std::endl;
		scum.decrementGrade();
		std::cout << scum << std::endl;
	}
	{	
		Bureaucrat	scum("Maggot", 150);

		std::cout << scum << std::endl;
		scum.incrementGrade();
		std::cout << scum << std::endl;
		scum.incrementGrade();
		std::cout << scum << std::endl;
		scum.decrementGrade();
		std::cout << scum << std::endl;
		scum.decrementGrade();
		std::cout << scum << std::endl;
	}
	{	
		Bureaucrat	scum("Orc1", 150);

		std::cout << scum << std::endl;
		scum.incrementGrade();
		std::cout << scum << std::endl;

		Bureaucrat	scum1(scum);
		std::cout << scum1 << std::endl;

		scum1.incrementGrade();
		std::cout << scum << std::endl;
		std::cout << scum1 << std::endl;
		scum.decrementGrade();
		scum1.decrementGrade();
		std::cout << scum << std::endl;
		std::cout << scum1 << std::endl;
	}
	{	
		Bureaucrat	scum("Orc", 150);
		Bureaucrat	midLevel("Uruk-hai", 75);

		std::cout << scum << std::endl;
		std::cout << midLevel << std::endl;
		midLevel = scum;
		std::cout << scum << std::endl;
		std::cout << midLevel << std::endl;		
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
