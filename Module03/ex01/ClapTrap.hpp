
#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	public:
		ClapTrap( const ClapTrap& to_copy);
		ClapTrap( std::string name );
		~ClapTrap( void );

		ClapTrap&	operator = ( const ClapTrap& to_copy );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount ); 

	protected:
		ClapTrap( void );

		std::string		_name;
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
		
	private:

};

#endif