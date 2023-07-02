

# include <iostream>
# include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &initial_Weapon ) 
: _name(name), _weapon(initial_Weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack( void ) const {
	std::string type = this->_weapon.getType();
	std::cout << this->_name << " attacks with their " << type;
}
