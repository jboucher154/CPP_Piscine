#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

class	ScalarConverter 
{
	private:
		/* PRIVATE METHODS AND MEMBERS */

	public:
		ScalarConverter( void );
		ScalarConverter( /*add parameters*/ );
		ScalarConverter( const ScalarConverter& to_copy );

		~ScalarConverter( void );

		ScalarConverter&	operator=( const ScalarConverter& to_copy );

		/* PUBLIC METHODS */

};

#endif
