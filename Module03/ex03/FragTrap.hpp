
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	public:
		FragTrap( const FragTrap& to_copy);
		FragTrap( std::string name );
		~FragTrap( void );

		FragTrap& operator = ( const FragTrap& to_copy );

		void	highFivesGuys( void );

	private:
		FragTrap( void );
};

#endif