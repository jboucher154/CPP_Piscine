
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void ) {

	DiamondTrap one("pink");
	one.whoAmI();
	one.gaurdGate();
	one.highFivesGuys();
	one.takeDamage(20);
	one.beRepaired(10);
	one.attack("tree");

	std::cout << std::endl;
	DiamondTrap two(one);
	two.whoAmI();
	std::cout << std::endl;

	DiamondTrap three("Ferret");
	DiamondTrap four("temp");
	four = three;
	four.whoAmI();
	std::cout << std::endl;

	return (0);
}