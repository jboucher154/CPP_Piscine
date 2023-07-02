
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack( void ) const {
	std::string type = this->_weapon->getType();
	std::cout << this->_name << " attacks with their " << type;
}

void	HumanB::setWeapon( Weapon new_weapon) {
	this->_weapon = &new_weapon;
}
