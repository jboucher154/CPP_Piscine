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

		static void	toChar( void );
		static void	toInt( void );
		static void	toFloat( void );
		static void	toDouble( void );
		static void	DetectType( std::string& input );

		static bool isNaN( std::string& input );

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

	public:
		enum eDataTypes
		{
			noDataType,
			charDataType,
			intDataType,
			floatDataType,
			doubleDataType
		};

		static void	Convert( std::string input );
};

#endif
