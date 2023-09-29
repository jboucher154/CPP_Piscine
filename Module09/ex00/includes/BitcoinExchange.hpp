#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>

class	BitcoinExchange 
{
	private:

		/* PRIVATE METHODS AND MEMBERS */
		std::string						input_file_;
		std::map<std::string, float>	database_;

		static const std::string	data_file_;
		void	processDataFile_( void ); // throw(BadFileNameException());

	public:
		BitcoinExchange( void );
		// BitcoinExchange( std::string input_file );
		BitcoinExchange( const BitcoinExchange& to_copy );

		~BitcoinExchange( void );

		BitcoinExchange&	operator=( const BitcoinExchange& to_copy );

		void	processInput( std::string input_file );
		void	processLine( std::string input_line );
		void	validateLine( std::string input_line );

		/* CLASS EXCEPTIONS */
		// class	BadFileNameException : public std::exception {
		// 	virtual const char* what( void ) const throw();
		// };

		/* PUBLIC METHODS */


};

#endif
