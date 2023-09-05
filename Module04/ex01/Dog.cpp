
#include "Dog.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->Animal::type_ = "Dog";
	this->brain_ = new Brain();
}
	
Dog::Dog( const Dog& to_copy ) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain_ = NULL;
	*this = to_copy;
}
	
/* DESTRUCTOR */

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain_;
}
 
/* OPERATOR OVERLOADS */

Dog&	Dog::operator=( const Dog& to_copy ) {
	std::cout << "Dog copy assignment operator overload called" << std::endl;
	this->Animal::type_ = to_copy.getType();
	if (this->brain_)
		delete this->brain_;
	this->brain_ = new Brain (*to_copy.brain_);
	return (*this);
}

/* CLASS PUBLIC METHODS */

void	Dog::makeSound( void ) const {
	std::cout << "Ruff" << std::endl;
}

void	Dog::printBrainAddress( void ) const {
	std::cout << "My Brain is located at : " << this->brain_ << std::endl;
}

/* CLASS PRIVATE METHODS */
