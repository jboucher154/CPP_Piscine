
#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

bool	check_for_good_input( int argc, char* argv[]) {

	long double entry;

	for (int i = 0; i < argc; i++) {
		std::istringstream ss(argv[i]);
		ss >> entry;
		if (ss.fail() || entry < 0 || entry > std::numeric_limits<int>::max()) {
			return (false); //could print out specific failure message here...
		}
	}
	return (true);
}

int	main( int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "please provide a list of positive integers to sort." << std::endl;
	}
	try {
		//start timing before sorting.
		//track time for data managment that is shared between or do it twice?
		//track time for each process
		if (!check_for_good_input(argc - 1, argv + 1)) {
			std::cout << "PmergeMe : Error. Invalid input detected.";
			std::cout << "Usage notes: Enter a list of positive integers to be sorted.";
			return (EXIT_FAILURE);
		}
		//run the sorting
		const std::chrono::high_resolution_clock::time_point start_1 = std::chrono::high_resolution_clock::now();
		//run first version here
		PmergeMe vector_sort(argc - 1, argv + 1);
		vector_sort.sort();
		const std::chrono::high_resolution_clock::time_point end_1 = std::chrono::high_resolution_clock::now();
		// const std::chrono::high_resolution_clock::time_point start_2 = std::chrono::high_resolution_clock::now();
		// //run second version here
		// const std::chrono::high_resolution_clock::time_point end_2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff_1 = std::chrono::duration_cast<std::chrono::microseconds>(end_1 - start_1);
		std::cout << "the sorting took : " << diff_1.count() << " microseconds" << std::endl;
		// std::chrono::duration<double> diff_1 = duration_cast<microseconds>(end_2 - start_2);
	
	}
	catch (std::exception& e) {

		std::cout<< e.what() << std::endl; //std out
	}
	return (EXIT_SUCCESS);
}