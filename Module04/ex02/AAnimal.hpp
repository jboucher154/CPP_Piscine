#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class	AAnimal 
{
	public:
		AAnimal( void );
		AAnimal( const AAnimal& to_copy );

		virtual ~AAnimal( void );

		AAnimal&	operator=( const AAnimal& to_copy );

		/* PUBLIC METHODS */
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
		
	protected:
		std::string	type_;
	
	private:
		/* PRIVATE METHODS AND MEMBERS */

};

#endif
 