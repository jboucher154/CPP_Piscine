#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits.h>
# include <float.h>

class	ScalarConverter 
{
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter& to_copy );
		~ScalarConverter( void );
		ScalarConverter&	operator=( const ScalarConverter& to_copy );

		char	toChar( std::string input ) const;
		int		toInt( std::string input ) const;
		float	toFloat( std::string input ) const;
		double	toDouble( std::string input ) const;

		static int		Type_;
		static char		char_convert_;
		static int		int_convert_;
		static float	float_convert_;
		static double	double_convert_;

	public:
		static enum eDataTypes
		{
			noDataType,
			charDataType,
			intDataType,
			floatDataType,
			doubleDataType
		};

		static void	Convert( std::string input );
		static void	DetectType( std::string input );
};

#endif
