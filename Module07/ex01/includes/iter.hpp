#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void	iter( T array[], size_t length, void (*f)( T & ) )
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	iter( T array[], size_t length, void (*f)( T const &) )
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void	print_nonconst( T& to_print )
{
	std::cout << to_print << " ";
}

template <typename T>
void	print_const( const T& to_print )
{
	std::cout << to_print << " ";
}

template <typename T>
void	plus_one( T& add_too)
{
	add_too++;
}

#endif