#include <unistd.h>

/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

void	print_bits(unsigned char octet)
{
	// int bit_location = 7;

	for (int bit_location = 7; bit_location >= 0; bit_location--)
	{	
		//this shifts the 1 to 'line up' with the bit to evaluate and the & 'looks' at the bits to see if they are the same or not
		if (octet & (1 << bit_location))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}
/* another way to do it would be :
	(octet >> bit_location) & 1
	this 'cuts off the least important bits of 'octet' based on the location
	and compares the remaining lleast significant bit to 1
*/

int	main(void)
{
	print_bits(2);
	return (0);
}