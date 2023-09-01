
#include "DiamondTrap.hpp"
#include "Color.hpp"
	
/* CONSTRUCTORS */

DiamondTrap::DiamondTrap( void ) 
: ScavTrap("default"), FragTrap("default"), name_("default") {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->ClapTrap::name_ = "default_clap_name";
	this->hit_points_ = this->FragTrap::hit_points_;
	this->energy_points_ = this->ScavTrap::energy_points_;
	this->attack_damage_ = this->FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap( std::string name ) 
: ScavTrap(name), FragTrap(name), name_(name) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "DiamondTrap parameterized constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->ClapTrap::name_ = name + "_clap_name";
	this->hit_points_ = this->FragTrap::hit_points_;
	this->energy_points_ = this->ScavTrap::energy_points_;
	this->attack_damage_ = this->FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap( const DiamondTrap& to_copy) 
: ClapTrap(to_copy.name_ + "_clap_name"), ScavTrap(to_copy.name_), FragTrap(to_copy.name_) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->ClapTrap::name_ = to_copy.name_ + "_clap_name";
	*this = to_copy;
}

/* DESTRUCTORS */

DiamondTrap::~DiamondTrap( void ) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "DiamondTrap destructor constructor called" << std::endl;
	std::cout << COLOR_RESET;
}

/* OPERATOR OVERLOADS */

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& to_copy ) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	std::cout << COLOR_RESET;
	this->ClapTrap::name_ = to_copy.ClapTrap::name_;
	this->name_ = to_copy.name_;
	this->hit_points_ = to_copy.FragTrap::hit_points_;
	this->energy_points_ = to_copy.ScavTrap::energy_points_;
	this->attack_damage_ = to_copy.FragTrap::attack_damage_;
	return (*this);
}

/* PUBLIC METHODS */

void	DiamondTrap::whoAmI( void ) {
	std::cout << COLOR_BRIGHT_YELLOW;
	std::cout << "I am DiamondTrap " << this->name_ << " and my ClapTrap name is " << this->ClapTrap::name_ << std::endl;
	std::cout << COLOR_RESET;
}

void	DiamondTrap::attack( const std::string& target ) {
	this->ScavTrap::attack(target);
}
