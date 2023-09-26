#include "../includes/MutantStack.hpp"
#include <iostream>
#include <stack>
#include <vector>


int	main( void ) {
	{
		std::cout << "\nBASIC MUSTANT STACK CLASS TESTS" << std::endl;
		MutantStack<std::string>	first;
		MutantStack<std::string>	second;
		second = first;
		MutantStack<std::string>	third(first);
		
		std::deque<int> 			test_deque(10, 42);
		std::vector<double>			test_vector(100, 4.2);

		MutantStack<int> copy_deque(test_deque);
		MutantStack<double, std::vector<double> > copy_vector(test_vector);


		std::stack<std::string>	stack_comparison_1;
		std::stack<std::string>	stack_comparison_2;
		stack_comparison_1 = stack_comparison_2;
		std::stack<std::string>	stack_comparison_3(stack_comparison_1);

		std::stack<int> stack_from_deque(test_deque);
		std::stack<double, std::vector<double> > stack_from_vector(test_vector);
		
	}
	{
		std::cout << "\nTEST BASIC OPERATIONS OF MUTANT STACK CONTAINTER" << std::endl;
		
		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;
		srand(time(NULL));

		std::cout << "\nTest Empty for mutant : " << (mutant.empty() ? "true" : "false") << " For non_mutant : " << (non_mutant.empty() ? "true" : "false") << std::endl;
		std::cout << "\nTesting Push..." << std::endl;
		for (int i = 0; i < 100; i ++) {
			int	random = rand() % 1000;
			mutant.push(random);
			non_mutant.push(random);
		}
		std::cout << "Mutant and non_mutant filled identically." << std::endl;
		std::cout << "\nTesting Size for mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size() << std::endl;
		std::cout << "\nChecking contents with top and pop" << std::endl;
		for (int i = 0; i < 100; i ++) {
			if (mutant.top() != non_mutant.top()) {
				std::cout << "Values from top don't match!" << std::endl;
			}
			mutant.pop();
			non_mutant.pop();
		}
		std::cout << "Sizes after top/ pop for mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size() << std::endl;
		// std::cout << "Testing emplace..." << std::endl; ??
		for (int i = 0; i < 5; i++) {
			int	random = rand() % 1000;
			mutant.push(random);
			non_mutant.push(random);
			if (mutant.top() != non_mutant.top()) {
				std::cout << "Values from top don't match!" << std::endl;
			}
		}

		MutantStack<int>	mutant_toswap;
		std::stack<int>		non_mutant_toswap;
		for (int i = 0; i < 3; i++) {
			int	random = rand() % 1000;
			mutant_toswap.push(random);
			non_mutant_toswap.push(random);
			if (mutant_toswap.top() != non_mutant_toswap.top()) {
				std::cout << "Values from top don't match!" << std::endl;
			}
		}
		std::cout << "\nSizes before swap mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size();
		std::cout << " mutant_toswap : " << mutant_toswap.size() << " non_mutant_toswap : " << non_mutant_toswap.size() << std::endl;
		mutant.swap(mutant_toswap);
		non_mutant.swap(non_mutant_toswap);
		std::cout << "Sizes after swap mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size();
		std::cout << " mutant_toswap : " << mutant_toswap.size() << " non_mutant_toswap : " << non_mutant_toswap.size() << std::endl;
	}
	return  (0);
}