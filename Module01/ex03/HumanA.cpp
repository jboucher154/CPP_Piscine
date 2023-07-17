/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:45:44 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/17 10:34:33 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &initial_Weapon ) 
: _name(name), _weapon(initial_Weapon) {}

HumanA::~HumanA( void ) {}

void	HumanA::attack( void ) const {
	std::string type = this->_weapon.getType();
	std::cout << this->_name << " attacks with their " << type << std::endl;
}
