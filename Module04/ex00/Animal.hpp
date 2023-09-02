#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal 
{
	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& to_copy );

		~Animal( void );

		Animal&	operator=( const Animal& to_copy );

		/* PUBLIC METHODS */
		std::string	getType( void ) const;
		void		setType( std::string new_type );
		void		makeSound( void ) const;
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
		std::string	type_;
};

#endif
