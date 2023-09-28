#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class	BitcoinExchange 
{
	private:
		BitcoinExchange( void );

		/* PRIVATE METHODS AND MEMBERS */
		std::string						fname_;
		std::map<std::string, float>	database_;

		static const std::string	data_file_;
		void	processDataFile_( void ); // throw(BadFileNameException());

	public:
		BitcoinExchange( std::string input_file );
		BitcoinExchange( const BitcoinExchange& to_copy );

		~BitcoinExchange( void );

		BitcoinExchange&	operator=( const BitcoinExchange& to_copy );

		/* CLASS EXCEPTIONS */
		// class	BadFileNameException : public std::exception {
		// 	virtual const char* what( void ) const throw();
		// };

		/* PUBLIC METHODS */


};

#endif
