
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void ) {

	int	count = 10;
	Zombie *horde = zombieHorde(count, "Tyson");
	for (int i = 0; i < count; i++) {
		horde->announce();
	}
	delete[] horde;
	return (0);
}