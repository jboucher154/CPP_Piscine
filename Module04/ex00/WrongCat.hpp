#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class	WrongCat 
{
	public:
		WrongCat( void );
		WrongCat( /*add parameters*/ );
		WrongCat( const WrongCat& to_copy );

		~WrongCat( void );

		WrongCat&	operator=( const WrongCat& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
