
#include "ScavTrap.hpp"

int	main( void ) {

	ScavTrap test("barry");

	test.attack("Target");
	test.attack("next Target");
	test.attack("Another Target");
	test.takeDamage(10);
	test.beRepaired(5);
	test.beRepaired(5);
	test.takeDamage(10);
	test.gaurdGate();
	test.takeDamage(100);
	test.attack("first Target");
	return (0);
}