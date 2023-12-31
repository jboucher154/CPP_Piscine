
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed& to_copy );
		~Fixed( void );
		Fixed &operator=( const Fixed& to_copy);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		static const int	_fractionlBits;
		int					_fixed_point_num;
};

#endif
