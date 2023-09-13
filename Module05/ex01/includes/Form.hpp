#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form 
{
	public:
		Form( void );
		Form( const std::string name, const int signGrade, const int executeGrade ) throw(GradeTooLowException, GradeTooHighException);
		Form( const Form& to_copy );

		~Form( void );

		Form&	operator=( const Form& to_copy );

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
		/* PUBLIC METHODS */
		/* getters */
		std::string const	getName( void ) const;
		bool				getSignedStatus( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;
		/*  */
		void				beSigned(Bureaucrat& cog) throw(GradeTooLowException);
		
	private:
		const std::string	name_;
		const int			signGrade_;
		const int			executeGrade_;		
		bool				signed_;
};

std::ostream&	operator << (std::ostream& output_stream, const Form& to_print);

#endif
