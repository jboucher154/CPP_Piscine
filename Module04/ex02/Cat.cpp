
#include "Cat.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Cat::Cat( void ) : AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->AAnimal::type_ = "Cat";
	this->brain_ = new Brain();
}
	
Cat::Cat( const Cat& to_copy ) : AAnimal() {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain_ = new Brain();
	*this = to_copy;
}

/* DESTRUCTOR */

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain_;
}

/* OPERATOR OVERLOADS */

Cat&	Cat::operator=( const Cat& to_copy ) {
	std::cout << "Cat copy assignment operator overload called" << std::endl;
	if (this != &to_copy) {
		this->AAnimal::type_ = to_copy.getType();
		*this->brain_ = *to_copy.brain_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

void	Cat::makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}

void	Cat::printBrainAddress( void ) const {
	std::cout << "My Brain is located at : " << this->brain_ << std::endl;
}

/* CLASS PRIVATE METHODS */
