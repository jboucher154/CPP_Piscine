#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class	WrongAnimal 
{
	public:
		WrongAnimal( void );
		WrongAnimal( /*add parameters*/ );
		WrongAnimal( const WrongAnimal& to_copy );

		~WrongAnimal( void );

		WrongAnimal&	operator=( const WrongAnimal& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
