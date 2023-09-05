
#include "WrongAnimal.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

WrongAnimal::WrongAnimal( void ) : type_("Snake") {
		std::cout << "WrongAnimal default constructor called" << std::endl;
}
	
WrongAnimal::WrongAnimal( const WrongAnimal& to_copy ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = to_copy;
}

/* DESTRUCTOR */

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* OPERATOR OVERLOADS */

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& to_copy ) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &to_copy)
		this->type_ = to_copy.type_;
	return (*this);
}

/* CLASS PUBLIC METHODS */

std::string	WrongAnimal::getType( void ) const {
	return (this->type_);
}

void		WrongAnimal::makeSound( void ) const {
	std::cout << "Sssssssssssss" << std::endl;
}

/* CLASS PRIVATE METHODS */
