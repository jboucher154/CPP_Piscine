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

		static void	printChar( void );
		static void	printInt( void );
		static void	printFloat( void );
		static void	printDouble( void );
		static void printInvalidInput( void );

		static void	convertToChar( void );
		static void	convertToInt( void );
		static void	convertToFloat( void );
		static void	convertToDouble( void );

		static void	detectType( const std::string& input );
		static void	doFirstConversion( std::string& input );
		static long double	setLimitChecker( std::string& input);
		static bool	checkInRange( int type_to_check);

		static bool isNaN( const std::string& input );
		static bool isInf( const std::string& input );
		static bool	isPossible( const std::string& input );

		static int		Type_;
		static char		char_convert_;
		static bool		char_flag_;
		static int		int_convert_;
		static bool		int_flag_;
		static float	float_convert_;
		static bool		float_flag_;
		static double	double_convert_;
		static bool		double_flag_;
		static bool		nan_found_;
		static bool		inf_found_;
		static long double	limit_checker;

		enum eDataTypes
		{
			noDataType,
			charDataType,
			intDataType,
			floatDataType,
			doubleDataType,
			nanDataType,
			posInfDataType,
			negInfDataType
		};
		
	public:

		static void	Convert( std::string input );
};

#endif
