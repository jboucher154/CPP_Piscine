
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Color.hpp"

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
		Dog doggo(dog_1);


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

void	testNowAllocateedArray( void ) {
	std::cout << COLOR_BRIGHT_YELLOW << std::endl;
	AAnimal *clinic[] = {new Cat(), new Cat(), new Dog(), new Dog(), new Cat(), new Dog()};
	std::cout << COLOR_RESET << std::endl;
	for (int i = 0; i < 6; i++) {
		clinic[i]->makeSound();
		delete clinic[i];
	}
}

int	main( void ) {

	brainTests();
	testNowAllocateedArray();
	std::cout << COLOR_BRIGHT_GREEN << std::endl;
	std::cout << "\nTest Requested in Subject: \n";

	// AAnimal wilFail = new AAnimal();
	
	AAnimal	*pound[10];

	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			pound[i] = new Dog();
		} else {
			pound[i] = new Cat();
		}
		pound[i]->makeSound();
	}
	std::cout << COLOR_BRIGHT_CYAN << std::endl;
	for (int i = 0; i < 10; i++) {
		pound[i]->makeSound();
		delete pound[i];
	}
	std::cout << COLOR_RESET << std::endl;
	return (0);
}