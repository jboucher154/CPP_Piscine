#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int	main( void ) {
	{
		std::cout << "\nTEST VECTOR CONTAINTER" << std::endl;
		std::vector<int> vec_container; //{0, 1, 2, 3, 6, 3, 9, 1};//can't do this way in 98 standard...
		for (int i = 0; i < 10; i++) {
			vec_container.push_back(i);
		}
		vec_container.push_back(1);
		std::vector<int>::iterator v_it = easyfind<std::vector<int> >(vec_container, 2);
		std::cout << "Easyfind from VECTOR 2: " << *v_it << std::endl;
		v_it = easyfind<std::vector<int> >(vec_container, 1);
		std::cout << "Easyfind from VECTOR 1: " << *v_it << std::endl;
		std::vector<int>::iterator v_end = vec_container.end() - 1;
		std::cout << "Was the first occurance found? " << ((v_end != v_it) ? "true" : "false") << std::endl;
		v_it = easyfind<std::vector<int> >(vec_container, 12);
		std::cout << "Easyfind from VECTOR not exist: " << *v_it << std::endl;
		std::cout << "Easyfind return for not found was == container.end(): " << ((v_it == vec_container.end()) ? "true" : "false") << std::endl;//returns false
	}
	{
		std::cout << "\nTEST LIST CONTAINTER" << std::endl;
		std::list<int> list_container; 
		for (int i = 0; i < 10; i++) {
			list_container.push_back(i);
		}
		list_container.push_back(1);
		std::list<int>::iterator l_it = easyfind<std::list<int> >(list_container, 2);
		std::cout << "Easyfind from LIST 2: " << *l_it << std::endl;
		l_it = easyfind<std::list<int> >(list_container, 1);
		std::cout << "Easyfind from LIST 1: " << *l_it << std::endl;
		std::list<int>::iterator l_end = list_container.end();
		l_end--;
		std::cout << "Was the first occurance found? " << ((l_end != l_it) ? "true" : "false") << std::endl;
		l_it = easyfind<std::list<int> >(list_container, 12);
		std::cout << "Easyfind from LIST not exist: " << *l_it << std::endl;
		std::cout << "Easyfind return for not found was == container.end(): " << ((l_it == list_container.end()) ? "true" : "false") << std::endl;//returns false
	}
	{
		std::cout << "\nTEST DEQUE CONTAINTER" << std::endl;
		std::deque<int> deque_container; 
		for (int i = 0; i < 10; i++) {
			deque_container.push_back(i);
		}
		deque_container.push_back(1);
		std::deque<int>::iterator l_it = easyfind<std::deque<int> >(deque_container, 2);
		std::cout << "Easyfind from LIST 2: " << *l_it << std::endl;
		l_it = easyfind<std::deque<int> >(deque_container, 1);
		std::cout << "Easyfind from LIST 1: " << *l_it << std::endl;
		std::deque<int>::iterator l_end = deque_container.end() - 1 ;
		std::cout << "Was the first occurance found? " << ((l_end != l_it) ? "true" : "false") << std::endl;
		l_it = easyfind<std::deque<int> >(deque_container, 12);
		std::cout << "Easyfind from LIST not exist: " << *l_it << std::endl;
		std::cout << "Easyfind return for not found was == container.end(): " << ((l_it == deque_container.end()) ? "true" : "false") << std::endl;//returns false
	}
	return  (0);
}