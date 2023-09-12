#ifndef INTERN_HPP
# define INTERN_HPP

class	Intern 
{
	public:
		Intern( void );
		Intern( /*add parameters*/ );
		Intern( const Intern& to_copy );

		~Intern( void );

		Intern&	operator=( const Intern& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
