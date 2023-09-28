
#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
 
const std::string	BitcoinExchange::data_file_  = "data.csv";

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange( void ) 
: fname_("") { 
	this->processDataFile_();
}

BitcoinExchange::BitcoinExchange( std::string input_file )
: fname_(input_file) {
	this->processDataFile_();//build database
}
BitcoinExchange::BitcoinExchange( const BitcoinExchange& to_copy ) {
	*this = to_copy;
}


/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange( void )
{
	/* destructor */
}
 

/* OPERATOR OVERLOADS */

BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& to_copy )
{
	if (this != &to_copy) {
		this->fname_ = to_copy.fname_;
		this->database_ = to_copy.database_;
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

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
	//
	for (std::map<std::string, float>::const_iterator iter = this->database_.begin(); iter != this->database_.end(); iter++) {
		std::cout << iter->first << " " << std::fixed << std::setprecision(2) << iter->second <<std::endl;
	}//
	data_file.close();
}

/* CLASS EXCEPTIONS */
// const char* BitcoinExchange::BadFileNameException::what( void ) const throw() {
// 	return ("Error: could not open file");
// }
