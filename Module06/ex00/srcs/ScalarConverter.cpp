
#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

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
bool	ScalarConverter::inf_found_ = false;
long double	ScalarConverter::limit_checker = 0;

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

/* PRIVATE MEMBER FUNCTIONS */

long double	ScalarConverter::setLimitChecker( std::string& input)
{
	if (ScalarConverter::Type_ == charDataType)
	{
		return (static_cast<long double>(input[0]));
	}
	else
	{
		try
		{
			long double	check_against = stold(input, nullptr);
			return (check_against);
		}
		catch (std::exception& e)
		{
			return (0);
		}
	}
	return (0);
}

bool	ScalarConverter::checkInRange( int type_to_check)
{
	bool	in_limits;

	switch (type_to_check)
	{
		case charDataType:
			in_limits = ScalarConverter::limit_checker <= std::numeric_limits<char>::max() && ScalarConverter::limit_checker >= std::numeric_limits<char>::min();
			break ;
		case intDataType:
			in_limits = ScalarConverter::limit_checker <= std::numeric_limits<int>::max() && ScalarConverter::limit_checker >= std::numeric_limits<int>::min();
			break ;
		case floatDataType:
			in_limits = ScalarConverter::limit_checker <= std::numeric_limits<float>::max() && ScalarConverter::limit_checker >= -std::numeric_limits<float>::max();//
			break ;
		case doubleDataType:
			in_limits = ScalarConverter::limit_checker <= std::numeric_limits<double>::max() && ScalarConverter::limit_checker >= -std::numeric_limits<double>::max();//
			break ;
		default:
			in_limits = false;
			break ;
	}
	return (in_limits);
}

void	ScalarConverter::convertToChar( void )
{
	if (ScalarConverter::checkInRange(charDataType) && ScalarConverter::char_flag_)
	{
		switch (ScalarConverter::Type_)
		{
			case intDataType:
				ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::int_convert_);
				break ;
			case floatDataType:
				ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::float_convert_);
				break ;
			case doubleDataType:
				ScalarConverter::char_convert_ = static_cast<char>(ScalarConverter::double_convert_);
				break ;
			default:
				break ;
		}
	}
	else
	{
		ScalarConverter::char_flag_ = false;
	}
}

void	ScalarConverter::printChar( void )
{
	std::cout << std::left;
	std::cout<< std::setw(10);
	if (ScalarConverter::Type_ == noDataType || ScalarConverter::nan_found_ || ScalarConverter::inf_found_ || ScalarConverter::char_flag_ == false)
	{
		std::cout << "char:" << "impossible" << std::endl;
	}
	else if (!std::isprint(ScalarConverter::char_convert_))
	{
		std::cout << "char:" << "not printable" << std::endl;
	}
	else
	{
		std::cout << "char:" << "'" << std::setw(0) << ScalarConverter::char_convert_ << "'"<< std::endl;
	}		
}

void	ScalarConverter::convertToInt( void )
{
	if (ScalarConverter::checkInRange(intDataType) && ScalarConverter::int_flag_)
	{
		switch (ScalarConverter::Type_)
		{
			case charDataType:
				ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::char_convert_);
				break ;
			case floatDataType:
				ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::float_convert_);
				break ;
			case doubleDataType:
				ScalarConverter::int_convert_ = static_cast<int>(ScalarConverter::double_convert_);
				break ;
			default:
				break ;
		}
	}
	else
	{
		ScalarConverter::int_flag_ = false;
	}
}

void	ScalarConverter::printInt( void )
{
	std::cout << std::left;
	std::cout<< std::setw(10);
	if (ScalarConverter::Type_ == noDataType || ScalarConverter::nan_found_ || ScalarConverter::inf_found_ || ScalarConverter::int_flag_ == false)
	{
		std::cout << "int:" << "impossible" << std::endl;
	}
	else
	{
		std::cout << "int:" << ScalarConverter::int_convert_ << std::endl;
	}
}

void	ScalarConverter::convertToFloat( void )
{
	if (ScalarConverter::checkInRange(floatDataType) && ScalarConverter::float_flag_)
	{
		switch (ScalarConverter::Type_)
		{
			case charDataType:
				ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::char_convert_);
				break ;
			case intDataType:
				ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::int_convert_);
				break ;
			case doubleDataType:
				ScalarConverter::float_convert_ = static_cast<float>(ScalarConverter::double_convert_);
				break ;
			default:
				break ;
		}
	}
	else
	{
		ScalarConverter::float_flag_ = false;
	}
}

void	ScalarConverter::printFloat( void )
{
	std::cout << std::left;
	std::cout<< std::setw(10);
	if (ScalarConverter::Type_ == nanDataType)
	{
		std::cout << "float:" << "nanf" << std::endl;
	}
	else if (ScalarConverter::Type_ == negInfDataType)
	{
		std::cout << "float:" << "-inff" << std::endl;
	}
	else if (ScalarConverter::Type_ == posInfDataType)
	{
		std::cout << "float:" << "+inff" << std::endl;
	}
	else if (ScalarConverter::Type_ == noDataType || (ScalarConverter::float_flag_ == false && ScalarConverter::Type_ != nanDataType))
	{
		std::cout << "float:" << "impossible" << std::endl;
	}
	else
	{
		float mantissa = ScalarConverter::float_convert_ - static_cast<int>(float_convert_);
		if (mantissa != 0.0f)
			std::cout << "float:" << ScalarConverter::float_convert_ << std::setw(0) << "f"<< std::endl;
		else
			std::cout << "float:" << ScalarConverter::float_convert_ << std::setw(0) << ".0f" << std::endl;
	}
}

void	ScalarConverter::convertToDouble( void )
{
	if (ScalarConverter::checkInRange(doubleDataType) && ScalarConverter::double_flag_)
	{
		switch (ScalarConverter::Type_)
		{
			case charDataType:
				ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::char_convert_);
				break ;
			case intDataType:
				ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::int_convert_);
				break ;
			case floatDataType:
				ScalarConverter::double_convert_ = static_cast<double>(ScalarConverter::float_convert_);
				break ;
			default:
				break ;
		}
	}
	else
	{
		ScalarConverter::double_flag_ = false;
	}
}

void	ScalarConverter::printDouble( void )
{
	std::cout << std::left;
	std::cout<< std::setw(10);
	if (ScalarConverter::Type_ == nanDataType)
	{
		std::cout << "double:" << "nan" << std::endl;
	}
	else if (ScalarConverter::Type_ == negInfDataType)
	{
		std::cout << "double:" << "-inf" << std::endl;
	}
	else if (ScalarConverter::Type_ == posInfDataType)
	{
		std::cout << "double:" << "+inf" << std::endl;
	}
	else if (ScalarConverter::Type_ == noDataType || (ScalarConverter::double_flag_ == false && ScalarConverter::Type_ != nanDataType))
	{
		std::cout << "double:" << "impossible" << std::endl;
	}
	else
	{
		double mantissa = ScalarConverter::float_convert_ - static_cast<int>(float_convert_);
		if (mantissa != 0.0f)
			std::cout << "double:" << ScalarConverter::double_convert_ << std::endl;
		else
			std::cout << "double:" << ScalarConverter::double_convert_ << std::setw(0) << ".0" << std::endl;
	}
}

/*
 * Count number of decimals to determine if possible number and clasify 
 * possibility of float.
*/
static int decimalCount( const std::string& temp )
{
	int decimal_count = 0;
	size_t pos = temp.find(".");
	while ( pos != std::string::npos && decimal_count <= 1)
	{
		decimal_count++;
		pos = temp.find(".", pos + 1);//
	}
	return (decimal_count);
}

/*
 * Check if value passed is non a number. 
 * If length is one it is considered a number as it can be converted 
 * to a character
*/
bool ScalarConverter::isNaN( const std::string& input )
{
	if (!input.compare("nan") || !input.compare("nanf"))
	{
		ScalarConverter::nan_found_ = true;
		return (true);
	}
	return (false);
}

/*
 * Check against infite literals given to cover in subject.
*/
bool ScalarConverter::isInf( const std::string& input )
{
	std::string	inf_literals[] = { "-inff", "+inff", "-inf", "+inf"};

	for (int i = 0; i < 4; i++)
	{
		if (!input.compare(inf_literals[i]))
		{
			ScalarConverter::inf_found_ = true;
			return (true);
		}
	}
	return (false);
}

bool	ScalarConverter::isPossible( const std::string& input )
{
	std::string temp = input;

	if (temp.length() == 1)
		return (true);
	if (decimalCount(input) > 1)
		return (false);
	if (temp.back() == 'f')
		temp.pop_back();
	if (temp.front() == '-' || temp.front() == '+')
		temp.erase(0,1);
	if (temp.find_first_not_of("0123456789.") != std::string::npos)
		return (false);
	return (true);
}

/*
 * Set type of intial string passed.
*/
void	ScalarConverter::detectType( const std::string& input )
{
	if (ScalarConverter::isNaN(input) || ScalarConverter::isInf(input))
	{
		if (ScalarConverter::nan_found_ == true)
			ScalarConverter::Type_ = nanDataType;
		else if (input.front() == '+')
			ScalarConverter::Type_ = posInfDataType;
		else
			ScalarConverter::Type_ = negInfDataType;
	}
	else if (input.empty() || !ScalarConverter::isPossible(input))
		ScalarConverter::Type_ = noDataType;
	else if (input.length() == 1 && !std::isdigit(input[0]))
		ScalarConverter::Type_ = charDataType;
	else
	{
		try 
		{
			long double	doubleConversion = stold(input, nullptr);
			if (decimalCount(input) == 1 && input.back() == 'f' && doubleConversion <= std::numeric_limits<float>::max() && doubleConversion <= std::numeric_limits<float>::max())
				ScalarConverter::Type_ = floatDataType;
			else if (decimalCount(input) == 0 && doubleConversion <= std::numeric_limits<int>::max() && doubleConversion >= std::numeric_limits<int>::min())
				ScalarConverter::Type_ = intDataType;
			else if (doubleConversion <= std::numeric_limits<double>::max() && doubleConversion <= std::numeric_limits<double>::max())
				ScalarConverter::Type_ = doubleDataType;
			else
				ScalarConverter::Type_ = noDataType;
		}
		catch (std::exception& e)
		{
			ScalarConverter::Type_ = noDataType;
		}
	}
}

void	ScalarConverter::doFirstConversion( std::string& input )
{
	try
	{
		switch(ScalarConverter::Type_)
		{
			case charDataType:
				ScalarConverter::char_convert_ = input.front();
				break;
			case intDataType:
				ScalarConverter::int_convert_ = stoi(input, nullptr);
				break;
			case floatDataType:
				ScalarConverter::float_convert_ = stof(input, nullptr);
				break;
			case doubleDataType:
				ScalarConverter::double_convert_ = stod(input, nullptr);
				break;
			default:
				ScalarConverter::char_flag_ = false;
				ScalarConverter::int_flag_ = false;
				ScalarConverter::float_flag_ = false;
				ScalarConverter::double_flag_ = false;
				break;
		}
	}
	catch(const std::exception& e)
	{
		ScalarConverter::char_flag_ = false;
		ScalarConverter::int_flag_ = false;
		ScalarConverter::float_flag_ = false;
		ScalarConverter::double_flag_ = false;
		std::cerr << e.what() << '\n';
	}
	
}

/* PUBLIC CLASS STATIC METHODS */

void	ScalarConverter::Convert( std::string input ) 
{

	ScalarConverter::detectType(input);
	ScalarConverter::limit_checker = ScalarConverter::setLimitChecker(input);
	doFirstConversion(input);
	if (ScalarConverter::Type_ != charDataType)
	{
		ScalarConverter::convertToChar();
	}
	if (ScalarConverter::Type_ != intDataType)
	{
		ScalarConverter::convertToInt();
	}
	if (ScalarConverter::Type_ != floatDataType)
	{
		ScalarConverter::convertToFloat();
	}
	if (ScalarConverter::Type_ != doubleDataType)
	{
		ScalarConverter::convertToDouble();
	}
	ScalarConverter::printChar();
	ScalarConverter::printInt();
	ScalarConverter::printFloat();
	ScalarConverter::printDouble();
}