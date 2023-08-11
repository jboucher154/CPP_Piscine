
#include "Fixed.hpp"
#include <iostream>

/* Initialize Class Memebers */

const int Fixed::_fractionlBits = 8;

/* Constructors */

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_num = to_copy.getRawBits();
}

/* Deconstructor */

Fixed::~Fixed( void ) {
	std::cout << "Deconstructor called" << std::endl;
}

/* Operator Overloads */

Fixed& Fixed::operator = ( Fixed& to_copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point_num = to_copy.getRawBits();
	return (*this);
}

/* Class Public Methods */

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_num);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixed_point_num = raw;
}
