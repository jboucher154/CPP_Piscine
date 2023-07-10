#include <unistd.h>
/*
	Write a function that takes a byte, reverses it, bit by bit (like the
	example) and returns the result.

	Your function must be declared as follows:

	unsigned char	reverse_bits(unsigned char octet);

	Example:

	1 byte
	_____________
	0010  0110
		||
		\/
	0110  0100
*/

// do all the operators only affect the least significant bit?
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char new_value = 0;

// this works too!
	// int constant = 128;
	// while (constant > 0)
	// {
	// 	new_value = new_value +( constant * (octet % 2));
	// 	octet = octet / 2;
	// 	constant  = constant/2;
	// }

	for (int place =  0; place < 8; place++)
	{
		new_value = new_value << 1;
		//reverse the newy placed bit based on the passed octet least significant bit
		new_value = new_value | ((octet >> place)& 1);
		// this is changing the bit that is being used to '|' the newly paced bit in new_value
		// octet  = octet >> 1; 
	}
	return (new_value);
}

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

int	main(void)
{
	unsigned char octet = 128;
	print_bits(octet);
	octet = reverse_bits(octet);
	print_bits(octet);
	return (0);
}