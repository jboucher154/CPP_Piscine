#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog& to_copy );

		~Dog( void );

		Dog&	operator=( const Dog& to_copy );

		/* PUBLIC METHODS */
		virtual	void	makeSound( void ) const;
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
