#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
class	Cat : public Animal
{
	public:
		Cat( void );
		// Cat( /*add parameters*/ );
		Cat( const Cat& to_copy );

		~Cat( void );

		Cat&	operator=( const Cat& to_copy );

		/* PUBLIC METHODS */
		void		makeSound( void ) const;
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
