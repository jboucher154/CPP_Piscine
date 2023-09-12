
#include "Bureaucrat.hpp"
#include "Color.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testRobotomyRequestFormClass( void )
{
	{
		RobotomyRequestForm	form0("Fred");

		std::cout << form0 << std::endl;
	}
	{
		RobotomyRequestForm	form0("NewGuy");

		std::cout << form0 << std::endl;
	}
	{
		RobotomyRequestForm	form0("Sharon");

		std::cout << form0 << std::endl;
	}
	{
		RobotomyRequestForm	form0("Thrice");
		RobotomyRequestForm	form1(form0);
		RobotomyRequestForm	form2 = form0;

		std::cout << "form0:" << form0 << std::endl;
		std::cout << "form1:" << form1 << std::endl;
		std::cout << "form2:" << form2 << std::endl;

		RobotomyRequestForm	form3("Twin");
		std::cout << "form3:" << form3 << std::endl;
		form3 = form0;
		std::cout << "form3 after = form0:" << form3 << std::endl;
	}
}

void	testShrubberyCreationFormClass( void )
{
	{
		ShrubberyCreationForm	form0("Front Lawn");

		std::cout << form0 << std::endl;
	}
	{
		ShrubberyCreationForm	form0("Yard");

		std::cout << form0 << std::endl;
	}
	{
		ShrubberyCreationForm	form0("Fountainside");

		std::cout << form0 << std::endl;
	}
	{
		ShrubberyCreationForm	form0("Triple_Park");
		ShrubberyCreationForm	form1(form0);
		ShrubberyCreationForm	form2 = form0;

		std::cout << "form0:" << form0 << std::endl;
		std::cout << "form1:" << form1 << std::endl;
		std::cout << "form2:" << form2 << std::endl;

		ShrubberyCreationForm	form3("Duplex");
		std::cout << "form3:" << form3 << std::endl;
		form3 = form0;
		std::cout << "form3 after = form0:" << form3 << std::endl;
	}
}

void	testPresidentialPardonFormClass( void )
{
	{
		PresidentialPardonForm	form0("Zaphod Beeblebrox");

		std::cout << form0 << std::endl;
	}
	{
		PresidentialPardonForm	form0("Zaphod Beeblebrox's mom");

		std::cout << form0 << std::endl;
	}
	{
		PresidentialPardonForm	form0("His own assistant");

		std::cout << form0 << std::endl;
	}
	{
		PresidentialPardonForm	form0("Towels");
		PresidentialPardonForm	form1(form0);
		PresidentialPardonForm	form2 = form0;

		std::cout << "form0:" << form0 << std::endl;
		std::cout << "form1:" << form1 << std::endl;
		std::cout << "form2:" << form2 << std::endl;

		PresidentialPardonForm	form3("Dolphins");
		std::cout << "form3:" << form3 << std::endl;
		form3 = form0;
		std::cout << "form3 after = form0:" << form3 << std::endl;

	}
}

void	testFormExecution( void )
{
	Bureaucrat	testCog1("Vogon1", 150);
	Bureaucrat	testCog2("Chief Vogon", 4);

	{
		RobotomyRequestForm		roboForm("NewGuy");
		ShrubberyCreationForm	shrubForm("Front Lawn");
		PresidentialPardonForm	presForm("Zaphod Beeblebrox");

		//-form that is not signed, but not quaified
		try 
		{
			roboForm.execute(testCog1);
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			shrubForm.execute(testCog1);
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			presForm.execute(testCog1);
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		//-form that is not signed, but quaified
		try 
		{
			roboForm.execute(testCog2);
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			shrubForm.execute(testCog2);
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			presForm.execute(testCog2);		
		}
		catch (AForm::FormNotSignedException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
	{
		RobotomyRequestForm		roboForm("NewGuy");
		ShrubberyCreationForm	shrubForm("Front Lawn");
		PresidentialPardonForm	presForm("Zaphod Beeblebrox");

		roboForm.beSigned(testCog2);
		shrubForm.beSigned(testCog2);
		presForm.beSigned(testCog2);
		//-form that is signed, but not quaified
		try 
		{
			roboForm.execute(testCog1);
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			shrubForm.execute(testCog1);
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			presForm.execute(testCog1);
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		//-form that is signed, and quaified
		try 
		{
			roboForm.execute(testCog2);
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			shrubForm.execute(testCog2);
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
		try 
		{
			presForm.execute(testCog2);		
		}
		catch (AForm::GradeTooLowException e)
		{
			std::cout << COLOR_BRIGHT_RED << e.what() << COLOR_RESET << std::endl;
		}
	}
}

// void	testBureaucratFormExecution( void )
// {
		//test bureaucrat
		/*
		-qualified, not signed
		-qualified signed
		-unqualified, not signed
		-qualified, signed
		*/

// }

/*
TODO-- add check for form signature before execution
TODO-- make more pedantic print statements
*/

int	main( void )
{
	std::cout << COLOR_BRIGHT_BLUE << std::endl;
	testRobotomyRequestFormClass();
	std::cout << COLOR_BRIGHT_GREEN << std::endl;
	testShrubberyCreationFormClass();
	std::cout << COLOR_BRIGHT_MAGENTA << std::endl;
	testPresidentialPardonFormClass();
	std::cout << COLOR_BRIGHT_YELLOW << std::endl;
	testFormExecution();
	std::cout << COLOR_RESET << std::endl;
	return (0);
}
