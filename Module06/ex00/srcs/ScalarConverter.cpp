
#include "ScalarConverter.hpp"
#include <iostream>

int		ScalarConverter::Type_ = noDataType;
char	ScalarConverter::char_convert_ = 0;
bool	ScalarConverter::char_flag_ = true;
int		ScalarConverter::int_convert_ = 0;
bool	ScalarConverter::int_flag_ = true;
float	ScalarConverter::float_convert_ = 0;
bool	ScalarConverter::float_flag_ = true;
double	ScalarConverter::double_convert_ = 0;
bool	ScalarConverter::double_flag_ = true;
bool	ScalarConverter::nan_found_ = false;

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

void	ScalarConverter::toChar( void )
{
	// long double	int_val = stold(input);

	// if (int_val <= CHAR_MAX && int_val <= CHAR_MIN)
	// {
	// 	ScalarConverter::char_convert_ = int_val;
	// }
	//else is out of bounds
	if (ScalarConverter::Type_ == intDataType)
	{
		if (!(ScalarConverter::int_convert_ <= CHAR_MAX && ScalarConverter::int_convert_ >= CHAR_MIN))
			ScalarConverter::char_flag_ = false;
		ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::int_convert_);
	}
	else if (ScalarConverter::Type_ == floatDataType)
	{
		if (!(ScalarConverter::float_convert_ <= CHAR_MAX && ScalarConverter::float_convert_ >= CHAR_MIN))
			ScalarConverter::char_flag_ = false;
		ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::float_convert_);
	}
	else if (ScalarConverter::Type_ == doubleDataType)
	{
		if (ScalarConverter::double_convert_ <= CHAR_MAX && ScalarConverter::double_convert_ <= CHAR_MIN)
			ScalarConverter::char_flag_ = false;
		ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::double_convert_);
	}
}

void	ScalarConverter::toInt( void )
{
	if (ScalarConverter::Type_ == charDataType)
	{
		ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::char_convert_);
	}
	else if (ScalarConverter::Type_ == floatDataType)
	{
		ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::float_convert_);
	}
	else if (ScalarConverter::Type_ == doubleDataType)
	{
		ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::double_convert_);
	}
}

void	ScalarConverter::toFloat( void )
{
	// long double	int_val = stold(input);

	// if (int_value <= FLT_MAX && int_value >= FLT_MIN)
	// {
	// 	ScalarConverter::float_convert_ = int_value;
	// }
	if (ScalarConverter::Type_ == intDataType)
	{
		ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::int_convert_);
	}
	else if (ScalarConverter::Type_ == charDataType)
	{
		ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::char_convert_);
	}
	else if (ScalarConverter::Type_ == doubleDataType)
	{
		ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::double_convert_);
	}
}

void	ScalarConverter::toDouble( void )
{
	// long double	int_val = stold(input);

	// if (int_value <= FLT_MAX && int_value >= FLT_MIN)
	// {
	// 	ScalarConverter::float_convert_ = int_value;
	// }
	if (ScalarConverter::Type_ == intDataType)
	{
		ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::int_convert_);
	}
	else if (ScalarConverter::Type_ == floatDataType)
	{
		ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::float_convert_);
	}
	else if (ScalarConverter::Type_ == charDataType)
	{
		ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::char_convert_);
	}
}

/* CLASS STATIC METHODS */

void	ScalarConverter::Convert( std::string input ) 
{
	ScalarConverter::DetectType(input);
	if (ScalarConverter::Type_ == noDataType)
	{
		// no valid types found...
	}
	if (ScalarConverter::Type_ != charDataType)
		ScalarConverter::toChar();
	if (ScalarConverter::char_flag_ == true)
		std::cout << "char: " << ScalarConverter::char_convert_ << " flag: " << ScalarConverter::char_flag_ << std::endl;
	else
		std::cout << "char: value not a valid char" << std::endl;
	// if (ScalarConverter::Type_ != int)
	// 	ScalarConverter::toInt();
	// if (ScalarConverter::Type_ != float)
	// 	ScalarConverter::toFloat();
	// if (ScalarConverter::Type_ != double)
	// 	ScalarConverter::toDouble();
}

static int decimalCount( const std::string& temp )
{
	int decimal_count = 0;
	size_t pos = temp.find(".");
	while ( pos != std::string::npos)
	{
		decimal_count++;
		pos = temp.find(".", pos + 1);//
	}
	return (decimal_count);
}

bool ScalarConverter::isNaN( std::string& input )
{
	std::string temp = input;

	if (temp.length() == 1)
		return (false);
	if (temp.back() == 'f')
		temp.pop_back();
	if (!temp.compare("nan"))
		return (true);
	if (decimalCount(temp) > 1)
		return (true);	
	if (temp.find_first_not_of("0123456789.") != std::string::npos)
		return (true);
	return (false);
}

void	ScalarConverter::DetectType( std::string& input )
{
	//check against empty string, nans, infs...
	if (isNaN(input) == true)
	{
		ScalarConverter::nan_found_ = true;
		return ;
	}
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		ScalarConverter::Type_ = charDataType;
		ScalarConverter::char_convert_ = input.front();
	}
	else if (input.back() == 'f')
	{
		ScalarConverter::Type_ = floatDataType;
		ScalarConverter::float_convert_ = stof(input, nullptr);
	}
	else
	{
		long int	longConversion = stol(input, nullptr, 10);
		long double	doubleConversion = stold(input, nullptr);
		if (longConversion <= INT_MAX && longConversion >= INT_MIN)
		{
			ScalarConverter::Type_ = intDataType;
			ScalarConverter::int_convert_ = stoi(input, nullptr);
		}
		else if (doubleConversion <= DBL_MAX && doubleConversion <= DBL_MIN)
		{
			ScalarConverter::Type_ = doubleDataType;
			ScalarConverter::double_convert_ = stod(input, nullptr);
		}
		else
		{
			ScalarConverter::Type_ = noDataType;
		}
	}
	std::cout << "type set as: " << ScalarConverter::Type_ << std::endl;
}