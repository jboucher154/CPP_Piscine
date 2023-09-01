
#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	public:
		DiamondTrap( const DiamondTrap& to_copy);
		DiamondTrap( std::string name );
		~DiamondTrap( void );

		DiamondTrap& operator=( const DiamondTrap& to_copy );

		void	whoAmI( void );
		void	attack( const std::string& target );

	private:
		DiamondTrap( void );

		std::string	name_;
};

#endif