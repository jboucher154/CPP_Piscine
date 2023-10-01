#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <exception>

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
		BitcoinExchange( const BitcoinExchange& to_copy );

		~BitcoinExchange( void );

		BitcoinExchange&	operator=( const BitcoinExchange& to_copy );

		void	processLine( std::string& input_line );
		void	validateLine( std::string& input_line, size_t date_length );
		std::map<std::string, float>::const_iterator	searchForInput(std::string& str_date);
		void	printResult(float entry, std::string date, float value);

		/* CLASS EXCEPTIONS */
		class	BadInputException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		class	BadDateException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		class	ValueTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		class	ValueTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		/* PUBLIC METHODS */
		void	processInput( std::string input_file );


};

#endif
