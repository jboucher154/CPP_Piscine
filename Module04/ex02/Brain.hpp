#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain 
{
	public:
		Brain( void );
		Brain( const Brain& to_copy );

		~Brain( void );

		Brain&	operator=( const Brain& to_copy );
		
	private:
		std::string ideas_[100];
};

#endif
