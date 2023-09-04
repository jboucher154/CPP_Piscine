
#include "Dog.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->Animal::type_ = "Dog";
}
	
Dog::Dog( const Dog& to_copy ) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = to_copy;
}
	
/* DESTRUCTOR */

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}
 
/* OPERATOR OVERLOADS */

Dog&	Dog::operator=( const Dog& to_copy ) {
	std::cout << "Dog copy assignment operator overload called" << std::endl;
	this->Animal::type_ = to_copy.getType();
	return (*this);
}

/* CLASS PUBLIC METHODS */

void		Dog::makeSound( void ) const {
	std::cout << "Ruff" << std::endl;
}

/* CLASS PRIVATE METHODS */
