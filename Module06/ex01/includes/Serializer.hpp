#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>

struct	Data;

class	Serializer 
{
	private:
		/* PRIVATE METHODS AND MEMBERS */
		Serializer( void );
		Serializer( const Serializer& to_copy );

		~Serializer( void );

		Serializer&	operator=( const Serializer& to_copy );

	public:
		/* PUBLIC METHODS */
		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

};

#endif
