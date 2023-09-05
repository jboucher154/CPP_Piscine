
#include "Brain.hpp"
#include <iostream>
 
/* CONSTRUCTORS */

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
	this->ideas_[0] = "My brain is empty...";
	for (int i = 1; i < 100; i++)
		this->ideas_[i] = "";
}
	
Brain::Brain( const Brain& to_copy ) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = to_copy;
}

/* DESTRUCTOR */

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}
 
/* OPERATOR OVERLOADS */

Brain&	Brain::operator=( const Brain& to_copy ) {
	std::cout << "Brain copy assignment operator overload called" << std::endl;
	if (this != &to_copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas_[i] = to_copy.ideas_[i];
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

/* CLASS PRIVATE METHODS */
