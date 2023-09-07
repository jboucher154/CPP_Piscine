#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat( void );
		Cat( const Cat& to_copy );

		~Cat( void );

		Cat&	operator=( const Cat& to_copy );

		/* PUBLIC METHODS */
		virtual	void	makeSound( void ) const;
		void			printBrainAddress( void ) const;
		
	private:
		Brain	*brain_;
};

#endif
