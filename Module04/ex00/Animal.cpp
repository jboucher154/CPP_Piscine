
#include "Animal.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Animal::Animal( void ) : type_("Snake") {
	std::cout << "Animal default constructor called" << std::endl;
}
	
Animal::Animal( const Animal& to_copy ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = to_copy;
}
	
/* DESTRUCTOR */

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}
 
/* OPERATOR OVERLOADS */

Animal&	Animal::operator=( const Animal& to_copy ) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &to_copy)
		this->type_ = to_copy.type_;
	return (*this);
}
	
/* CLASS PUBLIC METHODS */

std::string	Animal::getType( void ) const {
	return (this->type_);
}

void		Animal::makeSound( void ) const {
	std::cout << "Sssssssssssss" << std::endl;
}

/* CLASS PRIVATE METHODS */
