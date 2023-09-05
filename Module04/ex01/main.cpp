
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Color.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	animalTests( void ) {

	std::cout << "ANIMAL CLASS TESTS\n";

	Animal	animal;
	Animal	animal_1 = animal;
	Animal	animal_2;
	animal_2 = animal;

	animal.makeSound();
	animal_1.makeSound();
	animal_2.makeSound();

	std::cout << "animal type is: " << animal.getType() << std::endl;

	std::cout << "ANIMAL CLASS TESTS ENDED\n";
}

void	catTests( void ) {

	std::cout << "CAT CLASS TESTS\n";

	Cat	cat;
	Cat	cat_1 = cat;
	Cat	cat_2;
	cat_2 = cat;

	cat.makeSound();
	cat_1.makeSound();
	cat_2.makeSound();

	std::cout << "animal type is: " << cat.getType() << std::endl;

	std::cout << "CAT CLASS TESTS ENDED\n";
}

void	dogTests( void ) {

	std::cout << "DOG CLASS TESTS\n";

	Dog dog;
	Dog	dog_1 = dog;
	Dog	dog_2;
	dog_2 = dog;

	dog.makeSound();
	dog_1.makeSound();
	dog_2.makeSound();

	std::cout << "animal type is: " << dog.getType() << std::endl;

	std::cout << "DOG CLASS TESTS ENDED\n";
}

void	wrongAnimalTest( void ) {
	std::cout << "WRONG ANIMAL CLASS TESTS\n";

	WrongAnimal	wrongAnimal;
	WrongAnimal	wrongAnimal_1 = wrongAnimal;
	WrongAnimal	wrongAnimal_2;
	wrongAnimal_2 = wrongAnimal;

	wrongAnimal.makeSound();
	wrongAnimal_1.makeSound();
	wrongAnimal_2.makeSound();

	std::cout << "animal type is: " << wrongAnimal.getType() << std::endl;

	std::cout << "WRONG ANIMAL CLASS TESTS ENDED\n";
}

void	wrongCatTest( void ) {
	std::cout << "WRONG CAT CLASS TESTS\n";

	WrongCat	wrongCat;
	WrongCat	wrongCat_1 = wrongCat;
	WrongCat	wrongCat_2;
	wrongCat_2 = wrongCat;

	wrongCat.makeSound();
	wrongCat_1.makeSound();
	wrongCat_2.makeSound();

	std::cout << "animal type is: " << wrongCat.getType() << std::endl;

	std::cout << "WRONG CAT CLASS TESTS ENDED\n";
}

int	main( void ) {

	std::cout << COLOR_BRIGHT_BLUE;
	animalTests();
	std::cout << COLOR_BRIGHT_MAGENTA << std::endl;
	catTests();
	std::cout << COLOR_BRIGHT_YELLOW << std::endl;
	dogTests();
	std::cout << COLOR_BRIGHT_GREEN << std::endl;
	wrongAnimalTest();
	std::cout << COLOR_BRIGHT_CYAN << std::endl;
	wrongCatTest();
	std::cout << COLOR_RESET << std::endl;

	std::cout << "TEST FROM SUBJECT: " << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "TEST FROM SUBJECT WITH WRONG ANIMAL / CAT: " << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	return (0);
}