
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed& to_copy );
		Fixed( const int fpNum );
		Fixed( const float fpNum);

		~Fixed( void );

		Fixed&	operator=(const Fixed& to_copy);

		// The 6 comparison operators: >, <, >=, <=, == and !=.
		bool	operator>(const Fixed& rhs);
		bool	operator<(const Fixed& rhs);
		bool	operator>=(const Fixed& rhs);
		bool	operator<=(const Fixed& rhs);
		bool	operator==(const Fixed& rhs);
		bool	operator!=(const Fixed& rhs);

		// The 4 arithmetic operators: +, -, *, and /.
		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

		//  The 4 increment/decrement (pre-increment and post-increment
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static	const Fixed&	min(const Fixed& one, const Fixed& two);
		static	Fixed&	min(Fixed& one, Fixed& two);
		static	const Fixed&	max(const Fixed& one, const Fixed& two);
		static	Fixed&	max(Fixed& one, Fixed& two);

	private:
		static const int	_fractionlBits;
		int					_fixed_point_num;
};

std::ostream&	operator<<(std::ostream& output_stream, const Fixed& to_print);

#endif
