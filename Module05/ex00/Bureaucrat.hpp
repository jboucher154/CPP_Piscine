#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	Bureaucrat 
{
	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade ) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat( const Bureaucrat& to_copy );

		~Bureaucrat( void );

		Bureaucrat&	operator=( const Bureaucrat& to_copy );

		/* PUBLIC METHODS */
		std::string const	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
	
	
	/* NESTED CLASSES - should they be public or private?*/
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what( void ) const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what( void ) const throw();
	};
	private:
		const			std::string name_;
		unsigned int	grade_; // high 1 - 150 low
};

//print -> <name>, bureaucrat grade <grade>
std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print);

#endif
