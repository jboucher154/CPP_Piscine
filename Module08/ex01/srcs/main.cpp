#include "Span.hpp"
#include <iostream>
// #include <vector>
// #include <list>
// #include <deque>

int	main( void ) {
	
	srand(time(NULL));
	{
		{
			std::cout << "\n--Tests basic span class--" << std::endl;
			Span test_span(5);
			Span test_cpy = test_span;
			Span test_next(10);

			test_next = test_span;
		}

		std::cout << "\n--Tests basic span, add one number at a time--" << std::endl;
		Span small_span(10);
		try {
			for (int i = 0; i < 10; i++) {
				int random = rand() % 100;
				std::cout << "number to add: " << random << std::endl;
				small_span.addNumber(random);
			}
			std::cout << "Shortest span is: " << small_span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << small_span.longestSpan() << std::endl;
			small_span.addNumber(0); //should throw exception

		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
	}
	{
		std::cout << "\n--Tests Span, add whole num array--" << std::endl;
		try {
			int 	small[10];
			Span	small_span(10);
			for (int i = 0; i < 10; i++) {
				int random = rand() % 100;
				std::cout << "number to add: " << random << std::endl;
				small[i] = random;
			}
			small_span.addManyNumbers(small, 10);
			std::cout << "Shortest span is: " << small_span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << small_span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Tests Span of 2--" << std::endl;
		Span	small_span(2);
		try {
			small_span.addNumber(1);
			small_span.addNumber(3);
			std::cout << "Shortest span is: " << small_span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << small_span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Test Span, unfilled and with only 1--" << std::endl;
		Span	small_span(5);
		try {
			std::cout << "Shortest span is: " << small_span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << small_span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		try {
			small_span.addNumber(1);
			std::cout << "Longest Span is: " << small_span.longestSpan() << std::endl;
			std::cout << "Shortest span is: " << small_span.shortestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Tests Span, too large array--" << std::endl;
		try {
			int 	large[100];
			Span	span(10);
			for (int i = 0; i < 100; i++) {
				int random = rand() % 100;
				large[i] = random;
			}
			span.addManyNumbers(large, 100);
			std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Tests Span, large array 15,000--" << std::endl;
		try {
			int 	large[15000];
			Span	span(15000);
			for (int i = 0; i < 15000; i++) {
				int random = rand() % 1000;
				large[i] = random;
			}
			span.addManyNumbers(large, 100);
			std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Tests Span, multiple additions--" << std::endl;
		try {
			int 	large[5];
			Span	span(10);

			span.addNumber(1);
			span.addNumber(1);
			span.addNumber(2);
			span.addNumber(3);
			span.addNumber(4);

			for (int i = 0; i < 10; i++) {
				int random = i + 6;
				large[i] = random;
			}
			span.addManyNumbers(large, 5);
			std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--Tests OTHER --" << std::endl;
		try {
			Span	span(10);

			span.addNumber(std::numeric_limits<int>::min());
			span.addNumber(std::numeric_limits<int>::max());
			span.addNumber(0);

			std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;
			std::cout << "Longest Span is: " << span.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return  (0);
}