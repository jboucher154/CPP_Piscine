/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:53 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:45:54 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
