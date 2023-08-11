
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/* Initialize Class Members */

const int Fixed::_fractionlBits = 8;

/* CONSTRUCTORS */

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int iNum ) : _fixed_point_num(0) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_num = (iNum << Fixed::_fractionlBits);
}

Fixed::Fixed( const float fpNum) : _fixed_point_num(0) { 
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_num = int (std::roundf(fpNum * static_cast<float>((1 << Fixed::_fractionlBits))));
}

Fixed::Fixed( const Fixed& to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

/*  DECONSTRUCTOR */

Fixed::~Fixed( void ) {
	std::cout << "Deconstructor called" << std::endl;
}

/* ASSIGNMENT OPERATOR OVERLOAD */

Fixed& Fixed::operator = ( const Fixed& to_copy ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_copy)
		this->_fixed_point_num = to_copy.getRawBits();
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const Fixed& to_print) {
	output_stream << to_print.toFloat();
	return (output_stream);
}

/* CLASS PUBLIC METHODS */

int		Fixed::getRawBits( void ) const {
	return (this->_fixed_point_num);
}

void	Fixed::setRawBits( const int raw ) {
	
	this->_fixed_point_num = raw;
}

float	Fixed::toFloat( void ) const {
	return (float(this->_fixed_point_num) / (1 << Fixed::_fractionlBits));
}

int		Fixed::toInt( void ) const {
	return (this->_fixed_point_num >> Fixed::_fractionlBits);
}
