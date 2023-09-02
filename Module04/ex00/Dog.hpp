#ifndef DOG_HPP
# define DOG_HPP

class	Dog 
{
	public:
		Dog( void );
		Dog( /*add parameters*/ );
		Dog( const Dog& to_copy );

		~Dog( void );

		Dog&	operator=( const Dog& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
