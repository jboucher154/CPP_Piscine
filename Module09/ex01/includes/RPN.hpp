#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>

class	RPN 
{
	private:
		RPN( void );
		RPN( const RPN& to_copy );

		~RPN( void );

		RPN&	operator=( const RPN& to_copy );

		/* PRIVATE METHODS AND MEMBERS */
		static std::stack<double>	rpn_stack_;
		static double				result_;
		
		static void		addToStack_( std::string to_eval );
		static double	return_popped( void );

		static void		doOperation( char operand );
		static double	divide_( double lhs, double rhs );
		static double	multiply_( double lhs, double rhs );
		static double	add_( double lhs, double rhs );
		static double	subtract_( double lhs, double rhs );

	public:
		/* PUBLIC METHODS */
		static bool		validateInput( std::string input );
		static bool		calculate( std::string input );
		static double	getResult( void );
};

#endif
