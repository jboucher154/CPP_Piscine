/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebouche <jebouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:46:15 by jebouche          #+#    #+#             */
/*   Updated: 2023/07/05 15:46:17 by jebouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon( std::string type ) : _type(type) {}

Weapon::~Weapon( void ) {}

std::string	const &Weapon::getType( void ) {
	std::string	&type_ref = this->_type;

	return (type_ref);
}
void	Weapon::setType(std::string new_type) {
	this->_type = new_type;
}