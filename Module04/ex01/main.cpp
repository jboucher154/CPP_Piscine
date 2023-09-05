
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Color.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	brainTests( void ) {
	{
		std::cout << COLOR_BRIGHT_BLUE;
		std::cout << "CAT WITH BRAIN CLASS TESTS\n";

		Cat	cat;
		Cat cat_1 = cat;
		Cat	cat_2;
		cat_2 = cat;

		cat.makeSound();
		cat_1.makeSound();
		cat_2.makeSound();

		std::cout << "I am cat 0\n";
		cat.printBrainAddress();
		std::cout << "I am cat 1\n";
		cat_1.printBrainAddress();
		std::cout << "I am cat 2\n";
		cat_2.printBrainAddress();
		std::cout << "animal type is: " << cat.getType() << std::endl;
		std::cout << "CAT WITH BRAIN CLASS TESTS ENDED\n";
	}
	{
		std::cout << COLOR_BRIGHT_MAGENTA << std::endl;
		std::cout << "DOG WITH BRAIN CLASS TESTS\n";
		Dog	dog;
		Dog dog_1 = dog;
		Dog	dog_2;
		dog_2 = dog;

		dog.makeSound();
		dog_1.makeSound();
		dog_2.makeSound();

		std::cout << "I am dog 0\n";
		dog.printBrainAddress();
		std::cout << "I am dog 1\n";
		dog_1.printBrainAddress();
		std::cout << "I am dog 2\n";
		dog_2.printBrainAddress();

		std::cout << "animal type is: " << dog.getType() << std::endl;
		std::cout << "DOG WITH BRAIN CLASS TESTS ENDED\n";
	}
	std::cout << COLOR_RESET << std::endl;
}

void	testUnallocatedArray( void ) {
	std::cout << COLOR_BRIGHT_YELLOW << std::endl;
	Animal clinic[] = {Cat(), Cat(), Dog(), Dog(), Cat(), Dog()};
	std::cout << COLOR_RESET << std::endl;
}

int	main( void ) {

	brainTests();
	testUnallocatedArray();
	std::cout << COLOR_BRIGHT_GREEN << std::endl;
	Animal	*pound = new Animal[10];
	for (int i = 0; 0 < 10; i++) {
		if (i < 5) {
			pound[i] = new Dog();
		} else {
			pound[i] = new Cat();
		}
	}
	std::cout << COLOR_BRIGHT_CYAN << std::endl;

	std::cout << COLOR_RESET << std::endl;


	return (0);
}