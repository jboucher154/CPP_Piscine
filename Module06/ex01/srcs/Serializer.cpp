
#include "Serializer.hpp"

/* CONSTRUCTORS */

Serializer::Serializer( void )
{ /* default constructor */ }

Serializer::Serializer( const Serializer& to_copy )
{ 
	*this = to_copy; 
}

/* DESTRUCTOR */

Serializer::~Serializer( void )
{ /* destructor */ }

/* OPERATOR OVERLOADS */

Serializer&	Serializer::operator=( const Serializer& to_copy )
{
	( void ) to_copy;
	return (*this);
}

/* CLASS PUBLIC METHODS */

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

