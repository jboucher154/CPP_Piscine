
#include "ScalarConverter.hpp"

int		ScalarConverter::Type_ = ScalarConverter::eDataTypes::noDataType;
char	ScalarConverter::char_convert_ = 0;
int		ScalarConverter::int_convert_ = 0;
float	ScalarConverter::float_convert_ = 0;
double	ScalarConverter::double_convert_ = 0;

/* CONSTRUCTORS */

ScalarConverter::ScalarConverter( void )
{/* default constructor */ }

ScalarConverter::ScalarConverter( const ScalarConverter& to_copy )
{ 
	*this = to_copy;
}

/* DESTRUCTOR */
ScalarConverter::~ScalarConverter( void )
{ /* destructor */ }

/* OPERATOR OVERLOADS */

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& to_copy )
{
	( void ) to_copy;
	return (*this);
}

/* MEMBER FUNCTIONS */

char	ScalarConverter::toChar( std::string input ) const
{

}
int	ScalarConverter::toInt( std::string input ) const
{
	
}

float	ScalarConverter::toFloat( std::string input ) const
{
	
}

double	ScalarConverter::toDouble( std::string input ) const
{

}

/* CLASS STATIC METHODS */

void	ScalarConverter::Convert( std::string input ) 
{

}

void	ScalarConverter::DetectType( std::string input )
{
	//check against empty string, nans, infs...
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		ScalarConverter::Type_ = ScalarConverter::eDataTypes::charDataType;
		ScalarConverter::char_convert_ = input.front();
	}
	else if (input.back() == 'f') //not account for possible trailing ws
	{
		ScalarConverter::Type_ = ScalarConverter::eDataTypes::floatDataType;
		ScalarConverter::float_convert_ = stof(input, nullptr);
	}
	else
	{
		long int	longConversion = stol(input, nullptr, 10);
		long double	doubleConversion = stold(input, nullptr);
		if (longConversion <= INT_MAX && longConversion >= INT_MIN)
		{
			ScalarConverter::Type_ = ScalarConverter::eDataTypes::intDataType;
		}
		else if (doubleConversion <= DBL_MAX && doubleConversion <= DBL_MIN)
		{
			ScalarConverter::Type_ = ScalarConverter::eDataTypes::doubleDataType;
		}
		else
		{
			ScalarConverter::Type_ = ScalarConverter::eDataTypes::noDataType;
		}
	}
}