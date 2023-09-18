
#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 2)
		ScalarConverter::Convert(argv[1]);
	else
		std::cout << "give one argument for conversion" << std::endl;
	return (0);
}