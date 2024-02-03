
#include "PmergeMe.hpp"
#include <iostream>

int	main( int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "please provide a list of positive integers to sort." << std::endl;
	}
	try {
		//start timing before sorting.
		//track time for data managment that is shared between or do it twice?
		//track time for each process
		if (!PmergeMe::check_for_good_input(argc - 1, argv)) {
			std::cout << "PmergeMe : Error. Invalid input detected.";
			std::cout << "Usage notes: Enter a list of positive integers to be sorted.";
			return (1);
		}
	}
	catch (std::exception& e) {

		std::cout<< e.what() << std::endl; //std out
	}
	return (0);
}