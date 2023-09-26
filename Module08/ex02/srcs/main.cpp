#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <vector>
#include <list>

int	main( void ) {
	srand(time(NULL));
	{
		std::cout << "\nBASIC MUSTANT STACK CLASS TESTS" << std::endl;
		MutantStack<std::string>	first;
		MutantStack<std::string>	second;
		second = first;
		MutantStack<std::string>	third(first);
		
		std::deque<int> 			test_deque(10, 42);
		std::vector<double>			test_vector(100, 4.2);
		std::list<std::string>		test_list(10, "Hi");

		MutantStack<int> copy_deque(test_deque);
		MutantStack<double, std::vector<double> > copy_vector(test_vector);
		MutantStack<std::string, std::list<std::string> >	copy_list(test_list);


		std::stack<std::string>		stack_comparison_1;
		std::stack<std::string>		stack_comparison_2;
		stack_comparison_1 = stack_comparison_2;
		std::stack<std::string>		stack_comparison_3(stack_comparison_1);

		std::stack<int> 									stack_from_deque(test_deque);
		std::stack<double, std::vector<double> > 			stack_from_vector(test_vector);
		std::stack<std::string, std::list<std::string> >	stack_from_list(test_list);
	}
	{
		std::cout << "\nTEST BASIC OPERATIONS OF MUTANT STACK CONTAINTER" << std::endl;
		
		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;

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
	
	}
	{
		std::cout << "\nTEST ITERATOR OF MUTANT STACK CONTAINTER" << std::endl;

		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;

		std::cout << "\nFilling mutant and non_mutant with same 10 random numbers" << std::endl;
		for (int i = 0; i < 10; i ++) {
			int	random = rand() % 100;
			mutant.push(random);
			non_mutant.push(random);
			std::cout << i << " Value added " << random << std::endl;
		}
		std::cout << "\nCreating mutant stack iterators" << std::endl;
		MutantStack<int>::iterator mutant_start = mutant.begin();
		MutantStack<int>::iterator mutant_end = mutant.end();
		mutant_end -= 1;
		std::cout << "start value : " << *mutant_start << " end value : " << *mutant_end<< " mutant top : " << mutant.top() << std::endl;
		for (MutantStack<int>::iterator end = mutant.end() - 1; end != mutant.begin() - 1; end--) {
			// std::cout << "Mutant end value : " << *end << " non_mutant top : " << non_mutant.top() << std::endl;
			// std::cout << "Now popping from the stack comparison" << std::endl;
			if (*end != non_mutant.top()) {
				std::cout << " values do not match!!!!" << std::endl;
			}
			non_mutant.pop();
		}
		MutantStack<int>::iterator mutant_start1 = mutant.begin();
		std::cout << "start value before change: " << *mutant_start1 << std::endl;
		*mutant_start1 = 0;
		std::cout << "start value after change: " << *mutant_start1 << std::endl;
	}
	{
		std::cout << "\nTEST CONST_ITERATORS OF MUTANT STACK CONTAINTER" << std::endl;

		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;

		std::cout << "\nFilling mutant and non_mutant with same 10 random numbers" << std::endl;
		for (int i = 0; i < 10; i ++) {
			int	random = rand() % 100;
			mutant.push(random);
			non_mutant.push(random);
			// std::cout << i << " Value added " << random << std::endl;
		}
		std::cout << "\nCreating mutant stack const_iterators" << std::endl;
		MutantStack<int>::const_iterator mutant_start = mutant.begin();
		MutantStack<int>::const_iterator mutant_end = mutant.end();
		mutant_end -= 1;
		std::cout << "start value : " << *mutant_start << " end value : " << *mutant_end<< " mutant top : " << mutant.top() << std::endl;
		for (MutantStack<int>::const_iterator end = mutant.end() - 1; end != mutant.begin() - 1; end--) {
			// std::cout << "Mutant end value : " << *end << " non_mutant top : " << non_mutant.top() << std::endl;
			// std::cout << "Now popping from the stack comparison" << std::endl;
			if (*end != non_mutant.top()) {
				std::cout << " values do not match!!!!" << std::endl;
			}
			non_mutant.pop();
		}
		MutantStack<int>::const_iterator mutant_start1 = mutant.begin();
		std::cout << "start value before change: " << *mutant_start1 << std::endl;
		// *mutant_start1 = 0; //wont't work for const_iterator
		std::cout << "start value after change: " << *mutant_start1 << std::endl;
	}
	{
		std::cout << "\nTEST REVERSE_ITERATORS OF MUTANT STACK CONTAINTER" << std::endl;

		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;

		std::cout << "\nFilling mutant and non_mutant with same 10 random numbers" << std::endl;
		for (int i = 0; i < 10; i ++) {
			int	random = rand() % 100;
			mutant.push(random);
			non_mutant.push(random);
			// std::cout << i << " Value added " << random << std::endl;
		}
		std::cout << "\nCreating mutant stack reverse_iterators" << std::endl;
		MutantStack<int>::reverse_iterator mutant_start = mutant.rbegin();
		MutantStack<int>::reverse_iterator mutant_end = mutant.rend();
		mutant_end -= 1;
		std::cout << "start value : " << *mutant_start << " end value : " << *mutant_end << " mutant top : " << mutant.top() << std::endl;
		for (MutantStack<int>::reverse_iterator end = mutant.rbegin(); end != mutant.rend() - 1; end++) {
			// std::cout << "Mutant end value : " << *end << " non_mutant top : " << non_mutant.top() << std::endl;
			// std::cout << "Now popping from the stack comparison" << std::endl;
			if (*end != non_mutant.top()) {
				std::cout << " values do not match!!!!" << std::endl;
			}
			non_mutant.pop();
		}
		MutantStack<int>::reverse_iterator mutant_start1 = mutant.rbegin() + 1;
		std::cout << "start value before change: " << *mutant_start1 << std::endl;
		*mutant_start1 = 0;
		std::cout << "start value after change: " << *mutant_start1 << std::endl;
	}
	{
		std::cout << "\nTEST CONST_REVERSE_ITERATORS OF MUTANT STACK CONTAINTER" << std::endl;

		MutantStack<int>	mutant;
		std::stack<int>		non_mutant;

		std::cout << "\nFilling mutant and non_mutant with same 10 random numbers" << std::endl;
		for (int i = 0; i < 10; i ++) {
			int	random = rand() % 100;
			mutant.push(random);
			non_mutant.push(random);
			// std::cout << i << " Value added " << random << std::endl;
		}
		std::cout << "\nCreating mutant stack reverse_iterators" << std::endl;
		MutantStack<int>::const_reverse_iterator mutant_start = mutant.rbegin();
		MutantStack<int>::const_reverse_iterator mutant_end = mutant.rend();
		mutant_end -= 1;
		std::cout << "start value : " << *mutant_start << " end value : " << *mutant_end << " mutant top : " << mutant.top() << std::endl;
		for (MutantStack<int>::const_reverse_iterator end = mutant.rbegin(); end != mutant.rend() - 1; end++) {
			// std::cout << "Mutant end value : " << *end << " non_mutant top : " << non_mutant.top() << std::endl;
			// std::cout << "Now popping from the stack comparison" << std::endl;
			if (*end != non_mutant.top()) {
				std::cout << " values do not match!!!!" << std::endl;
			}
			non_mutant.pop();
		}
		MutantStack<int>::const_reverse_iterator mutant_start1 = mutant.rbegin() + 1;
		std::cout << "start value before change: " << *mutant_start1 << std::endl;
		// *mutant_start1 = 0; //wont't work for const iterator
		std::cout << "start value after change: " << *mutant_start1 << std::endl;
	}
	return  (0);
}


/* Main from subject*/
// int main()
// {
// 	{	
// 		std::cout << "CODE FROM SUBJECT" << std::endl;
// 		MutantStack<int> mstack;
// 		mstack.push(5);
// 		mstack.push(17);
// 		std::cout << mstack.top() << std::endl;
// 		mstack.pop();
// 		std::cout << mstack.size() << std::endl;
// 		mstack.push(3);
// 		mstack.push(5);
// 		mstack.push(737);
// 		//[...]
// 		mstack.push(0);
// 		MutantStack<int>::iterator it = mstack.begin();
// 		MutantStack<int>::iterator ite = mstack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 		std::cout << *it << std::endl;
// 		++it;
// 		}
// 		std::stack<int> s(mstack);
// 	}
// 	{
// 		std::cout << "\nCODE FROM SUBJECT WITH LIST REPLACED" << std::endl;
// 		std::list<int> mstack;
// 		mstack.push_back(5);
// 		mstack.push_back(17);
// 		std::cout << mstack.back() << std::endl;
// 		mstack.pop_back();
// 		std::cout << mstack.size() << std::endl;
// 		mstack.push_back(3);
// 		mstack.push_back(5);
// 		mstack.push_back(737);
// 		//[...]
// 		mstack.push_back(0);
// 		std::list<int>::iterator it = mstack.begin();
// 		std::list<int>::iterator ite = mstack.end();
// 		++it;
// 		--it;
// 		while (it != ite)
// 		{
// 		std::cout << *it << std::endl;
// 		++it;
// 		}
// 		std::stack<int, std::list<int> > s(mstack);
// 	}
// 	return 0;
// }

/* IF WE COULD USE CPP 11 ... */
		// for (int i = 0; i < 5; i++) {
		// 	int	random = rand() % 1000;
		// 	mutant.emplace(random);
		// 	non_mutant.emplace(random);
		// 	if (mutant.top() != non_mutant.top()) {
		// 		std::cout << "Values from top don't match!" << std::endl;
		// 	}
		// }

		// MutantStack<int>	mutant_toswap;
		// std::stack<int>		non_mutant_toswap;
		// for (int i = 0; i < 3; i++) {
		// 	int	random = rand() % 1000;
		// 	mutant_toswap.push(random);
		// 	non_mutant_toswap.push(random);
		// 	if (mutant_toswap.top() != non_mutant_toswap.top()) {
		// 		std::cout << "Values from top don't match!" << std::endl;
		// 	}
		// }
		// std::cout << "\nSizes before swap mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size();
		// std::cout << " mutant_toswap : " << mutant_toswap.size() << " non_mutant_toswap : " << non_mutant_toswap.size() << std::endl;
		// mutant.swap(mutant_toswap);
		// non_mutant.swap(non_mutant_toswap);
		// std::cout << "Sizes after swap mutant : " << mutant.size() << " for non_mutant : " << non_mutant.size();
		// std::cout << " mutant_toswap : " << mutant_toswap.size() << " non_mutant_toswap : " << non_mutant_toswap.size() << std::endl;
