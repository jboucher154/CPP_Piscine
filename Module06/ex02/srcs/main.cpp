#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base* generate(void)
{
	int	to_generate = std::rand() % 3;
	Base* generated;
	switch (to_generate)
	{
		case 0:
			generated = new A();
			std::cout << "\ngenerated Base was type: A" << std::endl;
			break ;
		case 1:
			generated = new B();
			std::cout << "\ngenerated Base was type: B" << std::endl;
			break ;
		case 2:
			generated = new C();
			std::cout << "\ngenerated Base was type: C" << std::endl;
			break ;
		default:
			generated = nullptr;
			break ;
	}
	return (generated);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Pointer passed was type A!" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Pointer passed was type B!" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Pointer passed was type C!" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		A& found = dynamic_cast<A&>(p);
		( void ) found;
		std::cout << "Reference passed was type A!" << std::endl;
	}
	catch(const std::exception& e)
	{ /* cast was not this type */ }
	try
	{
		B& found = dynamic_cast<B&>(p);
		( void ) found;
		std::cout << "Reference passed was type B!" << std::endl;
	}
	catch(const std::exception& e)
	{ /* cast was not this type */ }
	try
	{
		C& found = dynamic_cast<C&>(p);
		( void ) found;
		std::cout << "Reference passed was type C!" << std::endl;
	}
	catch(const std::exception& e)
	{ /* cast was not this type */ }
}

int	main( void )
{
	std::cout << "TEST DYNAMIC CAST WITH POLYMORPHIC CLASS TYPE" << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base* generic = generate();
		std::cout << std::endl << "Generic's acutal class is:" << std::endl;
		identify(generic);
		identify(*generic);
		delete generic;
	}
}