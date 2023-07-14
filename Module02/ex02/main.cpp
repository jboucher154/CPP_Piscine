
#include <iostream>
#include "Fixed.hpp"

/** min/max **/
void	test_min_max( void ) {
	std::cout << "\n MIN MAX TESTS\n";
	Fixed a(1), b(2), c(3), d(3);

	Fixed temp;
	std::cout << "starting values: a: " << a << " b: " << b << " c: " << c << "d: " << d << std::endl;
	//min tests
	temp = temp.min(a, b);
	std::cout << "min from a & b: " << temp << std::endl;
	temp = temp.min(b, a);
	std::cout << "min from b & a: " << temp << std::endl;
	temp = temp.min(c, b);
	std::cout << "min from c & b: " << temp << std::endl;
	temp = temp.min(d, c);
	std::cout << "min from d & c: " << temp << std::endl;

	//max tests
	temp = temp.max(a, b);
	std::cout << std::endl << "max from a & b: " << temp << std::endl;
	temp = temp.max(b, a);
	std::cout << "max from b & a: " << temp << std::endl;
	temp = temp.max(c, b);
	std::cout << "max from c & b: " << temp << std::endl;
	temp = temp.max(d, c);
	std::cout << "max from d & c: " << temp << std::endl;

	//constants
	//min tests
	Fixed const e(2), f(3), g(5.15f), h(5.15f);

	std::cout << std::endl << "starting values: e: " << e << " f: " << f << " g: " << g << " h: " << h << std::endl;
	temp = temp.min(e, f);
	std::cout << "min from e & f: " << temp << std::endl;
	temp = temp.min(f, e);
	std::cout << "min from f & e: " << temp << std::endl;
	temp = temp.min(g, f);
	std::cout << "min from g & f: " << temp << std::endl;
	temp = temp.min(h, g);
	std::cout << "min from d & g: " << temp << std::endl;

	//max tests
	temp = temp.max(e, f);
	std::cout << std::endl << "max from e & f: " << temp << std::endl;
	temp = temp.max(f, e);
	std::cout << "max from f & e: " << temp << std::endl;
	temp = temp.max(g, f);
	std::cout << "max from g & f: " << temp << std::endl;
	temp = temp.max(h, g);
	std::cout << "max from h & g: " << temp << std::endl;
}

/** The 6 comparison operators: >, <, >=, <=, == and != **/
void	test_comparisons( void ) {
	std::cout << "\n COMPARISON TESTS\n";
	Fixed a(1), b(2), c(3), d(3);

	std::cout << "starting values: a: " << a << " b: " << b << " c: " << c << "d: " << d << std::endl;
	std::cout << "test comparison > : a > b: " << (a > b) << " b > a: " << (b > a) << " b > c: " << (b > c) << std::endl;
	std::cout << "test comparison < : a < b: " << (a < b) << " b < a: " << (b < a) << " b < c: " << (b < c) << std::endl;
	std::cout << "test comparison >= : a >= b: " << (a >= b) << " b >= a: " << (b >= a) << " d >= c: " << (d >= c) << std::endl;
	std::cout << "test comparison <= : a <= b: " << (a <= b) << " b <= a: " << (b <= a) << " d <= c: " << (d <= c) << std::endl;
	std::cout << "test comparison == : a == b: " << (a == b) << " b == a: " << (b == a) << " d == c: " << (d == c) << std::endl;
	std::cout << "test comparison != : a != b: " << (a != b) << " b != a: " << (b != a) << " d != c: " << (d != c) << std::endl;
}

/** The 4 increment/decrement (prefix and postfix **/
void	test_inc_dec( void ) {
	std::cout << "\n INCREMENTOR TESTS\n";
	Fixed a(1), b(2), c(3);

	std::cout << "starting values: a: " << a << " b: " << b << " c: " << c << std::endl;
	std::cout << "test prefix incrementor: a: " << ++a << " b: " << ++b << " c: " << ++c << std::endl;
	std::cout << "test postfix incrementor (should be same as before): a: " << a++ << " b: " << b++ << " c: " << c++ << std::endl;
	std::cout << "test postfix incrementor (should be diff now): a: " << a << " b: " << b << " c: " << c << std::endl;
	//decrementor
	std::cout << "test prefix decrementor should be back to first increment: a: " << --a << " b: " << --b << " c: " << --c << std::endl;
	std::cout << "test postfix decrementor (should be same as before): a: " << a-- << " b: " << b-- << " c: " << c-- << std::endl;
	std::cout << "test postfix decrementor (should be back to og values now): a: " << a << " b: " << b << " c: " << c << std::endl;
}

/** The 4 arithmetic operators: +, -, *, and / **/
void	test_arithmetic( void ) {
	std::cout << "\n ARITHMETIC TESTS\n";
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
	
	Fixed e(-1), f(-6), g(-42);

	std::cout << "e + f: " << d << std::endl;
	d = (e - f);
	std::cout << "e - f: " << d << std::endl;
	d = (f * g);
	std::cout << "f * g: " << d << std::endl;
	d = (f / g);
	std::cout << "f / g: " << d << std::endl;
	d = e + f + g;
	std::cout << "e + f + g: " << d << std::endl;
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

	std::cout << "BEGIN MY TESTS" << std::endl;
	test_arithmetic();
	std::cout << std::endl;
	test_inc_dec();
	std::cout << std::endl;
	test_comparisons();
	std::cout << std::endl;
	test_min_max();
	std::cout << std::endl;
	return (0); 
}
