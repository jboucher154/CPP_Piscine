
#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc == 1 ||  argc > 2) {
		std::cout << "Error: Give one input file" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange	btc_db;
		
		btc_db.processInput(argv[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}