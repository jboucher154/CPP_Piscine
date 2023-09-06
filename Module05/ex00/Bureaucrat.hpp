#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class	Bureaucrat 
{
	public:
		Bureaucrat( void );
		Bureaucrat( unsigned int grade );
		Bureaucrat( const Bureaucrat& to_copy );

		~Bureaucrat( void );

		Bureaucrat&	operator=( const Bureaucrat& to_copy );

		/* PUBLIC METHODS */
		std::string const	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				incrementGrade( void );
		void				decrementGrade( void );
		
	private:
	const			std::string name_;
	unsigned int	grade_; // high 1 - 150 low
		/* PRIVATE METHODS AND MEMBERS */
};

//print -> <name>, bureaucrat grade <grade>
std::ostream&	operator << (std::ostream& output_stream, const Bureaucrat& to_print);

#endif
