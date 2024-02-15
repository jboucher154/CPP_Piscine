
#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

bool	check_for_good_input( int argc, char* argv[])
{

	std::string	str_entry;
	long double entry;

	try {
		for (int i = 0; i < argc; i++) {
			std::istringstream ss(argv[i]);
			if (ss.fail()) {
				throw(std::runtime_error("string stream error, unable to process input"));
			}
			while (std::getline(ss, str_entry, ' ')) {
				entry = std::stold(str_entry);
				if (entry < 0 || entry > std::numeric_limits<int>::max() || str_entry.find_first_not_of("0123456789") != std::string::npos)
					throw(std::invalid_argument("an input is out of integer range, negative, or not a number"));
			}
		}
		return true;
	}
	catch (std::exception& e) {
		std::cout << COLOR_BRIGHT_RED << "PmergeMe: Error: " << e.what() << COLOR_RESET << std::endl;
		return false;
	}
}

void	run_timed_sorting( int num_to_sort, char* str_num_array[] )
{
	const std::chrono::high_resolution_clock::time_point start_1 = std::chrono::high_resolution_clock::now();
	PmergeMe vector_sort(num_to_sort, str_num_array, VECTOR_SORT);
	vector_sort.sort();
	const std::chrono::high_resolution_clock::time_point end_1 = std::chrono::high_resolution_clock::now();

	const std::chrono::high_resolution_clock::time_point start_2 = std::chrono::high_resolution_clock::now();
	PmergeMe deque_sort(num_to_sort, str_num_array, DEQUE_SORT);
	deque_sort.sort();
	const std::chrono::high_resolution_clock::time_point end_2 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff_1 = std::chrono::duration_cast<std::chrono::microseconds>(end_1 - start_1);
	std::cout << vector_sort;
	std::cout << "Time to proces a range of " << vector_sort.get_size_sorted() << " elements with std::vector : " << vector_sort.get_print_color() << diff_1.count() << " microseconds" << COLOR_RESET << std::endl;
	std::chrono::duration<double> diff_2 = std::chrono::duration_cast<std::chrono::microseconds>(end_2 - start_2);
	std::cout << "Time to proces a range of " << deque_sort.get_size_sorted() << " elements with std::deque  : " << deque_sort.get_print_color()<< diff_2.count() << " microseconds" << COLOR_RESET << std::endl;

}

int	main( int argc, char* argv[] )
{

	if (argc < 2) {
		std::cout << "please provide a list of positive integers to sort." << std::endl;
		return EXIT_FAILURE;
	}
	try {
		if (!check_for_good_input(argc - 1, argv + 1)) {
			std::cout << COLOR_BRIGHT_YELLOW << "Usage notes: Enter a list of positive integers to be sorted." << std::endl;
			std::cout << "Usage notes: Input can be quoted or unquoted, but do not leave leading whitespace in a quote" << COLOR_RESET << std::endl;
			return EXIT_FAILURE;
		}
		run_timed_sorting(argc - 1, argv + 1);
	}
	catch (std::exception& e) {

		std::cout<< e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}
