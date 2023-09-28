
#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc == 1 ||  argc > 2) {
		std::cout << "Error: Give one input file" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange	btc(argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}