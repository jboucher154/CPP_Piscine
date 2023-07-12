
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionlBits = 8;

/* CONSTRUCTORS */

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int fpNum ) : _fixed_point_num(0) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_num = (fpNum << Fixed::_fractionlBits);
}

Fixed::Fixed( const float fpNum) : _fixed_point_num(0) { 
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_num = int (std::roundf(fpNum * (1 << Fixed::_fractionlBits)));
}

Fixed::Fixed( const Fixed& to_copy ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

/* DECONSTRUCTOR */

Fixed::~Fixed( void ) {
	std::cout << "Deconstructor called" << std::endl;
}

/* OPERATOR OVERLOADERS */

Fixed& Fixed::operator = (const Fixed& to_copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point_num = to_copy.getRawBits();
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const Fixed& to_print) {
	output_stream << to_print.toFloat();
	return (output_stream);
}

// The 6 comparison operators: >, <, >=, <=, == and !=.
bool	Fixed::operator > (const Fixed& rhs) {

}
bool	Fixed::operator < (const Fixed& rhs) {

}
bool	Fixed::operator >= (const Fixed& rhs) {

}
bool	Fixed::operator <= (const Fixed& rhs) {

}
bool	Fixed::operator == (const Fixed& rhs) {

}
bool	Fixed::operator != (const Fixed& rhs) {

}

// The 4 arithmetic operators: +, -, *, and /.
Fixed& Fixed::operator + (const Fixed& rhs) {
	this->_fixed_point_num += rhs.getRawBits();//check this
	return (*this);
}

Fixed& Fixed::operator - (const Fixed& rhs) {
	this->_fixed_point_num -= rhs.getRawBits();//check this
	return (*this);
}

Fixed& Fixed::operator * (const Fixed& rhs) {
	this->_fixed_point_num = ((int64_t)this->_fixed_point_num  * (int64_t)rhs.getRawBits()) >> 16;//check this
	return (*this);
}

Fixed& Fixed::operator / (const Fixed& rhs) {

}

//  The 4 increment/decrement (pre-increment and post-increment, 
// pre-decrement and post-decrement) operators, that will increase 
// or decrease the fixed-point value from the smallest representable ε such as 1 + ε > 1.

void	Fixed::operator ++ (const int incrementor) {}
void	Fixed::operator -- (const int decrementor) {}

/* CLASS METHODS */

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
	return (float(this->_fixed_point_num) / (1 << Fixed::_fractionlBits));
}

int		Fixed::toInt( void ) const {
	// std::cout << "to_int member function called" << std::endl;
	return (this->_fixed_point_num >> Fixed::_fractionlBits);
}

////////// NEW STUFFS
// 		Add these four public overloaded member functions to your class:
// • A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
Fixed&	Fixed::min(const Fixed& one, const Fixed& two) {}
Fixed&	Fixed::min(Fixed& one, Fixed& two) {}

// • A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
Fixed&	Fixed::max(const Fixed& one, const Fixed& two) {}
Fixed&	Fixed::max(Fixed& one, Fixed& two) {}
