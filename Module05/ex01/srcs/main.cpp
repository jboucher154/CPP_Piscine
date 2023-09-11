
#include "Bureaucrat.hpp"
#include "Color.hpp"

void	testBureaucratExceptionsLow( void ) {
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
	try {
		Bureaucrat	maggot("maggotymaggot", 1);
		std::cout << maggot;
		for (int i = 0; i < 150; i++)
		{
			maggot.decrementGrade();
			if (maggot.getGrade() == 1)
				std::cout << maggot.getName() << " reached bottom level!" << std::endl;

		}
		std::cout << maggot;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
}

void	testBureaucratExceptionsHigh( void ) {

	try {
		Bureaucrat	sauron("Sauron", 0);
		std::cout << sauron;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Sauron", 1);
		std::cout << sauron;
		sauron.incrementGrade();
		std::cout << sauron;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Sauron", -1);
		std::cout << sauron;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
	}
	try {
		Bureaucrat	sauron("Morgoth", 150);
		std::cout << sauron;
		for (int i = 0; i < 150; i++)
		{
			sauron.incrementGrade();
			if (sauron.getGrade() == 1)
				std::cout << sauron.getName() << " reached top level!" << std::endl;
		}
		std::cout << sauron;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
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

void	testBasicForm( void )
{
	{
		Form	form0("Application", 150, 150);

		std::cout << form0 << std::endl;
	}
	{
		Form	form0("Report", 1, 1);

		std::cout << form0 << std::endl;
	}
	{
		Form	form0("Quote", 1, 150);

		std::cout << form0 << std::endl;
	}
	{
		Form	form0("Triplicate", 150, 150);
		Form	form1(form0);
		Form	form2 = form0;

		std::cout << "form0:" << form0 << std::endl;
		std::cout << "form1:" << form1 << std::endl;
		std::cout << "form2:" << form2 << std::endl;

		Form	form3("Duplication", 2, 75);
		std::cout << "form3:" << form3 << std::endl;
		form3 = form0;
		std::cout << "form3 after = form0:" << form3 << std::endl;

	}
}

void	testCreationExceptionsForm( void )
{
	try
	{
		//high for sign
		Form		test("Query", 0, 150);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//low for sign
		Form	test("Query", 151, 150);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//negative for for sign
		Form	test("Query", -12, 10);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//high for execute
		Form	test("Query", 40, 0);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//low for execute
		Form	test("Query", 40, 160);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//negative for execute
		Form	test("Query", 40, -2);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//both high for execute
		Form	test("Query", 0, 0);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooHighException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
	try
	{
		//both low for execute
		Form	test("Query", 1000, 1000);
		std::cout << test << std::endl;
	}
	catch (Form::GradeTooLowException e)
	{
		std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_MAGENTA << std::endl;
	}
}

void	testBeSignedForm( void )
{
	{
		Form		toSign("Catapult Request", 75, 100);
		Bureaucrat	Midlevel("Pigface", 70);

		std::cout << toSign << std::endl;
		toSign.beSigned(Midlevel);
		std::cout << toSign << std::endl;
	}
	{
		Form		toSign("Catapult Request", 69, 100);
		Bureaucrat	Midlevel("Pigface", 70);

		std::cout << toSign << std::endl;
		try
		{
			toSign.beSigned(Midlevel);
		}
		catch (Form::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_BRIGHT_CYAN << std::endl;
		}
		std::cout << toSign << std::endl;
	}
}

void	testSignFormBureaucrat( void )
{
	{
		Bureaucrat	cog;
		Form		basic;

		std::cout << "\nBefore interactions:\n" << cog << "\n" << basic << std::endl;
		cog.signForm(basic);
		std::cout << "\nAfter interactions:\n" << cog << "\n" << basic << std::endl;
	}
	{
		Bureaucrat	cog("Fred", 149);
		Form		basic;

		std::cout << "\nBefore interactions:\n" << cog << "\n" << basic << std::endl;
		cog.signForm(basic);
		std::cout << "\nAfter interactions:\n" << cog << "\n" << basic << std::endl;
	}
	{
		Bureaucrat	cog("Fred", 100);
		Form		basic;

		std::cout << "\nBefore interactions:\n" << cog << "\n" << basic << std::endl;
		cog.signForm(basic);
		std::cout << "\nAfter interactions:\n" << cog << "\n" << basic << std::endl;
	}
}

int	main( void )
{

	/*std::cout << COLOR_BRIGHT_GREEN << "\nBASIC BUREAUCRAT TESTS\n";
	testBasicBureaucrat();
	std::cout << COLOR_BRIGHT_MAGENTA << "\nBureaucratExceptionsHigh TESTS\n";
	testBureaucratExceptionsHigh();
	std::cout << COLOR_BRIGHT_YELLOW << "\nBureaucratExceptionsLow TESTS\n";
	testBureaucratExceptionsLow();*/
	std::cout << COLOR_BRIGHT_GREEN << "\nBASIC FORM TESTS\n";
	testBasicForm();
	std::cout << COLOR_BRIGHT_MAGENTA << "\nFORM CREATION Exception TESTS\n";
	testCreationExceptionsForm();
	std::cout << COLOR_BRIGHT_CYAN << "\nBE SIGNED FORM TESTS\n";
	testBeSignedForm();
	std::cout << COLOR_BRIGHT_BLUE << "\nSIGN FORM BUREAUCRAT TESTS\n";
	testSignFormBureaucrat();
	std::cout << COLOR_RESET << std::endl;

	return (0);
}
