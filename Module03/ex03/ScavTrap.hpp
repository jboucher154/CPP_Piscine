
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {

	public:
		ScavTrap( const ScavTrap& to_copy);
		ScavTrap( std::string name );
		~ScavTrap( void );

		ScavTrap& operator=( const ScavTrap& to_copy );

		void	attack( const std::string& target );
		void	gaurdGate( void );

	// protected:
	// 	int energy_points_;

	private:
		ScavTrap( void );

};

#endif