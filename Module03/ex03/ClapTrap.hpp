
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

		ClapTrap&	operator=( const ClapTrap& to_copy );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	protected:
		std::string		name_;
		int				hit_points_;
		int				energy_points_;
		int				attack_damage_;
		
		ClapTrap( void );

	private:

};

#endif