
#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <ctime>
 
const std::string	BitcoinExchange::data_file_  = "data.csv";

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange( void ) 
: input_file_("") { 
	this->processDataFile_();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& to_copy ) {
	*this = to_copy;
}


/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange( void ) {
	/* destructor */
}
 

/* OPERATOR OVERLOADS */

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& to_copy ) {
	if (this != &to_copy) {
		this->input_file_ = to_copy.input_file_;
		this->database_ = to_copy.database_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

/*Functions for line validation*/
static bool	isLeapYear( int year ) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
		return (true);
	}
	return (false);
}

static bool validateYear( std::tm *local_time, int year ) {
	return (year < local_time->tm_year + 1900 && year >= 1900);
}

static bool validateMonth(std::tm *local_time, int year, int month) {
	if (month < 1 || month > 12) {
		return (false);
	}
	else if ((year == local_time->tm_year + 1900) && month > local_time->tm_mon) {
		return (false);
	}
	return (true);
}

static bool validateDay(std::tm *local_time, int year, int month, int day) {
	if ( day > 31 || day < 1 ) {
		return (false);
	}
	else if (month == 2 && (day > 29 || (isLeapYear(year) && day  > 28))) {
		return (false);
	}
	else if (((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		return (false);
	}
	else if ((year == local_time->tm_year + 1900) && month == local_time->tm_mon && day > local_time->tm_mday) {
		return (false);
	}
	return (true);
}

static bool	checkDate(int year, int month, int day) {
	std::time_t	now_time = std::time(NULL);
	std::tm*	local_time = std::localtime(&now_time);

	bool valid_year_value  = validateYear(local_time, year);
	bool valid_month_value = validateMonth(local_time, year, month);
	bool valid_day_value = validateDay(local_time, year, month, day);
	if (!valid_year_value || !valid_month_value || !valid_day_value) {
		return (false);
	}
	return (true);
}

void	BitcoinExchange::validateLine( std::string input_line ) {

	std::istringstream	ss_line(input_line);
	int		year, month, day;
	float	value;
	char	trash;
	
	ss_line >> year >> trash >> month >> trash >> day >> trash >> value;
	if (ss_line.fail() && trash != '|' && !ss_line.eof()) {
		throw(BadInputException());
	}
	if (!checkDate(year, month, day)) {
		throw(BadDateException());
	}
	if (value > 1000) {
		throw(ValueTooHighException());
	}
	else if (value < 0) {
		throw(ValueTooLowException());
	}
	// std::cout << year << " " << month << " " << day << " " << value << std::endl;//
}
/**/

void	BitcoinExchange::processLine( std::string input_line ) {
	//validate the line
	try {
		validateLine(input_line);
		//search for match
		std::map<std::string, float>::const_iterator = searchForInput(input_line);
		//calculate output
		//print output
	} catch (BadInputException& e) {
		std::cout << "Error: " << e.what() << input_line << std::endl;
	} catch (BadDateException& e) {
		std::istringstream	ss_for_date(input_line);
		std::string str_date;
		getline(ss_for_date, str_date, '|');
		std::cout << "Error: " << e.what() << " " << str_date << std::endl;
	} catch (ValueTooLowException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	} catch (ValueTooHighException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void	BitcoinExchange::processInput( std::string input_file ) {
	std::ifstream 	data_file(input_file);
	std::string		line;

	if (data_file.fail()) {
		throw (std::runtime_error("Error: cannot open input file"));
	}
	while (getline(data_file, line)) {
		if (!line.empty()) {
			processLine(line);
		}
	}
}

/* CLASS PRIVATE METHODS */

void	BitcoinExchange::processDataFile_( void ) {
	std::ifstream 	data_file(BitcoinExchange::data_file_);

	if (data_file.fail()) {
		throw (std::runtime_error("Error: cannot open data file"));
	}
	std::string		line;

	getline(data_file, line);
	while (getline(data_file, line)) {
		std::istringstream	entry(line);
		std::string key;
		float	flt_val;
		if ((getline(entry, key, ',') && (entry >> flt_val))) {
			if (!key.empty()) {
				this->database_[key] = flt_val;
			}
		} else {
			throw (std::runtime_error("Error: invalid contents of data file"));
		}
	}
	// //
	// for (std::map<std::string, float>::const_iterator iter = this->database_.begin(); iter != this->database_.end(); iter++) {
	// 	std::cout << iter->first << " " << std::fixed << std::setprecision(2) << iter->second <<std::endl;
	// }//
	data_file.close();
}

/* CLASS EXCEPTIONS */
const char* BitcoinExchange::BadInputException::what( void ) const throw() {
	return ("bad input =>");
}

const char* BitcoinExchange::BadDateException::what( void ) const throw() {
	return ("bad input =>");
}

const char* BitcoinExchange::ValueTooHighException::what( void ) const throw() {
	return ("too large a number.");
}

const char* BitcoinExchange::ValueTooLowException::what( void ) const throw() {
	return ("not a positive number.");
}