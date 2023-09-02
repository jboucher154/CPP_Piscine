#ifndef CAT_HPP
# define CAT_HPP

class	Cat 
{
	public:
		Cat( void );
		Cat( /*add parameters*/ );
		Cat( const Cat& to_copy );

		~Cat( void );

		Cat&	operator=( const Cat& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
