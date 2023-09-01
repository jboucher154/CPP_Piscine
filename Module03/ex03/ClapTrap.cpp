
#include "ClapTrap.hpp"

/* CONSTRUCTORS */

//set as private
ClapTrap::ClapTrap( void ) 
: name_("default"), hit_points_(10), energy_points_(10), attack_damage_(0){
	std::cout << "Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& to_copy ) {
	std::cout << "Copy Constructor Called" << std::endl;
	*this = to_copy;
}

ClapTrap::ClapTrap( std::string name ) 
: name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "ClapTrap Parameterized Constructor Called" << std::endl;
}

/* DESTRUCTOR */

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

/* OPERATOR OVERLOADS */

ClapTrap&	ClapTrap::operator=( const ClapTrap& to_copy ) {
	std::cout << "Assignment operator Called" << std::endl;
	this->name_ = to_copy.name_;
	this->hit_points_ = to_copy.hit_points_;
	this->energy_points_ = to_copy.energy_points_;
	this->attack_damage_ = to_copy.attack_damage_;
	return (*this);
}

/* PUBLIC METHODS */

void	ClapTrap::attack( const std::string& target ) {
	if (this->energy_points_ == 0) {
		std::cout  << "ClapTrap " << this->name_ << " does not have enough energy to attack!" << std::endl;
	}
	else if (this->hit_points_ <= 0) {
		std::cout  << "ClapTrap " << this->name_ << " is dead!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->attack_damage_ << " pts of damage!" << std::endl;
		this->energy_points_ -= 1;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->hit_points_ <= 0) {
		std::cout  << "ClapTrap " << this->name_ << " is already dead!" << std::endl;
	}
	else if (this->energy_points_ <= 0) {
		std::cout  << "ClapTrap " << this->name_ << " is out of energy!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name_ << " receives " << amount << " damage!" << std::endl;
		this->hit_points_ -= amount;
		if (this->hit_points_ < 0) {
			this->hit_points_ = 0;
		}
		std::cout << "ClapTrap " << this->name_ << " now has " << this->hit_points_ << " hit points" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energy_points_ <= 0) {
		std::cout << "ClapTrap " << this->name_ << " does not enough energy to repair itself!" << std::endl;
	}
	else if (this->hit_points_ <= 0) {
		std::cout  << "ClapTrap " << this->name_ << " is dead!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->name_ << " repairs itself with " << amount << " hit points" << std::endl;
		this->hit_points_ += amount;
		std::cout << "ClapTrap " << this->name_ << " now has " << this->hit_points_ << " hit points" << std::endl;
		this->energy_points_ -= 1;
	}
}