#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& one, T& two)
{
	T temp = one;
	one = two;
	two = temp;
}

template <typename T>
T&	min(T& one, T& two)
{
	return ((one >= two) ? two : one);
}

template <typename T>
T&	max(T& one, T& two)
{
	return ((two >= one) ? two : one);
}

#endif