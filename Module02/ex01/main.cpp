
#include <iostream>
#include "Fixed.hpp"

#include <unistd.h> //testing
void	print_bits(int to_print)
{
	// int bit_location = 7;

	for (int bit_location = 32; bit_location >= 0; bit_location--)
	{	
		//this shifts the 1 to 'line up' with the bit to evaluate and the & 'looks' at the bits to see if they are the same or not
		if (to_print & (1 << bit_location))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}

int main( void ) {
	// Fixed a;
	// Fixed b( a );
	// Fixed c;
	// c = b;
	
	// std::cout << a.getRawBits() << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	float test = 16.1;

	// std::cout << sizeof(int);
	std::cout << "Test before shift: " << test << std::endl;
	std::cout << "Test bits before shift: " << std::endl;
	print_bits(test);
	// int	test_int = test << 8;
	int test_int = test * (1 << 8);
	std::cout <<"Test after shift: " << test_int << std::endl;
	std::cout << "Test bits after shift: " << std::endl;
	print_bits(test_int);
	return 0; 
}