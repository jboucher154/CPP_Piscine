
#include "Cat.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Cat::Cat( void ) : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->Animal::type_ = "Cat";
}
	
Cat::Cat( const Cat& to_copy ) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = to_copy;
}

/* DESTRUCTOR */

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

Cat&	Cat::operator=( const Cat& to_copy ) {
	std::cout << "Cat copy assignment operator overload called" << std::endl;
	if (this != &to_copy)
		this->Animal::type_ = to_copy.getType();
	return (*this);
}

/* CLASS PUBLIC METHODS */

void		Cat::makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}

/* CLASS PRIVATE METHODS */
