
#include "ScavTrap.hpp"

/* CONSTRUCTORS */

//private
ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}
//add claptrap call here?
ScavTrap::ScavTrap( const ScavTrap& to_copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = to_copy;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

/* DECONSTRUCTOR */
//add claptrap call here?
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

/* OPERATER OVERLOADERS */
//add claptrap call here?
ScavTrap& ScavTrap::operator = ( const ScavTrap& to_copy ) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_name = to_copy._name;//check this
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	return (*this);
}

/* PUBLIC METHODS */

void	ScavTrap::gaurdGAte( void ) {
	std::cout << "ScavTrap " << this->_name << " is now in GATE KEEPER MODE!" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	if (this->_energy_points == 0)
		std::cout  << "ScavTrap " << this->_name << " does not have enough energy to attack!" << std::endl;
	else if (this->_hit_points <= 0) {
		std::cout  << "ScavTrap " << this->_name << " is dead!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " pts of damage!" << std::endl;
		this->_energy_points -= 1;
	}
}
