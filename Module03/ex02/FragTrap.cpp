
#include "FragTrap.hpp"
#include "Color.hpp"

/* CONSTRUCTORS */

FragTrap::FragTrap( void ) : ClapTrap("default ClapTrap") {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->name_ = "default FragTrap";
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap paramaterized constructor called" << std::endl;
	std::cout << COLOR_RESET;
	this->name_ = name;
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
}

FragTrap::FragTrap( const FragTrap& to_copy) : ClapTrap(to_copy.name_) {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap copy constructor called" << std::endl;
	std::cout << COLOR_RESET;
	*this = to_copy;
}

/* DESTRUCTOR */

FragTrap::~FragTrap( void ) {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap destructor called" << std::endl;
	std::cout << COLOR_RESET;
}

/* OPERATOR OVERLOADS */

FragTrap& FragTrap::operator=( const FragTrap& to_copy ) {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap assignment operator overload called" << std::endl;
	std::cout << COLOR_RESET;
	this->name_ = to_copy.name_;
	this->hit_points_ = to_copy.hit_points_;
	this->energy_points_ = to_copy.energy_points_;
	this->attack_damage_ = to_copy.attack_damage_;
	return (*this);
}

/* PUBLIC METHODS */

void	FragTrap::highFivesGuys( void ) {
	std::cout << COLOR_BRIGHT_MAGENTA;
	std::cout << "FragTrap " << this->name_ << " requests high fives all around!" << std::endl;
	std::cout << COLOR_RESET;
}