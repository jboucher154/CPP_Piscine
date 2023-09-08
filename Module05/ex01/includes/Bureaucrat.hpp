#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class	Form;

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
		int					getGrade( void ) const;
		void				incrementGrade( void ) throw(GradeTooHighException);
		void				decrementGrade( void ) throw(GradeTooLowException);
		void				signForm(Form& toSign);//not const?

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
		const std::string	name_;
		int					grade_;
};

std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print);

#endif
