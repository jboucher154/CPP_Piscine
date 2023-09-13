
#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include "Color.hpp"
 
/* CONSTRUCTORS */

ShrubberyCreationForm::ShrubberyCreationForm( void ) 
: AForm("ShrubberyCreationForm", 145, 137), target_("defaultTarget") 
{
	std::cout << "ShrubberyCreationForm default constructor created form for target: " <<  this->target_ << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) 
: AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor created form for target: " <<  this->target_ << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& to_copy )
: AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

ShrubberyCreationForm::~ShrubberyCreationForm( void ) 
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& to_copy ) 
{
	std::cout << "ShrubberyCreationForm copy assignment operator overload called" << std::endl;
	if (this != &to_copy)
	{
		this->AForm::copySignedStatus(to_copy.getSignedStatus());
		this->target_ = to_copy.target_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */
std::string		ShrubberyCreationForm::getTarget( void ) const
{
	return (this->target_);
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const throw(GradeTooLowException, FormNotSignedException)
{
	this->AForm::execute(executor);
	std::string		fname = this->getTarget() + "_shrubbery";
	std::ofstream	shrubFile(fname);  
	if (shrubFile.is_open())
	{
		shrubFile << "                                   									    " << std::endl;
		shrubFile << "         # #### ####                              &&& &&  & &&         " << std::endl;
		shrubFile << "      ### \\/#|### |/####                      && &\\/&\\|& ()|/ @,     " << std::endl;
		shrubFile << "     ##\\/#/ \\||/##/_/##/_#                 &\\/(/&/&||/& /_/)_&/_&    " << std::endl;
		shrubFile << "     ###  \\/###|/ \\/ # ###              &() &\\/&|()|/&\\/ \'%\" & ()    " << std::endl; 
		shrubFile << "   ##_\\_#\\_\\## | #/###_/_####            &_\\_&&_\\ |& |&&/&__%_/_& &&   " << std::endl;
		shrubFile << "  ## #### # \\ #| /  #### ##/##           &&   && & &| &| /& & % ()& /&&  " << std::endl;
		shrubFile << "   __#_--###`  |{,###---###-~             ()&_---()&\\&\\|&&-&&--%---()~   " << std::endl;
		shrubFile << "            \\ }{                              &&     \\|||                " << std::endl;
		shrubFile << "             }}{                                      |||                " << std::endl;
		shrubFile << "             }}{                                      |||                " << std::endl;
		shrubFile << "             {{}                                      |||                " << std::endl;
		shrubFile << "       , -=-~{ .-^- _                                 |||                " << std::endl;
		shrubFile << "             `}                                  , -=-~  .-^- _          " << std::endl;
		shrubFile << "              {                     					 `			   " << std::endl;
		shrubFile << "                                   									     " << std::endl;
		shrubFile << "                                                                             " << std::endl;
		shrubFile << "         &&& &&  & &&                             # #### ####             " << std::endl;
		shrubFile << "      && &\\/&\\|& ()|/ @,                     ### \\/#|### |/####         " << std::endl;
		shrubFile << "    &\\/(/&/&||/& /_/)_&/_&                   ##\\/#/ \\||/##/_/##/_#      " << std::endl;
		shrubFile << " &() &\\/&|()|/&\\/ \'%\" & ()                ###  \\/###|/ \\/ # ###         " << std::endl; 
		shrubFile << "   &_\\_&&_\\ |& |&&/&__%_/_& &&            ##_\\_#\\_\\## | #/###_/_####      " << std::endl;
		shrubFile << " &&   && & &| &| /& & % ()& /&&            ## #### # \\ #| /  #### ##/##     " << std::endl;
		shrubFile << " ()&_---()&\\&\\|&&-&&--%---()~             __#_--###`  |{,###---###-~        " << std::endl;
		shrubFile << "      &&     \\|||                                   \\ }{                    " << std::endl;
		shrubFile << "             |||                                      }}{                   " << std::endl;
		shrubFile << "             |||                                      }}{                   " << std::endl;
		shrubFile << "             |||                                      {{}                   " << std::endl;
		shrubFile << "             |||                                , -=-~{ .-^- _              " << std::endl;
		shrubFile << "        , -=-~  .-^- _                                `}                    " << std::endl;
		shrubFile << "                                                       {                    " << std::endl;
		shrubFile << "                                                                            " << std::endl;
		shrubFile.close();
	}
	else
	{
		std::cerr << "Error: while generating " << fname << " file." << std::endl;
	}
}

