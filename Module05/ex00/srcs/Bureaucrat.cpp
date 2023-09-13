
#include "Bureaucrat.hpp"
 
/* CONSTRUCTORS */

Bureaucrat::Bureaucrat( void ) : name_("standardIssueBureaucrat"), grade_(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
	
Bureaucrat::Bureaucrat( std::string name, int grade ) throw(GradeTooHighException, GradeTooLowException) 
: name_(name) {
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw (GradeTooLowException());
	}
	this->grade_ = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& to_copy ) : name_(to_copy.getName()){
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

Bureaucrat::~Bureaucrat( void ) {
		std::cout << "Bureaucrat destructor called" << std::endl;
}
/* OPERATOR OVERLOADS */

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& to_copy ) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &to_copy) {
		this->grade_ = to_copy.getGrade();
	}
	return (*this);
}
//include endl or no?
std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print) {
	output_stream << to_print.getName() << ", bureaucrat grade " << to_print.getGrade();
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

std::string const	Bureaucrat::getName( void ) const {
	return (this->name_);
}

int	Bureaucrat::getGrade( void ) const {
	return (this->grade_);
}

void	Bureaucrat::incrementGrade( void ) throw(GradeTooHighException) {
	if (this->grade_ == 1) {
		throw (GradeTooHighException());
	}
	else {
		this->grade_--;
	}
}

void	Bureaucrat::decrementGrade( void ) throw(GradeTooLowException){
	if (this->grade_ == 150) {
		throw (GradeTooLowException());
	}
	else {
		this->grade_++;
	}
}

/* NESTED CLASS METHODS */

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade is too low");
}