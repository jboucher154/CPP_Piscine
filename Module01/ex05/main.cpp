
#include "Harl.hpp"
#include "Color.hpp"
#include <iostream>
#include <ctime>

void	many_complaints( void ) {
	Harl		harl_one;
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};

	srand(time(NULL));
	std::cout << BGCOLOR_PURPLE_BLUE << "Testing many complaints" << COLOR_RESET << std::endl;
	for (int i = 0; i < 100; i++) {
		harl_one.complain(levels[std::rand() % 4]);
	}
	std::cout << BGCOLOR_PURPLE_BLUE << "Completed" << COLOR_RESET << std::endl;
}

void	simple_tests( void ) {
	Harl	harl_one;

	std::cout << BGCOLOR_PURPLE_BLUE << "Testing each complaint" << COLOR_RESET << std::endl;
	harl_one.complain("DEBUG");
	harl_one.complain("INFO");
	harl_one.complain("WARNING");
	harl_one.complain("ERROR");
	std::cout << BGCOLOR_PURPLE_BLUE << "Completed" << COLOR_RESET << std::endl;
}

void	input_tests( void ) {
	Harl	harl_one;

	std::cout << BGCOLOR_PURPLE_BLUE << "Testing bad input" << COLOR_RESET << std::endl;
	harl_one.complain("");
	harl_one.complain("nomatch");
	harl_one.complain("DEBUGINFO");
	std::cout << BGCOLOR_PURPLE_BLUE << "Completed" << COLOR_RESET << std::endl;
}

int	main( void ) {
	
	input_tests();
	simple_tests();
	many_complaints();
	return (0);
}