#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
class	WrongAnimal 
{
	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& to_copy );

		~WrongAnimal( void );

		WrongAnimal&	operator=( const WrongAnimal& to_copy );

		/* PUBLIC METHODS */
		std::string	getType( void ) const;
		void		makeSound( void ) const;
	
	protected:
		std::string	type_;
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
