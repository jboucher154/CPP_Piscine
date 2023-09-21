#include "iter.hpp"

int	main( void )
{
	{
		std::cout << "\n --TEST ITER WITH VARIOUS FUNCTIONS AND DATA TYPES--" << std::endl;
		int int_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
		float float_array[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f};
		double double_array[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 , 10.0};
		std::string str_array[] = {"hi", "I'm", "an", "array", "of", "strings!"};

		std::cout << "\n INT ARRAY ITER" << std::endl;
		::iter(int_array, 10, ::print_const);
		std::cout << std::endl;
		::iter(int_array, 10, ::plus_one<int>);
		::iter(int_array, 10, ::print_nonconst<int>);
		std::cout << "\n FLOAT ARRAY ITER" << std::endl;
		::iter(float_array, 10, ::print_const);
		std::cout << std::endl;
		::iter(float_array, 10, ::plus_one<float>);
		::iter(float_array, 10, ::print_nonconst<float>);
		std::cout << "\n DOUBLE ARRAY ITER" << std::endl;
		::iter(double_array, 10, ::print_const);
		std::cout << std::endl;
		::iter(double_array, 10, ::plus_one<double>);
		::iter(double_array, 10, ::print_nonconst<double>);
		std::cout << "\n STRING ARRAY ITER" << std::endl;
		::iter(str_array, 6, ::print_const);
		std::cout << std::endl;
		::iter(str_array, 6, ::plus_one<std::string>);
		::iter(str_array, 6, ::print_nonconst<std::string>);
		std::cout << std::endl;
	}
	return (0);
}
