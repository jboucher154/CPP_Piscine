
#include "Zombie.hpp"
#include <iostream>

void	randomChump( std::string name);
Zombie*	newZombie(std::string name);

int	main( void )
{
	Zombie	*one = newZombie("Frank");
	
	std::cout << "New Zombie created." << std::endl;
	std::cout << "New Zombie announcement:" << std::endl;
	one->announce();
	std::cout << "New Zombie destroy" << std::endl;
	delete one;
	std::cout << "Random Chump Call" << std::endl;
	randomChump("Charles");
	std::cout << "Testing Complete" << std::endl;
	return (0);
}