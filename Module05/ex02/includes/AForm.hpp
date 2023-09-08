#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm 
{
	public:
		AForm( void );
		AForm( const std::string name, const int signGrade, const int executeGrade ) throw(GradeTooLowException, GradeTooHighException);
		AForm( const AForm& to_copy );

		~AForm( void );

		AForm&	operator=( const AForm& to_copy );

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

std::ostream&	operator << (std::ostream& output_stream, const AForm& to_print);

#endif
