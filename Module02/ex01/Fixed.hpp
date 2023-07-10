
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed& to_copy );
		Fixed( const int fpNum );
		Fixed( const float fpNum);
		~Fixed( void );

		Fixed			&operator=( Fixed& to_copy);

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
		float	to_float( void ) const;
		int		to_int( void ) const;

	private:
		static const int	_fractionlBits;
		int					_fixed_point_num;
};

std::ostream&	operator<<(std::ostream& output_stream, const Fixed& to_print);

#endif
