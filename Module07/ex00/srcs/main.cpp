#include "whatever.hpp"
#include <string>
#include <iostream>

class TestTemplates
{
	private:
		int	class_value_;
	public:
		TestTemplates(int value): class_value_(value){};
		~TestTemplates(){};
		int	getValue( void ) const { return (this->class_value_);};
		TestTemplates&	operator=(const TestTemplates& rhs) { if (this != &rhs) {this->class_value_ = rhs.class_value_;} return (*this);};
		bool	operator>=(const TestTemplates& rhs) { return (this->class_value_ >= rhs.class_value_);};
};

std::ostream&	operator<<(std::ostream& output_stream, const TestTemplates& to_print) { output_stream << to_print.getValue(); return (output_stream);};




/* FROM SUBJECT */
int main( void ) 
{
	std::cout << "\nTEST FROM SUBJECT" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\nADDITIONAL TESTS" << std::endl;

		float a = 42.1f;
		float b = 49.691f;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		double c = 42.1656684;
		double d = 1.8976443;
		::swap( c, d );
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::cout << "\nTest equivalent values" << std::endl;

		float a = 42.01f;
		float b = 42.01f;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	}
	{
		std::cout <<  "\nTEST WITH USER DEFINED OBJECT" << std::endl;
		TestTemplates a(1);
		TestTemplates b(2);
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}

	return 0;
}