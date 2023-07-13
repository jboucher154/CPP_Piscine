
#include <iostream>
#include "Fixed.hpp"

//+ vs +=????
/** The 4 arithmetic operators: +, -, *, and / **/
void	test_arithmetic( void ) {
	Fixed a(1), b(2), c(3);

	std::cout << "starting values: a: " << a << " b: " << b << " c: " << c << std::endl;
	Fixed d = (a + b);
	std::cout << "a + b: " << d << std::endl;
	d = (a - b);
	std::cout << "a - b: " << d << std::endl;
	d = (b * c);
	std::cout << "b * c: " << d << std::endl;
	d = (b / c);
	std::cout << "b / c: " << d << std::endl;
	d = a + b + c;
	std::cout << "a + b + c: " << d << std::endl;
	//test negatives
	
}

int main( void ) { 
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "begin my tests" << std::endl;
	test_arithmetic();
	return (0); 
}
