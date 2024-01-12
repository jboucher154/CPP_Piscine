#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class	PmergeMe 
{
	private:
		/* PRIVATE METHODS AND MEMBERS */

	public:
		PmergeMe( void );
		PmergeMe( /*add parameters*/ );
		PmergeMe( const PmergeMe& to_copy );

		~PmergeMe( void );

		PmergeMe&	operator=( const PmergeMe& to_copy );

		/* PUBLIC METHODS */

};

#endif
