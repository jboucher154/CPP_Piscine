#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>

class	Span 
{
	private:
		Span( void );
		/* PRIVATE METHODS AND MEMBERS */
		std::vector<int>	numbers_;
		unsigned int		max_;

	public:
		Span( unsigned int N );
		Span( const Span& to_copy );

		~Span( void );

		Span&	operator=( const Span& to_copy );

		/* PUBLIC METHODS */
		void	addNumber( int to_add ) throw(std::length_error);
		int		shortestSpan( void ) throw(std::length_error);
		int		longestSpan( void ) throw(std::length_error);
		void	addManyNumbers(int to_add[], size_t size) throw(std::length_error);

};

#endif

