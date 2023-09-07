#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Bureaucrat 
{

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade ); // throw exception for out of range
		Bureaucrat( const Bureaucrat& to_copy );

		~Bureaucrat( void );

		Bureaucrat&	operator=( const Bureaucrat& to_copy );

		/* PUBLIC METHODS */
		std::string const	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				incrementGrade( void ); // throw exception for out of range
		void				decrementGrade( void ); // throw exception for out of range

		
	private:
		const std::string	name_;
		int					grade_; // high 1 - 150 low
		
		/* NESTED CLASESS */

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
};

//print -> <name>, bureaucrat grade <grade>
std::ostream&	operator<<(std::ostream& output_stream, const Bureaucrat& to_print);

#endif
