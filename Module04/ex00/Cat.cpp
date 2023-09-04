
#include "Cat.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	this->Animal::type_ = "Cat";
}
	
// Cat::Cat( /*add parameters*/ ) {
// 	/* parameterized constructor */
// }
	
Cat::Cat( const Cat& to_copy ) {
	/* copy constructor */
}
	
 
/* DESTRUCTOR */

Cat::~Cat( void ) {
	/* destructor */
}
	
 
/* OPERATOR OVERLOADS */

Cat&	Cat::operator=( const Cat& to_copy ) {
	/* copy assignment operator overload */
}
	

/* CLASS PUBLIC METHODS */

void		makeSound( void ) const {
	std::cout << "Meow" << std::endl;
}

/* CLASS PRIVATE METHODS */
