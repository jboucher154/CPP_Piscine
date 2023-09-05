#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal 
{
	public:
		Animal( void );
		Animal( const Animal& to_copy );

		virtual ~Animal( void );

		Animal&	operator=( const Animal& to_copy );

		/* PUBLIC METHODS */
		std::string	getType( void ) const;
		virtual void		makeSound( void ) const;
		
	protected:
		std::string	type_;
	
	private:
		/* PRIVATE METHODS AND MEMBERS */

};

#endif
