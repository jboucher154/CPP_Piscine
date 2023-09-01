
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {

	/* ClapTrap tests*/
	std::cout << "ClapTrap Tests" << std::endl;
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

	/* ScavTrap Tests*/
	std::cout << "ScavTrap Tests" << std::endl;

	ScavTrap testScav1("Barry");
	ScavTrap testScav(testScav1);

	testScav.attack("Target");
	testScav.attack("next Target");
	testScav.attack("Another Target");
	testScav.takeDamage(10);
	testScav.beRepaired(5);
	testScav.beRepaired(5);
	testScav.takeDamage(10);
	testScav.gaurdGate();
	testScav.takeDamage(100);
	testScav.attack("first Target");
	
	ScavTrap testScav2 = testScav;
	testScav.attack("the sky");
	std::cout << std::endl;

	/* FragTrap Tests */
	std::cout << "FragTrap Tests" << std::endl;
	FragTrap testFrag("Charlie");
	FragTrap testFrag2(testFrag);

	testFrag2.attack("the grass");
	testFrag2.attack("something else");
	testFrag2.takeDamage(20);
	testFrag2.takeDamage(20);
	testFrag2.beRepaired(20);
	testFrag2.takeDamage(50);
	testFrag2.takeDamage(20);
	testFrag2.beRepaired(10);
	testFrag2.highFivesGuys();
	testFrag2.takeDamage(20);
	FragTrap testFrag3 = testFrag2;
	testFrag3.attack("the ground");
	std::cout << std::endl;

	return (0);
}