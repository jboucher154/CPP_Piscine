
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fractionlBits = 8;

/* CONSTRUCTORS */

Fixed::Fixed( void ) : _fixed_point_num(0) {}

Fixed::Fixed( const int fpNum ) : _fixed_point_num(0) {
	this->_fixed_point_num = (fpNum << Fixed::_fractionlBits);
}

Fixed::Fixed( const float fpNum) : _fixed_point_num(0) { 
	this->_fixed_point_num = int (std::roundf(fpNum * (1 << Fixed::_fractionlBits)));
}

Fixed::Fixed( const Fixed& to_copy ) {
	*this = to_copy;
}

/* DECONSTRUCTOR */

Fixed::~Fixed( void ) {
	// std::cout << "Deconstructor called" << std::endl;
}

/* OPERATOR OVERLOADERS */

Fixed& Fixed::operator = (const Fixed& to_copy) {
	this->_fixed_point_num = to_copy.getRawBits();
	return (*this);
}

std::ostream&	operator << (std::ostream& output_stream, const Fixed& to_print) {
	output_stream << to_print.toFloat();
	return (output_stream);
}

/** The 6 comparison operators: >, <, >=, <=, == and != **/

bool	Fixed::operator > (const Fixed& rhs) {
	return (this->_fixed_point_num > rhs.getRawBits());
}

bool	Fixed::operator < (const Fixed& rhs) {
	return (this->_fixed_point_num < rhs.getRawBits());
}

bool	Fixed::operator >= (const Fixed& rhs) {
	return (this->_fixed_point_num >= rhs.getRawBits());
}

bool	Fixed::operator <= (const Fixed& rhs) {
	return (this->_fixed_point_num <= rhs.getRawBits());
}

bool	Fixed::operator == (const Fixed& rhs) {
	return (this->_fixed_point_num == rhs.getRawBits());
}

bool	Fixed::operator != (const Fixed& rhs) {
	return (this->_fixed_point_num != rhs.getRawBits());
}

/** The 4 arithmetic operators: +, -, *, and / **/

Fixed Fixed::operator + ( const Fixed& rhs) {
	Fixed res;
	res._fixed_point_num =  this->_fixed_point_num + rhs.getRawBits();
	return (res);
}

Fixed Fixed::operator - ( const Fixed& rhs) {
	Fixed res;
	res._fixed_point_num = this->_fixed_point_num - rhs.getRawBits();
	return (res);
}

Fixed Fixed::operator * ( const Fixed& rhs) {
	Fixed res;
	res._fixed_point_num = ((int64_t)this->_fixed_point_num  * (int64_t)rhs.getRawBits()) >> Fixed::_fractionlBits;
	return (res);
}

Fixed Fixed::operator / ( const Fixed& rhs) {
	Fixed res;
	res._fixed_point_num = ((int64_t)this->_fixed_point_num * (1 << Fixed::_fractionlBits)) / (int64_t)rhs.getRawBits();
	return (res);
}

/** The 4 increment/decrement (prefix and postfix **/

Fixed&	Fixed::operator ++ ( void ) {
	this->_fixed_point_num += 1;
	return (*this);
}

Fixed	Fixed::operator ++ ( int ) {
	Fixed temp = *this;

	this->_fixed_point_num += 1;
	return (temp);
}

Fixed&	Fixed::operator -- ( void ) {
	this->_fixed_point_num -= 1;
	return (*this);
}

Fixed	Fixed::operator -- ( int ) {
	Fixed temp(*this);

	this->_fixed_point_num -= 1;
	return (temp);
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

const Fixed&	Fixed::min( const Fixed& one, const Fixed& two ) {
	if (one.getRawBits() < two.getRawBits())
		return (one);
	return (two);
}

Fixed&	Fixed::min( Fixed& one, Fixed& two ) {
	if (one < two)
		return (one);
	return (two);
}

const Fixed&	Fixed::max( const Fixed& one, const Fixed& two ) {
	if (one.getRawBits() > two.getRawBits())
		return (one);
	return (two);
}

Fixed&	Fixed::max( Fixed& one, Fixed& two ) {
	if (one > two)
		return (one);
	return (two);
}
