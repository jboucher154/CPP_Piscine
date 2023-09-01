
#include "ScavTrap.hpp"
#include "Color.hpp"

/* CONSTRUCTORS */

//private
ScavTrap::ScavTrap( void ) : ClapTrap("default") {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << COLOR_RESET;
}

ScavTrap::ScavTrap( const ScavTrap& to_copy) : ClapTrap(to_copy.name_) {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	std::cout << COLOR_RESET;
	*this = to_copy;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
}

/* DESTRUCTOR */

ScavTrap::~ScavTrap( void ) {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "ScavTrap deconstructor called" << std::endl;
	std::cout << COLOR_RESET;
}

/* OPERATER OVERLOADERS */

ScavTrap& ScavTrap::operator = ( const ScavTrap& to_copy ) {
	std::cout << COLOR_BRIGHT_GREEN;
	std::cout << "ScavTrap assignment operator called" << std::endl;
	std::cout << COLOR_RESET;
	this->name_ = to_copy.name_;
	this->hit_points_ = to_copy.hit_points_;
	this->energy_points_ = to_copy.energy_points_;
	this->attack_damage_ = to_copy.attack_damage_;
	return (*this);
}

/* PUBLIC METHODS */

void	ScavTrap::gaurdGate( void ) {
	std::cout << "ScavTrap " << this->name_ << " is now in GATE KEEPER MODE!" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	std::cout << COLOR_BRIGHT_GREEN;
	if (this->energy_points_ == 0) {
		std::cout  << "ScavTrap " << this->name_ << " does not have enough energy to attack!" << std::endl;
	}
	else if (this->hit_points_ <= 0) {
		std::cout  << "ScavTrap " << this->name_ << " is dead!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing " << this->attack_damage_ << " pts of damage!" << std::endl;
		this->energy_points_ -= 1;
	}
	std::cout << COLOR_RESET;
}
