#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog( const Dog& to_copy );

		~Dog( void );

		Dog&	operator=( const Dog& to_copy );

		/* PUBLIC METHODS */
		void	makeSound( void ) const;
		void	printBrainAddress( void ) const;
		
	private:
		Brain	*brain_;
};

#endif
