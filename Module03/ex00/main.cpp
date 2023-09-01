
#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap test = ClapTrap("Clarence");
	ClapTrap test2 = ClapTrap("Victor");
	ClapTrap test3 = ClapTrap(test2);
	ClapTrap test4 = test;

	std::cout << std::endl;

	for (int i = 0; i < 12; i++)
		test.attack("box");
	test.beRepaired(10);
	test.takeDamage(2);

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		test2.takeDamage(2);
	test2.beRepaired(10);
	test2.attack("triangle");

	std::cout << std::endl;
	for (int i = 0; i < 21; i++) {
		test3.takeDamage(1);
		test3.beRepaired(2);
		test3.attack("chair");
	}

	std::cout << std::endl;
	return (0);
}