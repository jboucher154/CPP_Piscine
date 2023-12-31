/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:53 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/17 10:34:28 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {}

void	HumanB::attack( void ) const {
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with nothing" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &new_weapon) {
	this->_weapon = &new_weapon;
}
