
#include "../includes/Bureaucrat.hpp"

 
/* CONSTRUCTORS */
Bureaucrat::Bureaucrat( void ) : name_("defaultBureaucrat"), grade_(150) {
	std::cout << "Default Bureaucrat constructor" << std::endl;
}
	
Bureaucrat::Bureaucrat( std::string const name, int grade ) : name_(name) {
	std::cout << "Parameterized Bureaucrat constructor" << std::endl;
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw(GradeTooLowException());
	}
	this->grade_ = grade;
}
	
Bureaucrat::Bureaucrat( const Bureaucrat& to_copy ) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = to_copy;
}
	
 
/* DESTRUCTOR */
Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat destructor" << std::endl;
}
	
 
/* OPERATOR OVERLOADS */
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& to_copy ) {
	std::cout << "Bureaucrat copy assigment operator overload" << std::endl;
	if (this != &to_copy) {
		// this->name_ = to_copy.name_;//const...cannot change?
		this->grade_ = to_copy.grade_;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& output_stream, const Bureaucrat& to_print) {
	output_stream << to_print.getName() << ", bureaucrat grade " << to_print.getGrade() << "." << std::endl;
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

std::string const	Bureaucrat::getName( void ) const {
	return (this->name_);
}

unsigned int	Bureaucrat::getGrade( void ) const {
	return (this->grade_);
}

void	Bureaucrat::incrementGrade( void ) {
	if (this->grade_ - 1 < 1) {
		throw (GradeTooHighException());
	}
	else {
		this->grade_--;
	}
}
void	Bureaucrat::decrementGrade( void ) {
	if (this->grade_ + 1 > 150) {
		throw (GradeTooLowException());
	}
	else {
		this->grade_++;
	}
}

/* CLASS PRIVATE METHODS */

/* NESTED CLASSES */

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade is too low");
}