#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <iterator>

template < typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	private:
		/* PRIVATE METHODS AND MEMBERS */

	public:
		MutantStack<T, Container>( void );
		MutantStack<T, Container>( Container existing ); 
		MutantStack( const MutantStack<T, Container>& to_copy );

		~MutantStack( void );

		MutantStack&	operator=( const MutantStack<T, Container>& to_copy );

		/* TYPEDEFS */
		typedef	typename std::stack<T, Container>::container_type::iterator 				iterator;
		typedef	typename std::stack<T, Container>::container_type::const_iterator 			const_iterator;
		typedef	typename std::stack<T, Container>::container_type::reverse_iterator 		reverse_iterator;
		typedef	typename std::stack<T, Container>::container_type::const_reverse_iterator	const_reverse_iterator;

		/* PUBLIC METHODS */
		typename MutantStack<T, Container>::iterator		begin( void );
		typename MutantStack<T, Container>::iterator		end( void );
		typename MutantStack<T, Container>::const_iterator	begin( void ) const;
		typename MutantStack<T, Container>::const_iterator	end( void ) const; 
		
		typename MutantStack<T, Container>::reverse_iterator		rbegin( void );
		typename MutantStack<T, Container>::reverse_iterator		rend( void );
		typename MutantStack<T, Container>::const_reverse_iterator	rbegin( void ) const;
		typename MutantStack<T, Container>::const_reverse_iterator	rend( void ) const;
};

#include "MutantStack.tpp"

#endif
