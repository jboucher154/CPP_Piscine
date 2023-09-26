#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
// # include <deque>
# include <vector>
# include <iterator>

template < typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	private:
		/* PRIVATE METHODS AND MEMBERS */

	public:
		MutantStack( void ) : std::stack<T, Container>() {};
		MutantStack<T, Container>( Container existing ) : std::stack<T, Container>(existing) {}; 
		MutantStack( const MutantStack<T>& to_copy ) {
			*this = to_copy;
		};

		~MutantStack( void ) {};

		MutantStack&	operator=( const MutantStack<T>& to_copy ) {
			if (this != &to_copy) {
				std::stack<T>::operator=(to_copy);
			}
			return (*this);
		};

		/* TYPEDEFS */
		typedef	typename std::stack<T>::container_type::iterator iterator;
		typedef	typename std::stack<T>::container_type::const_iterator const_iterator;

		/* PUBLIC METHODS */
		MutantStack::iterator	begin( void ) {
			return (this->::std::stack<T>::c.begin());
		}
		MutantStack::iterator	end( void ) {
			return (this->::std::stack<T>::c.end());
		}
		MutantStack::const_iterator	begin( void ) const {
			return (this->::std::stack<T>::c.begin());
		}
		MutantStack::const_iterator	end( void ) const {
			return (this->::std::stack<T>::c.end());
		}
};

#endif
