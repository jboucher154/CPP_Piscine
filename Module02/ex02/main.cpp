
#include <iostream>
#include "Fixed.hpp"

//+ vs +=????
/** The 4 arithmetic operators: +, -, *, and / **/
void	test_arithmetic( void ) {
	Fixed a, b;

	std::cout << "starting values: a: " << a << " b: " << b << std::endl;
	a + 1;
	std::cout << "add 1 to a: " << a << std::endl;
	b - 1;
	std::cout << "subtract 1 from b: " << b << std::endl;
	a - b;
	std::cout << "a minus b: " << a << std::endl; //comes out as 2
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
