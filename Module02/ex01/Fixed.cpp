
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionlBits = 8;

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

//should convert the param to the fixed point num
Fixed::Fixed( const int fpNum ) : _fixed_point_num(0) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_num = (fpNum << Fixed::_fractionlBits);
}

//converts it to the corresponding fixed-point value.
Fixed::Fixed( const float fpNum) : _fixed_point_num(0) { 
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_num = int (std::roundf(fpNum * (1 << Fixed::_fractionlBits))); //may need to round up for accuracy? --> added roundf
}

//could use the assignment operator call here
Fixed::Fixed( const Fixed& to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	// this->_fixed_point_num = to_copy.getRawBits();
	*this = to_copy;
}

Fixed::~Fixed( void ) {
	std::cout << "Deconstructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& to_copy) {
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

float	Fixed::toFloat( void ) const {
	// std::cout << "to_float member function called" << std::endl;
	return (float(this->_fixed_point_num) / (1 << Fixed::_fractionlBits)); //rounding issues?
}

int		Fixed::toInt( void ) const {
	// std::cout << "to_int member function called" << std::endl;
	return (this->_fixed_point_num >> Fixed::_fractionlBits);
}

std::ostream&	operator<<(std::ostream& output_stream, const Fixed& to_print) {
	output_stream << to_print.toFloat();
	return (output_stream);
}
