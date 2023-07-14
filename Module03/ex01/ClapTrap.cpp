
#include "ClapTrap.hpp"

/* CONSTRUCTORS */

//set as protected
ClapTrap::ClapTrap( void ) {
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& to_copy ) {
	std::cout << "ClapTrap Copy Constructor Called" << std::endl;
	*this = to_copy;
}

ClapTrap::ClapTrap( std::string name ) 
: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap Parameterized Constructor Called" << std::endl;
}

/* DECONSTRUCTOR */

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Deconstructor Called" << std::endl;
}

/* OPERATOR OVERLOADS */

ClapTrap&	ClapTrap::operator = ( const ClapTrap& to_copy ) {
	std::cout << "ClapTrap Assignment operator Called" << std::endl;
	this->_name = to_copy._name; //check membory on this
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	return (*this);
}

/* PUBLIC METHODS */

void	ClapTrap::attack( const std::string& target ) {
	if (this->_energy_points == 0)
		std::cout  << "ClapTrap " << this->_name << " does not have enough energy to attack!" << std::endl;
	else if (this->_hit_points <= 0) {
		std::cout  << "ClapTrap " << this->_name << " is dead!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " pts of damage!" << std::endl;
		this->_energy_points -= 1;
	}
}
void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_hit_points <= 0) {
		std::cout  << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " receives " << amount << " damage!" << std::endl;
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " now has " << this->_hit_points << " hit points" << std::endl;
}
void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energy_points <= 0)
		std::cout << "ClapTrap " << this->_name << " does not enough energy to repair itself!" << std::endl;
	else if (this->_hit_points <= 0) {
		std::cout  << "ClapTrap " << this->_name << " is dead!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points" << std::endl;
		std::cout << "ClapTrap " << this->_name << " now has " << this->_hit_points << " hit points" << std::endl;
		this->_hit_points += amount;
		this->_energy_points -= 1;
	}
}
