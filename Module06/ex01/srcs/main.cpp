#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>



int	main( void )
{
	std::cout << "\tTEST DATA STRUCT" << std::endl;
	{
		Data *test1 = new Data;
		test1->name = "Jenny";
		test1->class_type = "Paladin";
		test1->affiliation= "Alliance";
		test1->level = 0;

		std::cout << "Test1-> Pointers Address: " << &test1 << "\nContents: " << std::endl;
		std::cout << "Name: " << test1->name << "\nClass: " << test1->class_type << "\nAffiliation: " << test1->affiliation;
		std::cout << "\nLevel: " << test1->level << std::endl;

		delete test1;
	}
	std::cout << std::endl << "\tTEST SERIALIZER CLASS" << std::endl;
	{
		Data *test1 = new Data;
		test1->name = "Jenny";
		test1->class_type = "Hunter";
		test1->affiliation= "Horde";
		test1->level = 20;

		std::cout << "\nTest1-> Pointers Address: " << &test1 << " address it holds: " << test1 << "\nContents: " << std::endl;
		std::cout << "Name: " << test1->name << " Class: " << test1->class_type << " Affiliation: " << test1->affiliation;
		std::cout << "Level: " << test1->level << std::endl;

		uintptr_t uint_of_ptr = Serializer::serialize(test1);
		std::cout << "\nAfter serialization:" << std::endl;
		std::cout << "unsigned int pointer from serialize: " << uint_of_ptr << std::endl;
		std::cout << "Test1-> Pointers Address: " << &test1 << " address it holds: " << test1 << "\nContents: " << std::endl;
		std::cout << "Name: " << test1->name << " Class: " << test1->class_type << " Affiliation: " << test1->affiliation;
		std::cout << "Level: " << test1->level << std::endl;

		Data *reinterpreted = Serializer::deserialize(uint_of_ptr);
		std::cout << "\nAfter DEserialization:" << std::endl;
		std::cout << "unsigned int pointer from serialize: " << uint_of_ptr << std::endl;
		std::cout << "\nreinterpreted-> Pointers Address: " << &reinterpreted << " address it holds: " << reinterpreted << "\nContents: " << std::endl;
		std::cout << "Name: " << reinterpreted->name << "\nClass: " << reinterpreted->class_type << "\nAffiliation: " << reinterpreted->affiliation;
		std::cout << "\nLevel: " << reinterpreted->level << std::endl;
		std::cout << "\nTest1-> Pointers Address: " << &test1 << " address it holds: " << test1 << "\nContents: " << std::endl;
		std::cout << "Name: " << test1->name << "\nClass: " << test1->class_type << "\nAffiliation: " << test1->affiliation;
		std::cout << "\nLevel: " << test1->level << std::endl;

		delete test1;
	}
	return (0);
}