#include "RPN.hpp"

int	main( int argc, char *argv[] ) {
	if (argc != 2) {
		std::cout << "Error: need exactly one argument." << std::endl;
		return (1);
	}
	try {
		if (RPN::validateInput(argv[1])) {
			if (RPN::calculate(argv[1])) {
				std::cout << RPN::getResult() << std::endl;
			}
		}
		else {
			std::cout << "Error: invalid characters given in argument." << std::endl; 
		}
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl; 
	}
}