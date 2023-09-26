#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

// # ifndef
#  include "./MutantStack.hpp"
// # endif
// template < typename T, typename Container >
// class MutantStack : public std::stack<T, Container>;

/* CONSTRUCTORS */

template < typename T, typename Container >
MutantStack<T, Container>::MutantStack( void ) : std::stack<T, Container>() {}

template < typename T, typename Container >
MutantStack<T, Container>::MutantStack( Container existing ) : std::stack<T, Container>(existing) {}

template < typename T, typename Container >
MutantStack<T, Container>::MutantStack( const MutantStack<T, Container>& to_copy ) {
	*this = to_copy;
}

/* DESTRUCTOR */

template < typename T, typename Container >
MutantStack<T, Container>::~MutantStack( void ) {}

/* OPERATOR OVERLOADS */

template < typename T, typename Container >
MutantStack<T, Container>&	MutantStack<T, Container>::operator=( const MutantStack<T, Container>& to_copy ) {
	if (this != &to_copy) {
		std::stack<T, Container>::operator=(to_copy);
	}
	return (*this);
}

/* PUBLIC METHODS */

/* NORMAL ITERATORS*/

template < typename T, typename Container >
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin( void ) {
	return (this->::std::stack<T, Container>::c.begin());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end( void ) {
	return (this->::std::stack<T, Container>::c.end());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin( void ) const {
	return (this->::std::stack<T, Container>::c.begin());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end( void ) const {
	return (this->::std::stack<T, Container>::c.end());
}

/* REVERSE ITERATORS */

template < typename T, typename Container >
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin( void ) {
	return (this->::std::stack<T, Container>::c.rbegin());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend( void ) {
	return (this->::std::stack<T, Container>::c.rend());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin( void ) const {
	return (this->::std::stack<T, Container>::c.rbegin());
}

template < typename T, typename Container >
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend( void ) const {
	return (this->::std::stack<T, Container>::c.rend());
}

#endif