
#include "WrongCat.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->WrongAnimal::type_ = "Cat";
}
	
WrongCat::WrongCat( const WrongCat& to_copy ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = to_copy;
}
 
/* DESTRUCTOR */

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}
 
/* OPERATOR OVERLOADS */

WrongCat&	WrongCat::operator=( const WrongCat& to_copy ) {
	std::cout << "WrongCat copy assignment operator overload called" << std::endl;
	this->WrongAnimal::type_ = to_copy.getType();
	return (*this);
}

/* CLASS PUBLIC METHODS */

void		WrongCat::makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}

/* CLASS PRIVATE METHODS */
