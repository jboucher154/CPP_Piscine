
#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractionlBits = 8;

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

//should convert the param to the fixed point num
Fixed::Fixed( const int fpNum ) : _fixed_point_num(0) {
	std::cout << "Paramaterized constructor called" << std::endl;
	this->_fixed_point_num = fpNum << Fixed::_fractionlBits;
}

//converts it to the corresponding fixed-point value.
Fixed::Fixed( const float fpNum) : _fixed_point_num(0) {
	
}

//could use the assignment operator call here
Fixed::Fixed( Fixed& to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_num = to_copy.getRawBits();
}

Fixed::~Fixed( void ) {
	std::cout << "Deconstructor called" << std::endl;
}

Fixed& Fixed::operator=( Fixed& to_copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point_num = to_copy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_num);
}

void	Fixed::setRawBits( const int raw ) {
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixed_point_num = raw;
}

float	Fixed::to_float( void ) const {
	std::cout << "to_float member function called" << std::endl;
}

int		Fixed::to_int( void ) const {
	std::cout << "to_int member function called" << std::endl;
	return (this->_fixed_point_num >> Fixed::_fractionlBits);
}

std::ostream&	operator<<(std::ostream& output_stream, const Fixed& to_print) {
	output_stream << to_print.to_float();
	return (output_stream);
}
