#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template < typename T >
typename T::iterator	easyfind( T& container, int to_find) {

	typename T::iterator iter = std::find(container.begin(), container.end(), to_find);
	if (iter != container.end()) {
		return (iter);
	}
	else {
		return (container.end());
	}
}

#endif