
#include "AAnimal.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

AAnimal::AAnimal( void ) : type_("Snake") {
	std::cout << "AAnimal default constructor called" << std::endl;
}
	
AAnimal::AAnimal( const AAnimal& to_copy ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = to_copy;
}
	
/* DESTRUCTOR */

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
}
 
/* OPERATOR OVERLOADS */

AAnimal&	AAnimal::operator=( const AAnimal& to_copy ) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &to_copy)
		this->type_ = to_copy.type_;
	return (*this);
}
	
/* CLASS PUBLIC METHODS */

std::string	AAnimal::getType( void ) const {
	return (this->type_);
}

/* CLASS PRIVATE METHODS */
